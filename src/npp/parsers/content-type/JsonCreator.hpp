#ifndef JSONCREATOR_H
#define JSONCREATOR_H
#include "ContentParser.hpp"
#include <functional>
#include <map>

class JsonCreator: public ContentParser
{
    public:
        static JsonCreator parser;
        void parse(std::string& text, Element** e) const;
        void parseContent(std::string& text, ElementInt* e) const;
        void parseContent(std::string& text, ElementString* e) const;
        void parseContent(std::string& text, ElementBoolean* e) const;
        void parseContent(std::string& text, ElementArray* e) const;
        void parseContent(std::string& text, ElementObject* e) const;
        void parseContent(std::string& text, ElementDouble* e) const;
    private:
        JsonCreator();
        ~JsonCreator();
};
#endif //JSONCREATOR_H
