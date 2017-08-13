#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H
#include "../../../includes/npp.hpp"

class HttpRequest: public npp::Request
{
    friend class Router;
    private:
    public:
        const std::string route;
        const std::string method;
        HttpRequest(const std::string r, const std::string m);
        ~HttpRequest();
        void setResponse(npp::Response* response);
};

#endif // HTTP_REQUEST_H
