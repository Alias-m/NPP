#ifndef HTTP_PACKAGE_H
#define HTTP_PACKAGE_H
#include "parser/http.hpp"

namespace http_module
{
    void include(npp::NppServer* server)
    {
        new Http(server);
    }
}

#endif // HTTP_PACKAGE_H
