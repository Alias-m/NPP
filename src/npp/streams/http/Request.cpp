#include "Request.hpp"

HttpRequest::HttpRequest(const std::string r, const std::string m): Request(r, m){
}

void HttpRequest::setResponse(Response* response){
    this->response = response;
}

HttpRequest::~HttpRequest()
{
}
