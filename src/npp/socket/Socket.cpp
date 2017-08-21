#include "Socket.hpp"

Socket::Socket(SOCKET s): socket(s)
{
    if(socket == INVALID_SOCKET)
    {
        #ifdef _WIN32
        std::cout << WSAGetLastError() << std::endl;
        #else
        perror("Invalid socket");
        #endif // _WIN32
        exit(errno);
    }
}

void Socket::_bind(sockaddr_in* sin){
    if(bind (socket, (sockaddr *) sin, sizeof (*sin)) == SOCKET_ERROR)
    {
        #ifdef _WIN32
        std::cout << WSAGetLastError() << std::endl;
        #else
        perror("Bind failed");
        #endif // _WIN32
        exit(errno);
    }
}

void Socket::_listen(){
    if(listen(socket, 32) == SOCKET_ERROR)
    {
        #ifdef _WIN32
        std::cout << WSAGetLastError() << std::endl;
        #else
        perror("Listening failed");
        #endif // _WIN32
        exit(errno);
    }
}

Socket* Socket::_accept(sockaddr_in* csin, accept_size size){
    return new Socket(accept(socket, (sockaddr*)csin, &size));
}

void Socket::read(std::string& buffer){
    FD_ZERO(&fdset);
    tv_timeout.tv_sec = 0;
    tv_timeout.tv_usec = 500;
    FD_SET(socket, &fdset);
    char buff[2];
    do
    {
        if(recv(socket, buff, 1, 0) > 0)
        {
            buffer += buff[0];
            select(socket+1, &fdset, NULL, NULL, &tv_timeout);
        }
    }
    while (FD_ISSET(socket, &fdset));
    FD_CLR(socket, &fdset);
}

void Socket::write(const char* buffer){
    send(socket, buffer, strlen(buffer), 0);
}

void Socket::_close(){
    closesocket(socket);
}

Socket::~Socket(){
    closesocket(socket);
}
