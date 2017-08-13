#include "http.hpp"

#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>
/*
template<typename Out>
void split(const std::string &s, char delim, Out result, const int limit) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    int i = 0;
    while (i++ < limit || limit < 0 ? std::getline(ss, item, delim) : std::getline(ss, item)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim, const int limit = -1) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems), limit);
    return elems;
}
*/
std::vector<std::string> split(const std::string &s, char delim, const int limit = -1);


npp::Request* Http::parse(char* method, char* route, std::vector<std::string> request, std::string& body, npp::NppServer* server)
{
    npp::Request* r = new HttpRequest(route, method);
    npp::Response* response = new HttpResponse();
    r->setResponse(response);
    for(std::vector<std::string>::const_iterator it = request.begin(); it != request.end(); it++)
    {
        std::vector<std::string> elements = split(*it, ':', 1);
        auto func = httpItem.get(elements[0].c_str());
        if(func)
            func(elements[1].substr(1, elements[1].length() - 2).c_str(), this, r, response, server);
    }
    r->body = new ElementInt();
    if(parser)
        parser->parse(body, &r->body);
    return r;
}

Http::Http(npp::NppServer* server):npp::Protocol(server, "HTTP/1.1")
{
    httpItem.put("Content-Type", [](const char* key, Http* http, npp::Request* req, npp::Response* res, npp::NppServer* server) -> void
                 {
                     res->contentType = key;
                     http->parser = server->getContentParser(key);
                 });
    //contentType.put("application/json", &JsonParser::parser);
    //contentType.put("application/xml", &XmlParser::parser);
}

Http::~Http()
{
}
