#include "Videos.hpp"

void VideoEndPoint::_post(const HttpRequest* request) const
{
    Video v("Name", 42, 1, 10, "User");
    v.generate(request->body);
    request->response->setBody(v);
}
