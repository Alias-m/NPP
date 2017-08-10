#include "JsonParser.hpp"
#include "../../streams/Element.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>
JsonParser JsonParser::parser;

template<typename Out>
void split(const std::string &s, char delim, Out result, const int limit) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    int i = 0;
    while (i++ < limit || limit < 0 ? std::getline(ss, item, delim) : std::getline(ss, item)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim, const int limit = -1) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems), limit);
    return elems;
}


JsonParser::JsonParser() {
    elements['{'] = []() -> Element*{return new ElementObject();};
    elements['['] = []() -> Element*{return new ElementArray();};
    elements['\"'] = []() -> Element*{return new ElementString();};
    elements['t'] = []() -> Element*{return new ElementBoolean();};
    elements['f'] = []() -> Element*{return new ElementBoolean();};
}
JsonParser::~JsonParser() {}

Element* JsonParser::parse(std::string& text) const{
    Element* e;
    int i = 0;
    for(i = 0;text[i] == '\t' || text[i] == ' ' || text[i] == ','; i++);
    text = text.substr(i);
    char first = text[0];

    std::map<const char, std::function<Element*()>>::const_iterator it = elements.find(first);
    if(it == elements.end()){
        for(i = 0; text[i] < 0x3A && text[i] > 0x2F ; i++);
        if(text[i] == '.')
            e = new ElementDouble();
        else
            e = new ElementInt();
    }
    else
        e = it->second();
    e->read(text, this);
    return e;
}

void JsonParser::parseContent(std::string& text, ElementDouble* e) const
{
    double total = 0;
    int div = 0;
    int i;
    for(i = 0; (text[i] < 0x3A && text[i] > 0x2F) || text[i] == '.' ; i++)
    {
        if(text[i] == '.')
            div = 1;
        else
        {
            total = total*10 + (text[i] - 0x30);
            div *= 10;
        }
    }
    e->value = total/div;
    text = text.substr(i);

}

void JsonParser::parseContent(std::string& text, ElementInt* e) const
{
    int total = 0;
    int i;
    for(i = 0; text[i] < 0x3A && text[i] > 0x2F ; i++)
        total = total*10 + (text[i] - 0x30);
    e->value = total;
    text = text.substr(i);
}

void JsonParser::parseContent(std::string& text, ElementString* e) const
{
    int cpt = 0;
    std::string value;
    int i;
    for(i = 1; text[i] != '"' || (cpt&1)  ; i++)
    {
        if(text[i] == '\\')
        {
            cpt++;
            if(!(cpt&1))
                value += (text[i]);
        }
        else if(text[i] == '"' && !(cpt&1))
            break;
        else
        {
            value += (text[i]);
            cpt = 0;
        }
    }
    i++;
    e->value = value;
    text = text.substr(i);
}

void JsonParser::parseContent(std::string& text, ElementBoolean* e) const
{
    int i;
    for(i = 0; text[i] < 0x7B && text[i] > 0x60 ; i++);
    e->value = text.substr(0, i) == "true";
    text = text.substr(i);
}

void JsonParser::parseContent(std::string& text, ElementArray* e) const
{
    Element* child = NULL;
    std::string key;
    char end = text[1];
    text = text.substr(1);
    while(end != ']')
    {
        child = parse(text);
        int i;
        for(i = 0;text[i] == '\t' || text[i] == ' ' || text[i] == ','; i++);
        end = text[0];
        e->values.push_back(child);
    }
    text = text.substr(1);
}

void JsonParser::parseContent(std::string& text, ElementObject* e) const
{
    text = text.substr(1);
    int start, cpt, i;
    Element* child = NULL;
    char end = text[1];
    while(end != '}')
    {
        std::string key;
        for(start = -1, cpt = 0, i = 0; ; i++)
        {
            if(start == -1)
            {
                if(text[i] == '"')
                    start = i;
            }
            else
            {
                if(text[i] == '\\')
                {
                    cpt++;
                    if(!(cpt&1))
                        key += (text[i]);
                }
                else if(text[i] == '"' && !(cpt&1))
                    break;
                else
                {
                    key += (text[i]);
                    cpt = 0;
                }
            }
        }
        text = text.substr(i + 2);
        child = parse(text);
        for(i = 0;text[i] == '\t' || text[i] == ' ' || text[i] == ','; i++);
        text = text.substr(i);
        end = text[0];
        e->values.put(key.c_str(), child);
    }
    text = text.substr(1);
}
