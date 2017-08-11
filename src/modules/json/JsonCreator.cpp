#include "JsonCreator.hpp"
#include "../../npp/streams/Element.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>

JsonCreator JsonCreator::parser;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
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


JsonCreator::JsonCreator():ContentCreator("application/json"){
}

JsonCreator::~JsonCreator() {
}

void JsonCreator::parse(std::string& text, Element** e) const{
    if(*e)
        (*e)->read(text, this);
}

void JsonCreator::parseContent(std::string& text, ElementDouble* e) const
{
    text.append(patch::to_string(e->value));
}

void JsonCreator::parseContent(std::string& text, ElementInt* e) const
{
    text.append(patch::to_string(e->value));
}

void JsonCreator::parseContent(std::string& text, ElementString* e) const
{
    text.append("\"").append(e->value).append("\"");
}

void JsonCreator::parseContent(std::string& text, ElementBoolean* e) const
{
    text.append(patch::to_string(e->value ? "true" : "false"));
}

void JsonCreator::parseContent(std::string& text, ElementArray* e) const
{
    text.append("[");
    for(std::vector<Element*>::const_iterator it = e->values.begin(); it != e->values.end(); it++)
    {
        if(it != e->values.begin())
            text.append(",");
        (*it)->read(text, this);
    }
    text.append("]");
}

void JsonCreator::parseContent(std::string& text, ElementObject* e) const
{
    text.append("{");
    for(std::map<std::string*, Element*>::const_iterator it = e->values.begin(); it != e->values.end(); it++)
    {
        if(it != e->values.begin())
            text.append(",");
        text.append("\"").append(*(it->first)).append("\":");
        it->second->read(text, this);
    }
    text.append("}");
}

