#ifndef NPP_PARSING_FRAMEWORK_H
#define NPP_PARSING_FRAMEWORK_H
#include <string>
#include "../npp/utils/Factory.hpp"

class Element;
class ElementInt;
class ElementString;
class ElementBoolean;
class ElementArray;
class ElementObject;
class ElementDouble;
namespace npp
{
    class NppServer;
    class ContentReader
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

    class ContentParser: public ContentReader
    {
        public:
            ContentParser(const char* id, NppServer* server);
    };

    class ContentCreator: public ContentReader
    {
        public:
            ContentCreator(const char* id, NppServer* server);
    };

    class ElementCreator
    {
        public:
            static ElementCreator creator;
            ElementInt* create(int value) const;
            ElementDouble* create(double value) const;
            ElementString* create(const char* value) const;
            ElementBoolean* create(bool value) const;

            ElementArray* array() const;
            ElementObject* object() const;
            ElementCreator* add(ElementArray* e, Element* value);
            ElementCreator* put(ElementObject* e, const char* key, Element* value);
        private:
            ElementCreator();
            ~ElementCreator();
    };
};
#endif //NPP_PARSING_FRAMEWORK_H
