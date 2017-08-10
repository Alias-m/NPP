#ifndef RESPONSE_H
#define RESPONSE_H
#include "Element.hpp"

class Socket;
class SocketServer;

class Response
{
    friend class SocketServer;
    friend class Http;
private:
    bool sending;
    Socket* socket;

public:
    std::string contentType;
    Element* body;
    Response(bool s = true);
    virtual const char* createResponse() = 0;
    void setAutoSending(bool sending);
    void send();
    virtual ~Response() { delete body;};
};

#endif // RESPONSE_H
