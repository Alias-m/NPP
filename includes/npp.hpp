#ifndef NppServer_H
#define NppServer_H
#include "../src/npp/socket/SocketServer.hpp"
class NppServer
{
private:
    SocketServer server;
public:
    NppServer(const int port);
    void start();
    ~NppServer();
};

#endif // NppServer_H
