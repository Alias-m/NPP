#ifndef HTTP_SERVER_SOCKET_H
#define HTTP_SERVER_SOCKET_H

#include <thread>

#ifdef _WIN32

#include <winsock2.h>

#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
#endif
#include <iostream>
#include <functional>
#include "../../includes/npp.hpp"
#include "../Router.hpp"
#include "Socket.hpp"
#include <chrono>

class SocketServer
{
    public:
        SocketServer(npp::NppServer*, int port);
        void run(std::function<bool(Socket*, npp::NppServer*)> func);
        void run();
        ~SocketServer();

    protected:
        Socket* master;
        npp::NppServer* server;
        bool static defaultCallback(Socket* socket, npp::NppServer*);
        bool wait(std::function<bool(Socket*, npp::NppServer*)> func);
};
#endif //HTTP_SERVER_SOCKET_H
