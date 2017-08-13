#ifndef NPP_FRAMEWORK_H
#define NPP_FRAMEWORK_H
#define include_module(__module__, __server__) __module__::include(__server__)
#include <sstream>
#include <cstdio>
#include "../npp/streams/Element.hpp"

class SocketServer;
class Socket;
class Router;
namespace npp
{
    class Response;
    class Request;
    class EndPoint;
    class Protocol;
    class Parser;
    class ContentParser;
    class ContentCreator;
    class NppServer
    {
        friend class EndPoint;
        friend class Protocol;
        private:
            Factory<npp::Protocol*> protocolParsers;
            SocketServer* server;
            Parser* parser;
            void addProtocol(const char*, Protocol*);
            Factory<ContentParser*> contentParser;
            Factory<ContentCreator*> contentCreator;
        public:
            ContentParser* getContentParser(const char* key){
                return contentParser.get(key);
            }
            ContentCreator* getContentCreator(const char* key){
                return contentCreator.get(key);
            }
            void addContentParser(const char* key, ContentParser* parser){
                contentParser.put(key, parser);
            }
            void addContentCreator(const char* key, ContentCreator* parser){
                contentCreator.put(key, parser);
            }
            Request* parseProtocol(const char*);
            Router* router;
            NppServer(const int port);
            void start();
            ~NppServer();
    };

    class Object
    {
        public:
            virtual Element* toElement() const = 0;
            inline void generate(Element* e){fromElement(dynamic_cast<ElementObject*>(e));};
            virtual void fromElement(ElementObject*) = 0;
    };

    class Request
    {
        private:
        public:
            Socket* socket;
            npp::Response* response;
            Element* body;
            const std::string route;
            const std::string method;
            Request(const std::string r, const std::string m);
            virtual ~Request();
            void setResponse(Response* response);
    };

    class Response
    {
        friend class SocketServer;
        friend class Request;
        private:
            bool sending;
        protected:
            Element* body;
        public:
            Socket* socket;
            std::string contentType;
            Response(bool s = true);
            virtual const char* createResponse(npp::NppServer* server) = 0;
            void setAutoSending(bool sending);
            void setBody(npp::Object& o) {body = o.toElement();}
            void setBody(Element* e) {body = e;}
            void send(npp::NppServer* server);
            virtual ~Response() { delete body;};
    };

    class Protocol
    {
        public:
            Protocol(NppServer* server, const char* id){
                server->addProtocol(id, this);
            }
            virtual Request* parse(char* method, char* route, std::vector<std::string> request, std::string& body, NppServer*) = 0;
    };

    class Parser
    {
        public:
            Request* parse(const char* request, Factory<Protocol*>* parsers, NppServer* server) const;
            Parser() {
            }
            ~Parser() {}
        private:
    };

    class EndPoint
    {
        public:
            EndPoint(npp::NppServer* server, const char* route);
            virtual void operator()(Request* request) = 0;
    };

};
#endif // NPP_FRAMEWORK_H
