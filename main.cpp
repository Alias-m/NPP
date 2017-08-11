#include <iostream>
#include "src/includes/npp.hpp"
#include "api/controllers/Videos.hpp"
//test webook 1
int main()
{
    NppServer server(3000);
    server.start();
    return 0;
}
