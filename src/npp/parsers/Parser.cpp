#include "Parser.hpp"

Parser Parser::parser;
Factory<Protocol*> Parser::parsers;

Request* Parser::parse(const char* request) const
{
    char method[50];
    char route[1024];
    char protocol[50];
    std::string s = request;
    std::string body("");
    std::stringstream ss(s);
    std::string tok;
    std::vector<std::string> req;
    for(int i = 0;getline(ss, tok, '\n') && tok.length() > 1;i++) {
        if(i)
            req.push_back(tok);
        else
            sscanf(tok.c_str(), "%s %s %s\t\n", method, route, protocol);
    }
    while(getline(ss, tok))
        body.append(tok);

    Protocol* p = Parser::parsers.get(protocol);
    if(p)
        return p->parse(method, route, req, body);
    else//TODO: exception
        std::cout << "Unknown Protocol : " << protocol << std::endl;
    return nullptr;
}
