#include "../../includes/npp.hpp"

npp::Request::Request(const std::string r, const std::string m): route(r), method(m){
}

void npp::Request::setResponse(Response* response){
    this->response = response;
}

npp::Request::~Request()
{
    //response->body = body;
    if(response->body == body)
        delete response;
    else
    {
        delete response;
        delete body;
    }
}
