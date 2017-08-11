#include "Router.hpp"

Router Router::router;

Router::Router(){
}

void Router::route(Request* request) const
{
    EndPoint* endPoint = endPoints.get(request->route.c_str());
    if(endPoint)
        (*endPoints.get(request->route.c_str()))(request);
    else
    {
        //TODO: default response
        std::cout << "End point not found" << std::endl;
    }
}

void Router::addRoute(const char* route, EndPoint* endPoint)
{
    endPoints.put(route, endPoint);
}
