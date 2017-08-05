#include "../../../../includes/http.hpp"

HttpLinker HttpLinker::linker;
HttpLinker::HttpLinker(){
    methods.put("get", &HttpEndPoint::_get);
    methods.put("post", &HttpEndPoint::_post);
    methods.put("put", &HttpEndPoint::_put);
    methods.put("delete", &HttpEndPoint::_delete);
    methods.put("options", &HttpEndPoint::_options);
}

HttpLinker::httpMethod HttpLinker::link(std::string method){
    return methods.get(method.c_str());
}

void HttpEndPoint::operator()(const Request* request){
    HttpLinker::linker.link(request->method);//(request);
}
