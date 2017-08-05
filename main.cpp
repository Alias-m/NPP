#include <iostream>
#include "includes/npp.hpp"

int main()
{
    NppServer server(3000);
    server.start();
    return 0;
}
