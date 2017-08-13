#ifndef HTTP_ENDPOINT_H
#define HTTP_ENDPOINT_H
#include <iostream>
#include <stdio.h>
#include "../../../includes/npp.hpp"
#include "../../../npp/utils/Factory.hpp"
#include "../streams/Response.hpp"
#include "../streams/Request.hpp"

class HttpEndPoint: public npp::EndPoint
{
    public:
        HttpEndPoint(npp::NppServer* server, const char* route):npp::EndPoint(server, route){}
        virtual void operator()(npp::Request* request);
        virtual void _get(const HttpRequest* request) const;
        virtual void _post(const HttpRequest* request) const;
        inline virtual void _put(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _delete(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _options(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _head(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _connect(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _trace(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _copy(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _lock(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _mkcol(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _move(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _propfind(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _proppatch(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _search(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _unlock(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _report(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _mkactivity(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _checkout(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _merge(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
        inline virtual void _patch(const HttpRequest* request) const { (dynamic_cast<HttpResponse*>(request->response))->code = 404; }
};

typedef void(HttpEndPoint::* httpMethod)(const HttpRequest* request) const;

class HttpLinker{
private:
    Factory<httpMethod> methods;
    HttpLinker();
public:
    static HttpLinker linker;
    httpMethod link(std::string method);
};

#endif //HTTP_ENDPOINT_H
