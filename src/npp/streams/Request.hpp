#ifndef REQUEST_H
#define REQUEST_H
#include <string>
#include <map>
#include <winsock2.h>
#include "Response.hpp"
#include "Element.hpp"

class Socket;
class SocketServer;
class Router;

class Request
{
    friend class SocketServer;
    friend class Router;
private:
    Socket* socket;
public:
    Response* response;
    Element* body;
    const std::string route;
    const std::string method;
    Request(const std::string r, const std::string m);
    virtual ~Request();
    void setResponse(Response* response);


};

#endif // REQUEST_H
