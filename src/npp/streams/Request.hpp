#ifndef REQUEST_H
#define REQUEST_H
#include <string>
#include <map>
#include <winsock2.h>

class SocketServer;
class Router;

class Request
{
    friend class SocketServer;
    friend class Router;
private:
    std::map<std::string, std::string> path;
    std::map<std::string, std::string> query;
    std::map<std::string, std::string> body;
    SOCKET socket;
public:
    const std::string route;
    const std::string method;
    Request(const std::string r, const std::string m);


};

#endif // REQUEST_H
