#include "Response.hpp"
#include "../socket/Socket.hpp"

Response::Response(bool s):sending(s){
}

void Response::setAutoSending(bool sending){
    this->sending = sending;
}

void Response::send(){
    if(sending){
        sending = false;
        socket->write(this->createResponse());
    }
}
