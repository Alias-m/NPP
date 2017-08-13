#include "Socket.hpp"

int recv_to(int fd, char *buffer, int len, int flags, int to) {

   fd_set readset;
   int result = -1;
   struct timeval tv;
   FD_ZERO(&readset);
   FD_SET(fd, &readset);
   tv.tv_usec = to;
   result = select(fd+1, &readset, NULL, NULL, &tv);

   // Check status
   if (result < 0)
      return -1;
   else if (result > 0 && FD_ISSET(fd, &readset)) {
      result = recv(fd, buffer, len, flags);
      return result;
   }
   return -2;
}


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
        if(recv_to(socket, buff, 1, 0, 1) > 0)
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
