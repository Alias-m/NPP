#include <iostream>
#include "src/includes/npp.hpp"
#include "src/modules/simple_api/package.hpp"
#include "api/controllers/Videos.hpp"

int main()
{
    npp::NppServer server(3000);
    VideoEndPoint endPoint("/videos", &server);

    include_module(simple_api_module, &server);

    server.start();
    return 0;
}
