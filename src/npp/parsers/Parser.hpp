#ifndef MAINPARSER_H
#define MAINPARSER_H
#include <iostream>
#include <stdio.h>
#include <map>
#include "Protocol.hpp"
#include "../streams/Request.hpp"
#include <cstring>
#include "../utils/Factory.hpp"
#include <sstream>
#include <vector>
#include <iterator>

class Parser
{
    public:
        static Parser parser;
        Request* parse(const char* request) const;
        static Factory<Protocol*> parsers;
    private:
        Parser() {
        }
        ~Parser() {}
};
#endif //MAINPARSER_H
