#include "../includes/npp.hpp"
#include "../npp/socket/SocketServer.hpp"

npp::NppServer::NppServer(const int port) {
    server = new SocketServer(this, port);
    router = new Router();
    parser = new Parser();
}

npp::NppServer::~NppServer()
{
    delete parser;
    delete router;
    delete server;
    //TODO : delete les listes
}

void npp::NppServer::start(){
    server->run();
}

void npp::NppServer::addProtocol(const char* id, Protocol* protocol){
    protocolParsers.put(id, protocol);
}

npp::Request* npp::NppServer::parseProtocol(const char* request)
{
    const npp::Parser p;
    return p.parse(request, &protocolParsers, this);
}
