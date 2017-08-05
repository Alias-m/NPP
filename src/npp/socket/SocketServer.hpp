#ifndef HTTP_SERVER_SOCKET_H
#define HTTP_SERVER_SOCKET_H

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

class SocketServer
{
    public:
        SocketServer(int port);
        void run(std::function<bool(SOCKET)> func);
        void run();
        ~SocketServer();

    protected:
        SOCKET mastersocket;
        bool static defaultCallback(SOCKET socket);
        bool wait(std::function<bool(SOCKET)> func);
};
#endif //HTTP_SERVER_SOCKET_H
