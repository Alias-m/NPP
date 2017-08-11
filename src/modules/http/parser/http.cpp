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

Http Http::http;

Request* Http::parse(char* method, char* route, std::vector<std::string> request, std::string& body)
{
    Request* r = new HttpRequest(route, method);
    Response* response = new HttpResponse();
    r->setResponse(response);
    for(std::vector<std::string>::const_iterator it = request.begin(); it != request.end(); it++)
    {
        std::vector<std::string> elements = split(*it, ':', 1);
        auto func = httpItem.get(elements[0].c_str());
        if(func)
            func(elements[1].substr(1, elements[1].length() - 2).c_str(), this, r, response);
    }
    r->body = new ElementInt();
    if(parser)
        parser->parse(body, &r->body);
    return r;
}

Http::Http()
{
    Parser::parsers.put("HTTP/1.1", &Http::http);
    httpItem.put("Content-Type", [](const char* key, Http* http, Request* req, Response* res) -> void
                 {
                     res->contentType = key;
                     http->parser = ContentParser::contentType.get(key);
                 });
    //contentType.put("application/json", &JsonParser::parser);
    //contentType.put("application/xml", &XmlParser::parser);
}

Http::~Http()
{
}
