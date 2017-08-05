#include "EndPoint.hpp"
#include "../Router.hpp"

EndPoint::EndPoint(std::string route){
    Router::router.addRoute(route.c_str(), this);
}
