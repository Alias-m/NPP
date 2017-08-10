#ifndef HTTP_SERVER_SOCKET_H
#define HTTP_SERVER_SOCKET_H

#include <thread>

#ifdef WIN32 /* si vous êtes sous Windows */

#include <winsock2.h>

#else /* si vous êtes sous Linux */
/*
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // close
#include <netdb.h> // gethostbyname
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
*/
#endif
#include <winsock2.h>
#include <iostream>
#include <functional>
#include "../parsers/Parser.hpp"
#include "../Router.hpp"
#include "Socket.hpp"
#include <chrono>

class SocketServer
{
    public:
        SocketServer(int port);
        void run(std::function<bool(Socket*)> func);
        void run();
        ~SocketServer();

    protected:
        Socket* master;
        bool static defaultCallback(Socket* socket);
        bool wait(std::function<bool(Socket*)> func);
};
#endif //HTTP_SERVER_SOCKET_H
