#ifndef CONTENTPARSER_H
#define CONTENTPARSER_H
#include "../../streams/Element.hpp"
class ContentParser
{
    public:
        virtual Element* parse(const char* text) const = 0;
};
#endif //CONTENTPARSER_H
