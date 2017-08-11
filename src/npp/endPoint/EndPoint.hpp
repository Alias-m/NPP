#ifndef ENDPOINT_H
#define ENDPOINT_H
#include "../streams/Request.hpp"
#include <string>

class EndPoint
{
public:
    EndPoint(const char* route);
    virtual void operator()(Request* request) = 0;
};

#endif // ENDPOINT_H
