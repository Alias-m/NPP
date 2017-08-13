#ifndef ROUTER_H
#define ROUTER_H
#include "../includes/npp.hpp"
#include "utils/Factory.hpp"

class Router
{
friend class npp::NppServer;
private:
    Router();
    Factory<npp::EndPoint*> endPoints;
public:
    void route(npp::Request* request) const;
    void addRoute(const char* route, npp::EndPoint* endPoint);

};

#endif // ROUTER_H
