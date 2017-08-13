#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>
#include <map>
#include "../../includes/npp_parser.hpp"
#include "../utils/Factory.hpp"

class ContentReader;
class Element
{
    public:
        virtual void read(std::string& text, const npp::ContentReader* parser) {};
        virtual ~Element(){
        }
};

class ElementInt: public Element
{
    public:
        int value;
        void read(std::string& text, const npp::ContentReader* parser);
};

class ElementDouble: public Element
{
    public:
        double value;
        void read(std::string& text, const npp::ContentReader* parser);
};

class ElementString: public Element
{
    public:
        std::string value;
        void read(std::string& text, const npp::ContentReader* parser);
};

class ElementBoolean: public Element
{
    public:
        bool value;
        void read(std::string& text, const npp::ContentReader* parser);
};

class ElementArray: public Element
{
    public:
        std::vector<Element*> values;
        void read(std::string& text, const npp::ContentReader* parser);
        ~ElementArray();
};

class ElementObject: public Element
{
    public:
        std::map<std::string*, Element*> values;
        void getItem(const char* key, int* value);
        void getItem(const char* key, bool* value);
        void getItem(const char* key, double* value);
        void getItem(const char* key, ElementObject* value);
        void getItem(const char* key, ElementArray* value);
        void getItem(const char* key, std::string* value);
        void read(std::string& text, const npp::ContentReader* parser);
        ~ElementObject();
};

#endif // ELEMENT_H
