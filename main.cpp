#include <iostream>
#include "src/includes/npp.hpp"
#include "api/controllers/Videos.hpp"

int main()
{
    NppServer server(3000);
    server.start();
    return 0;
}
