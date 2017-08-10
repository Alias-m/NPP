#include "Response.hpp"
#include <iostream>
#include <stdio.h>

HttpResponse::HttpResponse(bool s): Response(s), code(404), status("Not Found"){
    parameters["Date"] = "Thu, 19 Feb 2009 12:27:04 GMT";
    parameters["Server"] = "Apache/2.2.3";
    parameters["Last-Modified"] = "Wed, 18 Jun 2003 16:05:58 GMT";
    parameters["ETag"] = "\"56d-9989200-1132c580\"";
    parameters["Content-Type"] = "text/html";
    parameters["Accept-Ranges"] = "bytes";
    parameters["Connection"] = "close";
}
    /*
        const char *reply =
        "HTTP/1.1 200 OK\n"
        "Date: Thu, 19 Feb 2009 12:27:04 GMT\n"
        "Server: Apache/2.2.3\n"
        "Last-Modified: Wed, 18 Jun 2003 16:05:58 GMT\n"
        "ETag: \"56d-9989200-1132c580\"\n"
        "Content-Type: text/html\n"
        "Content-Length: 15\n"
        "Accept-Ranges: bytes\n"
        "Connection: close\n"
        "\n"
        "TEST RETURN ...";
    */

HttpResponse::~HttpResponse()
{
    this->send();
}

void HttpResponse::setParameter(const char* key, const char* value){
    parameters.insert(std::pair<const char*, const char*>(key, value));
}

std::string HttpResponse::getBody(){
    std::string body("TEST RETURN ...");
    return body.c_str();
}

const char* HttpResponse::createResponse(){
    std::string response;
    std::string body(getBody());

    std::string test;
    test.append(patch::to_string(body.length()));
    setParameter("Content-Length", test.c_str());


    response.append("HTTP/1.1 ");
    response.append(patch::to_string(code));
    response.append(" ");
    response.append(patch::to_string(status));
    response.append("\n");

    for(std::map<const char*, const char*>::const_iterator it = parameters.begin(); it != parameters.end(); it++){
        response.append((it)->first);
        response.append(": ");
        response.append((it)->second);
        response.append("\n");
    }
    response.append("\n");
    response.append(body);
    return response.c_str();
}
