#include "ContentParser.hpp"


Factory<ContentParser*> ContentParser::contentType;
Factory<ContentCreator*> ContentCreator::contentType;

ContentParser::ContentParser(const char* id){
    ContentParser::contentType.put(id, this);
}

ContentCreator::ContentCreator(const char* id){
    ContentCreator::contentType.put(id, this);
}
