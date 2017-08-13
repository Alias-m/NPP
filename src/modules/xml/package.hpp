#ifndef XML_PACKAGE_H
#define XML_PACKAGE_H
#include "XmlParser.hpp"

namespace xml_module
{
    void include(npp::NppServer* server)
    {
        new XmlParser(server);
    }
}

#endif // XML_PACKAGE_H
