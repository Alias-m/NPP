#ifndef VIDEO_ENDPOINT_H
#define VIDEO_ENDPOINT_H
#include "../../includes/http.hpp"

class VideoEndPoint: public HttpEndPoint
{
public:
    VideoEndPoint(const char* route):HttpEndPoint(route){}
    static VideoEndPoint singleton;
    void _get(const Request* request) const;

};

#endif // VIDEO_ENDPOINT_H
