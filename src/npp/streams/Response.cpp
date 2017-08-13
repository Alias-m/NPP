#include "../../includes/npp.hpp"
#include "../socket/Socket.hpp"

npp::Response::Response(bool s):sending(s), body(nullptr){
}

void npp::Response::setAutoSending(bool sending){
    this->sending = sending;
}

void npp::Response::send(npp::NppServer* server){
    if(sending){
        sending = false;
        socket->write(this->createResponse(server));
    }
}
