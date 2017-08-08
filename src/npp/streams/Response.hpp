#ifndef RESPONSE_H
#define RESPONSE_H
#include <winsock2.h>

class Socket;
class SocketServer;

class Response
{
    friend class SocketServer;
private:
    bool sending;
    Socket* socket;
public:
    Response(bool s = true);
    void setAutoSending(bool sending);
    void send();
    ~Response();
};

#endif // RESPONSE_H
