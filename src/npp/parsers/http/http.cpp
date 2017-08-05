#include "http.hpp"

Http Http::http;

Request* Http::parse(char* method, char* route, std::vector<std::string> request) const
{
    std::cout << " <"<< method << "> - <"<< route << "> - "<< std::endl;
    Request* r = new Request(route, method);
    return r;
}

Http::Http()
{
}

Http::~Http()
{
}
