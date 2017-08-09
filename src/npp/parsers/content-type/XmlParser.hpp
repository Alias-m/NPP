#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "ContentParser.hpp"

class XmlParser: public ContentParser
{
    public:
        static XmlParser parser;
        Element* parse(const char* text) const;

    private:
        XmlParser();
        ~XmlParser();
};
#endif //XMLPARSER_H
