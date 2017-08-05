#ifndef HTTP_ENDPOINT_H
#define HTTP_ENDPOINT_H
#include <iostream>
#include <stdio.h>
#include "../src/npp/endPoint/EndPoint.hpp"
#include "../src/npp/parsers/Factory.hpp"

class HttpEndPoint: public EndPoint
{
    public:
        virtual void operator()(const Request* request);
        inline virtual void _get(const Request* request) const {}
        inline virtual void _post(const Request* request) const {}
        inline virtual void _put(const Request* request) const {}
        inline virtual void _delete(const Request* request) const {}
        inline virtual void _options(const Request* request) const{}
        //Todo: add function
};

class HttpLinker{
    typedef void(HttpEndPoint::* httpMethod)(const Request* request) const;
private:
    Factory<httpMethod> methods;
    HttpLinker();
public:
    static HttpLinker linker;
    httpMethod link(std::string method);
};
#endif //HTTP_ENDPOINT_H
