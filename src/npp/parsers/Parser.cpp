#include "Parser.hpp"

Parser Parser::parser;

Request* Parser::parse(const char* request) const
{
    char method[50];
    char route[1024];
    char protocol[50];
    std::string s = request;
    std::stringstream ss(s);
    std::string tok;
    std::vector<std::string> req;
    for(int i = 0;getline(ss, tok, '\n');i++) {
        if(i)
            req.push_back(tok);
        else
            sscanf(tok.c_str(), "%s %s %s\t\n", method, route, protocol);
    }

    Protocol* p = parsers.get(protocol);
    if(p)
        return p->parse(method, route, req);
    else//TODO: exception
        std::cout << "Unknown Protocol : " << protocol << std::endl;
    return NULL;
}
