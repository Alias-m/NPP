#ifndef SIMPLE_API_PACKAGE_H
#define SIMPLE_API_PACKAGE_H
#include "../../includes/npp.hpp"
#include "../http/package.hpp"
#include "../json/package.hpp"
#include "../xml/package.hpp"

namespace simple_api_module
{
    void include(npp::NppServer* server)
    {
		include_module(http_module, server);
		include_module(json_module, server);
		include_module(xml_module, server);
    }
}

#endif // SIMPLE_API_PACKAGE_H
