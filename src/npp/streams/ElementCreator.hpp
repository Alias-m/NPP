#ifndef ELEMENTCREATOR_H
#define ELEMENTCREATOR_H
#include <string>

class Element;
class ElementInt;
class ElementDouble;
class ElementString;
class ElementBoolean;
class ElementArray;
class ElementObject;

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
#endif //ELEMENTCREATOR_H
