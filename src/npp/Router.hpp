#ifndef ROUTER_H
#define ROUTER_H
#include "streams/Request.hpp"
#include "parsers/Factory.hpp"
#include "endPoint/EndPoint.hpp"

class Router
{
private:
    Router();
    Factory<EndPoint*> endPoints;
public:
    static Router router;
    void route(const Request* request) const;
    void addRoute(const char* route, EndPoint* endPoint);

};

#endif // ROUTER_H
