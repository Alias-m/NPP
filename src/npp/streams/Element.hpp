#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>
#include <map>
#include "../parsers/content-type/ContentParser.hpp"
#include "../utils/Factory.hpp"

class Element
{
    public:
        virtual void read(std::string& text, const ContentReader* parser) {};
        virtual ~Element(){
        }
};

class ElementInt: public Element
{
    public:
        int value;
        inline void read(std::string& text, const ContentReader* parser){ parser->parseContent(text, this); }
};

class ElementDouble: public Element
{
    public:
        double value;
        inline void read(std::string& text, const ContentReader* parser){ parser->parseContent(text, this); }
};

class ElementString: public Element
{
    public:
        std::string value;
        inline void read(std::string& text, const ContentReader* parser){ parser->parseContent(text, this); }
};

class ElementBoolean: public Element
{
    public:
        bool value;
        inline void read(std::string& text, const ContentReader* parser){ parser->parseContent(text, this); }
};

class ElementArray: public Element
{
    public:
        std::vector<Element*> values;
        inline void read(std::string& text, const ContentReader* parser){ parser->parseContent(text, this); }
        ~ElementArray(){
            for(std::vector<Element*>::const_iterator it = values.begin(); it != values.end(); it++)
                delete *it;
        }
};

class ElementObject: public Element
{
    public:
        std::map<std::string*, Element*> values;
        void getItem(const char* key, int* value) {
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                if(!std::strcmp(it->first->c_str(), key)){
                    *value = dynamic_cast<ElementInt*>(it->second)->value;
                    return;
                }
            }
        }
        void getItem(const char* key, bool* value) {
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                if(!std::strcmp(it->first->c_str(), key)){
                    *value = dynamic_cast<ElementBoolean*>(it->second)->value;
                    return;
                }
            }
        }
        void getItem(const char* key, double* value) {
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                if(!std::strcmp(it->first->c_str(), key)){
                    *value = dynamic_cast<ElementDouble*>(it->second)->value;
                    return;
                }
            }
        }
        void getItem(const char* key, ElementObject* value) {
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                if(!std::strcmp(it->first->c_str(), key)){
                    value = dynamic_cast<ElementObject*>(it->second);
                    return;
                }
            }
        }
        void getItem(const char* key, ElementArray* value) {
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                if(!std::strcmp(it->first->c_str(), key)){
                    value = dynamic_cast<ElementArray*>(it->second);
                    return;
                }
            }
        }
        void getItem(const char* key, std::string* value) {
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                if(!std::strcmp(it->first->c_str(), key)){
                    *value = dynamic_cast<ElementString*>(it->second)->value;
                    return;
                }
            }
        }
        inline void read(std::string& text, const ContentReader* parser){ parser->parseContent(text, this); }
        ~ElementObject(){
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                delete it->first;
                delete it->second;
            }
        }
};

#endif // ELEMENT_H
