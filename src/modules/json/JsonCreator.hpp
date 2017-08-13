#ifndef JSONCREATOR_H
#define JSONCREATOR_H
#include "../../includes/npp_parser.hpp"
#include <functional>
#include <map>

class JsonCreator: public npp::ContentCreator
{
    public:
        void parse(std::string& text, Element** e) const;
        void parseContent(std::string& text, ElementInt* e) const;
        void parseContent(std::string& text, ElementString* e) const;
        void parseContent(std::string& text, ElementBoolean* e) const;
        void parseContent(std::string& text, ElementArray* e) const;
        void parseContent(std::string& text, ElementObject* e) const;
        void parseContent(std::string& text, ElementDouble* e) const;
        JsonCreator(npp::NppServer* server);
        ~JsonCreator();
    private:
};
#endif //JSONCREATOR_H
