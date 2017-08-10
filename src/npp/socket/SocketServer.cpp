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
    while(this->wait(func));
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
    std::thread connection (func, socket);
    connection.detach();
    return true;
}

bool SocketServer::defaultCallback(Socket* socket)
{
    std::string buffer("");
    Request* request = NULL;
    socket->read(buffer);
    if(buffer.length()){
        auto start = std::chrono::high_resolution_clock::now();
        request = Parser::parser.parse(buffer.c_str());
        request->socket = socket;
        request->response->socket = socket;
        Router::router.route(request);
        delete request;
        delete socket;
        auto end = std::chrono::high_resolution_clock::now();
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Request performed in "<< (microseconds/1000.0) << " milliseconds" <<std::endl;
    }

    return true;
}

SocketServer::~SocketServer()
{
    delete master;
}
