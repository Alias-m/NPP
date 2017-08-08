#include "SocketServer.hpp"

SocketServer::SocketServer(int port): master(NULL)
{
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    master = new Socket(socket(AF_INET , SOCK_STREAM , 0));

    sockaddr_in sin = { 0 };
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);

    master->_bind(&sin);
    master->_listen();

    std::cout << "Server listening on port " << port << std::endl;
}

void SocketServer::run(std::function<bool(Socket*)> func)
{
    while(this->wait(func))
    {}
}

void SocketServer::run()
{
    this->run(SocketServer::defaultCallback);
}

bool SocketServer::wait(std::function<bool(Socket*)> func)
{
    sockaddr_in csin = { 0 };
    int sinsize = sizeof csin;
    Socket* socket = master->_accept(&csin, sinsize);
    //TODO : fork

    {
        auto start = std::chrono::high_resolution_clock::now();
        func(socket);
        delete socket;
        auto elapsed = std::chrono::high_resolution_clock::now() - start;

        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout << "Request performed in "<< (microseconds/1000.0) << " milliseconds" <<std::endl;
    }


    return true;
}

bool SocketServer::defaultCallback(Socket* socket)
{
    std::string buffer("");
    Request* request = NULL;
    socket->read(buffer);
    std::cout << buffer << std::endl;

    Response* response = new Response();
    request = Parser::parser.parse(buffer.c_str());
    request->socket = socket;
    response->socket = socket;
    request->setResponse(response);
    Router::router.route(request);

    delete request;
    return true;
}

SocketServer::~SocketServer()
{
    delete master;
}
