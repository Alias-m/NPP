#include "../../../includes/npp_parser.hpp"
#include "../../../includes/npp.hpp"
npp::ContentParser::ContentParser(const char* id, npp::NppServer* server){
    server->addContentParser(id, this);
}

npp::ContentCreator::ContentCreator(const char* id, npp::NppServer* server){
    server->addContentCreator(id, this);
}
