#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "../../npp/parsers/content-type/ContentParser.hpp"
#include <functional>
#include <map>
class ContentParser;
class JsonParser: public ContentParser
{
    public:
        static JsonParser parser;
        void parse(std::string& text, Element** e) const;
        void parseContent(std::string& text, ElementInt* e) const;
        void parseContent(std::string& text, ElementString* e) const;
        void parseContent(std::string& text, ElementBoolean* e) const;
        void parseContent(std::string& text, ElementArray* e) const;
        void parseContent(std::string& text, ElementObject* e) const;
        void parseContent(std::string& text, ElementDouble* e) const;
    private:
        std::map<const char, std::function<Element*()>> elements;
        JsonParser();
        ~JsonParser();
};
#endif //JSONPARSER_H
