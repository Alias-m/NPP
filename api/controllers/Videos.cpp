#include "Videos.hpp"

VideoEndPoint VideoEndPoint::singleton("/videos");

void VideoEndPoint::_post(const Request* request) const
{
    request->response->body = request->body;
}
