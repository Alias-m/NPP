#include "http.hpp"

Http Http::http;

Request* Http::parse(char* method, char* route, std::vector<std::string> request) const
{
    Request* r = new HttpRequest(route, method);
    Response* response = new HttpResponse();
    r->setResponse(response);
    return r;
}

Http::Http()
{
}

Http::~Http()
{
}
