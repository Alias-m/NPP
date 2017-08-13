#include "Element.hpp"

void ElementInt::read(std::string& text, const npp::ContentReader* parser)
{
    parser->parseContent(text, this);
}

void ElementDouble::read(std::string& text, const npp::ContentReader* parser)
{
    parser->parseContent(text, this);
}

void ElementString::read(std::string& text, const npp::ContentReader* parser)
{
    parser->parseContent(text, this);
}

void ElementBoolean::read(std::string& text, const npp::ContentReader* parser)
{
    parser->parseContent(text, this);
}

void ElementArray::read(std::string& text, const npp::ContentReader* parser)
{
    parser->parseContent(text, this);
}

ElementArray::~ElementArray(){
    for(std::vector<Element*>::const_iterator it = values.begin(); it != values.end(); it++)
        delete *it;
}

void ElementObject::getItem(const char* key, int* value) {
    for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        if(!std::strcmp(it->first->c_str(), key)){
            *value = dynamic_cast<ElementInt*>(it->second)->value;
            return;
        }
    }
}
void ElementObject::getItem(const char* key, bool* value) {
    for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        if(!std::strcmp(it->first->c_str(), key)){
            *value = dynamic_cast<ElementBoolean*>(it->second)->value;
            return;
        }
    }
}
void ElementObject::getItem(const char* key, double* value) {
    for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        if(!std::strcmp(it->first->c_str(), key)){
            *value = dynamic_cast<ElementDouble*>(it->second)->value;
            return;
        }
    }
}
void ElementObject::getItem(const char* key, ElementObject* value) {
    for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        if(!std::strcmp(it->first->c_str(), key)){
            value = dynamic_cast<ElementObject*>(it->second);
            return;
        }
    }
}
void ElementObject::getItem(const char* key, ElementArray* value) {
    for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        if(!std::strcmp(it->first->c_str(), key)){
            value = dynamic_cast<ElementArray*>(it->second);
            return;
        }
    }
}
void ElementObject::getItem(const char* key, std::string* value) {
    for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        if(!std::strcmp(it->first->c_str(), key)){
            *value = dynamic_cast<ElementString*>(it->second)->value;
            return;
        }
    }
}

void ElementObject::read(std::string& text, const npp::ContentReader* parser)
{
    parser->parseContent(text, this);
}

ElementObject::~ElementObject(){
    for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        delete it->first;
        delete it->second;
    }
}
