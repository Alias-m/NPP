#include "../../includes/npp.hpp"
#include "../Router.hpp"
npp::EndPoint::EndPoint(npp::NppServer* server, const char* route){
    std::cout << "New route : " << route << std::endl;
    server->router->addRoute(route, this);
}
