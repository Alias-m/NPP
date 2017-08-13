#include "Request.hpp"

HttpRequest::HttpRequest(const std::string r, const std::string m): npp::Request(r, m){
}

HttpRequest::~HttpRequest()
{
}
