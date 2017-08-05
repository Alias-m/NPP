#include "../../includes/npp.hpp"

NppServer::NppServer(const int port): server(port){
}

NppServer::~NppServer()
{
}

void NppServer::start(){
    server.run();
}

