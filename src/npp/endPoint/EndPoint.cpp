#include "EndPoint.hpp"
#include "../Router.hpp"

EndPoint::EndPoint(const char* route){
    std::cout << "New route : " << route << std::endl;
    Router::router.addRoute(route, this);
}
