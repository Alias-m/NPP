#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include "../streams/Request.hpp"

class Protocol
{
    public:
        virtual Request* parse(char* method, char* route, std::vector<std::string> request) const = 0;
};
#endif //PROTOCOL_H
