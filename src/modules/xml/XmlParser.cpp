#include "XmlParser.hpp"


XmlParser::XmlParser(npp::NppServer* server):ContentParser("application/xml", server) {}
XmlParser::~XmlParser() {}

void XmlParser::parse(std::string& text, Element** e) const{
}

void XmlParser::parseContent(std::string& text, ElementInt* e) const
{

}

void XmlParser::parseContent(std::string& text, ElementDouble* e) const
{

}
void XmlParser::parseContent(std::string& text, ElementString* e) const
{

}

void XmlParser::parseContent(std::string& text, ElementBoolean* e) const
{

}

void XmlParser::parseContent(std::string& text, ElementArray* e) const
{

}

void XmlParser::parseContent(std::string& text, ElementObject* e) const
{

}
