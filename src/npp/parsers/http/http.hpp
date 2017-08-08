#ifndef HTTP_PROTOCOL_H
#define HTTP_PROTOCOL_H
#include <iostream>
#include <stdio.h>
#include "../Protocol.hpp"
#include <vector>
#include "../../streams/http/Request.hpp"
#include "../../streams/http/Response.hpp"

class Http: public Protocol
{
    private:
        Http();
    public:
        static Http http;
        Request* parse(char* method, char* route, std::vector<std::string> request) const;
        ~Http();
};
#endif //HTTP_PROTOCOL_H
