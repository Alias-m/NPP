#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H
#include <map>
#include <string>
#include "../Response.hpp"
#include <sstream>

class Socket;
class SocketServer;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

class HttpResponse: public Response
{
    friend class SocketServer;
private:
    bool sending;
    Socket* socket;
    //http stuff
    std::map<const char*, const char*> parameters;
    int code;
    std::string status;//TODO : given by code

public:
    HttpResponse(bool s = true);
    const char* createResponse();
    void setParameter(const char* key, const char* value);
    std::string getBody();
    ~HttpResponse();
};

#endif // HTTP_RESPONSE_H
