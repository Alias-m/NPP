#ifndef MAINPARSER_H
#define MAINPARSER_H
#include <iostream>
#include <stdio.h>
#include <map>
#include "Protocol.hpp"
#include "../streams/Request.hpp"
#include "http/http.hpp"
#include <cstring>
#include "Factory.hpp"
#include <sstream>
#include <vector>
#include <iterator>

class Parser
{
    public:
        static Parser parser;
        Request* parse(const char* request) const;
    private:
        Factory<Protocol*> parsers;
        Parser() {
            parsers.put("HTTP/1.1", &Http::http);
        }
        ~Parser() {}
};
#endif //MAINPARSER_H
