#ifndef HTTP_PROTOCOL_H
#define HTTP_PROTOCOL_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include "../../../npp/parsers/Parser.hpp"
#include "../../../npp/parsers/Protocol.hpp"
#include "../streams/Request.hpp"
#include "../streams/Response.hpp"
#include "../../../npp/utils/Factory.hpp"


class Http: public Protocol
{
    friend class HttpResponse;
    friend class HttpRequest;
    private:
        Http();
        Factory<void(*)(const char* key, Http* http, Request* req, Response* res)> httpItem;
        ContentParser* parser;
    public:
        static Http http;
        Request* parse(char* method, char* route, std::vector<std::string> request, std::string& body);
        ~Http();
};
#endif //HTTP_PROTOCOL_H
