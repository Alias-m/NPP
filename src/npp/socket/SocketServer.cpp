#include "SocketServer.hpp"

SocketServer::SocketServer(int port)
{
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    mastersocket = socket(AF_INET , SOCK_STREAM , 0);
    if(mastersocket == INVALID_SOCKET)
    {
        std::cout << WSAGetLastError() << std::endl;
        exit(errno);
    }

    sockaddr_in sin = { 0 };

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);

    if(bind (mastersocket, (sockaddr *) &sin, sizeof sin) == SOCKET_ERROR)
    {
        std::cout << WSAGetLastError() << std::endl;
        exit(errno);
    }

    if(listen(mastersocket, 32) == SOCKET_ERROR)
    {
        std::cout << WSAGetLastError() << std::endl;
        exit(errno);
    }
    std::cout << "Server listening on port " << port << std::endl;
}

void SocketServer::run(std::function<bool(SOCKET)> func)
{
    while(this->wait(func))
    {}
}

void SocketServer::run()
{
    this->run(SocketServer::defaultCallback);
}

bool SocketServer::wait(std::function<bool(SOCKET)> func)
{
    sockaddr_in csin = { 0 };
    int sinsize = sizeof csin;
    SOCKET csock_tmp = accept(mastersocket, (sockaddr *)&csin, &sinsize);

    if(csock_tmp != INVALID_SOCKET)
    {
        //TODO: fork
        // traitement
        func(csock_tmp);

        closesocket(csock_tmp);
    }
    else
    {
        //Exception
        std::cout << "Unable to connect to client" << std::endl;
    }
    return true;
}

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

bool SocketServer::defaultCallback(SOCKET socket)
{

    std::string buffer("");
    char buff[10000];
    Request* request = NULL;
    fd_set fdset;
    FD_ZERO(&fdset);
    struct timeval tv_timeout;
    tv_timeout.tv_sec = 0;
    tv_timeout.tv_usec = 500;
    FD_SET(socket, &fdset);
    do
    {
        if(recv_to(socket, buff, 1, 0, 1) > 0)
        {
            buffer += buff;
            select(socket+1, &fdset, NULL, NULL, &tv_timeout);
        }
    }
    while (FD_ISSET(socket, &fdset));

    FD_CLR(socket, &fdset);

    std::cout << buffer << std::endl;
    request = Parser::parser.parse(buffer.c_str());
    request->socket = socket;
    Router::router.route(request);
    delete request;
    return true;
}

SocketServer::~SocketServer()
{
    closesocket(mastersocket);
}
