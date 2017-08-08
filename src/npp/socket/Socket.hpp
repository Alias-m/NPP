#ifndef SOCKET_H
#define SOCKET_H
#include <winsock2.h>

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

class Socket
{
    public:
        Socket(SOCKET s);
        void _bind(sockaddr_in* sin);
        void _listen();
        void _close();
        int _recv(char* buff, int len, int flags, int to);
        void read(std::string& buffer);
        void write(const char* buffer);
        Socket* _accept(sockaddr_in* csin, int size);
        ~Socket();

    protected:
        SOCKET socket;
        fd_set fdset;
        struct timeval tv_timeout;
};
#endif //SOCKET_H
