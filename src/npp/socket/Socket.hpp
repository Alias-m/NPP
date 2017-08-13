#ifndef SOCKET_H
#define SOCKET_H

#ifdef _WIN32

#include <winsock2.h>
#define accept_size int
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
#define accept_size unsigned int

#endif
#include <iostream>
#include <functional>
#include "../../includes/npp.hpp"
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
        Socket* _accept(sockaddr_in* csin, accept_size size);
        ~Socket();

    protected:
        SOCKET socket;
        fd_set fdset;
        struct timeval tv_timeout;
};
#endif //SOCKET_H
