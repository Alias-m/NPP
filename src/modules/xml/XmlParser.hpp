#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "../../includes/npp_parser.hpp"

class XmlParser: public npp::ContentParser
{
    public:
        void parse(std::string& text, Element** e) const;
        void parseContent(std::string& text, ElementInt* e) const;
        void parseContent(std::string& text, ElementString* e) const;
        void parseContent(std::string& text, ElementBoolean* e) const;
        void parseContent(std::string& text, ElementArray* e) const;
        void parseContent(std::string& text, ElementObject* e) const;
        void parseContent(std::string& text, ElementDouble* e) const;
        XmlParser(npp::NppServer* server);
        ~XmlParser();

    private:
};
#endif //XMLPARSER_H
