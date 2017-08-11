#ifndef RESPONSE_H
#define RESPONSE_H
#include "Element.hpp"
#include "../../includes/object.hpp"

class Socket;
class SocketServer;

class Response
{
    friend class SocketServer;
    friend class Request;
private:
    bool sending;
    Socket* socket;
protected:
    Element* body;
public:
    std::string contentType;
    Response(bool s = true);
    virtual const char* createResponse() = 0;
    void setAutoSending(bool sending);
    void setBody(Object& o) {body = o.toElement();}
    void setBody(Element* e) {body = e;}
    void send();
    virtual ~Response() { delete body;};
};

#endif // RESPONSE_H
