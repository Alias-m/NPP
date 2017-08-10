#ifndef HTTP_PROTOCOL_H
#define HTTP_PROTOCOL_H
#include <iostream>
#include <stdio.h>
#include "../Protocol.hpp"
#include <vector>
#include "../../streams/http/Request.hpp"
#include "../../streams/http/Response.hpp"
#include "../content-type/ContentParser.hpp"
#include "../Factory.hpp"
#include "../content-type/JsonParser.hpp"
#include "../content-type/XmlParser.hpp"

//class JsonParser;
//class XmlParser;
class Http: public Protocol
{
    friend class HttpResponse;
    friend class HttpRequest;
    private:
        Http();
        Factory<void(*)(const char* key, Http* http, Request* req, Response* res)> httpItem;
        Factory<ContentParser*> contentType;
        ContentParser* parser;
    public:
        static Http http;
        Request* parse(char* method, char* route, std::vector<std::string> request, std::string& body);
        ~Http();
};
#endif //HTTP_PROTOCOL_H
