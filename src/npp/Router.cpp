#include "Router.hpp"

Router::Router(){
}

void Router::route(npp::Request* request) const
{
    npp::EndPoint* endPoint = endPoints.get(request->route.c_str());
    if(endPoint)
        (*endPoints.get(request->route.c_str()))(request);
    else
    {
        //TODO: default response
        std::cout << "End point not found" << std::endl;
    }
}

void Router::addRoute(const char* route, npp::EndPoint* endPoint)
{
    endPoints.put(route, endPoint);
}
