#ifndef RESPONSE_H
#define RESPONSE_H

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
    Response(bool s = true);
    virtual const char* createResponse() = 0;
    void setAutoSending(bool sending);
    void send();
    virtual ~Response() {};
};

#endif // RESPONSE_H
