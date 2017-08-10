#ifndef CONTENTPARSER_H
#define CONTENTPARSER_H
#include <string>

class Element;
class ElementInt;
class ElementDouble;
class ElementString;
class ElementBoolean;
class ElementArray;
class ElementObject;

class ContentParser
{
    public:
        virtual void parse(std::string& text, Element** e) const = 0;
        virtual void parseContent(std::string& text, ElementInt* e) const = 0;
        virtual void parseContent(std::string& text, ElementString* e) const = 0;
        virtual void parseContent(std::string& text, ElementBoolean* e) const = 0;
        virtual void parseContent(std::string& text, ElementArray* e) const = 0;
        virtual void parseContent(std::string& text, ElementObject* e) const = 0;
        virtual void parseContent(std::string& text, ElementDouble* e) const = 0;
};
#endif //CONTENTPARSER_H
