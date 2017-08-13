#include "../includes/http.hpp"

void HttpEndPoint::operator()(npp::Request* request){
    (this->*(HttpLinker::linker.link(request->method)))(dynamic_cast<HttpRequest*>(request));
}

void HttpEndPoint::_get(const HttpRequest* request) const {
    (dynamic_cast<HttpResponse*>(request->response))->code = 404;
}

void HttpEndPoint::_post(const HttpRequest* request) const {
    (dynamic_cast<HttpResponse*>(request->response))->code = 404;
}
//TODO definir les fonctions ici

HttpLinker HttpLinker::linker;
HttpLinker::HttpLinker(){
    methods.put("GET", &HttpEndPoint::_get);
    methods.put("POST", &HttpEndPoint::_post);
    methods.put("PUT", &HttpEndPoint::_put);
    methods.put("DELETE", &HttpEndPoint::_delete);
    methods.put("OPTIONS", &HttpEndPoint::_options);
    methods.put("HEAD", &HttpEndPoint::_head);
    methods.put("CONNECT", &HttpEndPoint::_connect);
    methods.put("TRACE", &HttpEndPoint::_trace);
    methods.put("COPY", &HttpEndPoint::_copy);
    methods.put("LOCK", &HttpEndPoint::_lock);
    methods.put("MKCOL", &HttpEndPoint::_mkcol);
    methods.put("MOVE", &HttpEndPoint::_move);
    methods.put("PROPFIND", &HttpEndPoint::_propfind);
    methods.put("PROPPATCH", &HttpEndPoint::_proppatch);
    methods.put("SEARCH", &HttpEndPoint::_search);
    methods.put("UNLOCK", &HttpEndPoint::_unlock);
    methods.put("REPORT", &HttpEndPoint::_report);
    methods.put("MKACTIVITY", &HttpEndPoint::_mkactivity);
    methods.put("CHECKOUT", &HttpEndPoint::_checkout);
    methods.put("MERGE", &HttpEndPoint::_merge);
    methods.put("PATCH", &HttpEndPoint::_patch);
}

httpMethod HttpLinker::link(std::string method){
    return methods.get(method.c_str());
}
