#ifndef NPP_OBJECT_H
#define NPP_OBJECT_H
#include "../npp/streams/ElementCreator.hpp"
#include "../npp/streams/Element.hpp"

class Object
{
    public:
        virtual Element* toElement() const = 0;
        void generate(Element* e){fromElement(dynamic_cast<ElementObject*>(e));};
        virtual void fromElement(ElementObject*) = 0;
};
#endif //NPP_OBJECT_H
