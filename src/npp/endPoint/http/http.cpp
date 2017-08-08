#include "../../../../includes/http.hpp"

HttpLinker HttpLinker::linker;
HttpLinker::HttpLinker(){
    methods.put("GET", &HttpEndPoint::_get);
    methods.put("POST", &HttpEndPoint::_post);
    methods.put("PUT", &HttpEndPoint::_put);
    methods.put("DELETE", &HttpEndPoint::_delete);
    methods.put("OPTIONS", &HttpEndPoint::_options);
}

httpMethod HttpLinker::link(std::string method){
    return methods.get(method.c_str());
}

void HttpEndPoint::operator()(const Request* request){
    (this->*(HttpLinker::linker.link(request->method)))(request);
}
