#ifndef HTTP_PROTOCOL_H
#define HTTP_PROTOCOL_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include "../../../includes/npp.hpp"
#include "../../../includes/npp_parser.hpp"
#include "../streams/Response.hpp"
#include "../streams/Request.hpp"
#include "../../../npp/utils/Factory.hpp"


class Http: public npp::Protocol
{
    friend class HttpResponse;
    friend class HttpRequest;
    private:
        Factory<void(*)(const char* key, Http* http, npp::Request* req, npp::Response* res, npp::NppServer*)> httpItem;
        npp::ContentParser* parser;
    public:
        Http(npp::NppServer*);
        npp::Request* parse(char* method, char* route, std::vector<std::string> request, std::string& body, npp::NppServer*);
        ~Http();
};
#endif //HTTP_PROTOCOL_H
