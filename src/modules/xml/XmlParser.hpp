#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "../../npp/parsers/content-type/ContentParser.hpp"

class XmlParser: public ContentParser
{
    public:
        static XmlParser parser;
        void parse(std::string& text, Element** e) const;
        void parseContent(std::string& text, ElementInt* e) const;
        void parseContent(std::string& text, ElementString* e) const;
        void parseContent(std::string& text, ElementBoolean* e) const;
        void parseContent(std::string& text, ElementArray* e) const;
        void parseContent(std::string& text, ElementObject* e) const;
        void parseContent(std::string& text, ElementDouble* e) const;

    private:
        XmlParser();
        ~XmlParser();
};
#endif //XMLPARSER_H
