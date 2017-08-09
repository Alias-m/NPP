#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "ContentParser.hpp"

class JsonParser: public ContentParser
{
    public:
        static JsonParser parser;
        Element* parse(const char* text) const;

    private:
        JsonParser();
        ~JsonParser();
};
#endif //JSONPARSER_H
