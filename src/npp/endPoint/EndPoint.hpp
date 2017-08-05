#ifndef ENDPOINT_H
#define ENDPOINT_H
#include "../streams/Request.hpp"
#include <string>
class Router;

class EndPoint
{
public:
    EndPoint(std::string route);
    virtual void operator()(const Request* request) = 0;

};

#endif // ENDPOINT_H
