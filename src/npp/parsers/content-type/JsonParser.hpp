#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "ContentParser.hpp"
#include <functional>
#include <map>

class JsonParser: public ContentParser
{
    public:
        static JsonParser parser;
        Element* parse(std::string& text) const;
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
