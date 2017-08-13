#ifndef JSON_PACKAGE_H
#define JSON_PACKAGE_H
#include "JsonCreator.hpp"
#include "JsonParser.hpp"

namespace json_module
{
    void include(npp::NppServer* server)
    {
        new JsonCreator(server);
        new JsonParser(server);
    }
}

#endif // JSON_PACKAGE_H
