#include "Request.hpp"

Request::Request(const std::string r, const std::string m): route(r), method(m){
}

void Request::setResponse(Response* response){
    this->response = response;
}

Request::~Request()
{
    delete response;
}
