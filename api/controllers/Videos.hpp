#ifndef VIDEO_ENDPOINT_H
#define VIDEO_ENDPOINT_H
#include <iostream>
#include "../../src/modules/http/includes/http.hpp"
#include "../models/Videos.hpp"

class VideoEndPoint: public HttpEndPoint
{
public:
    VideoEndPoint(const char* route):HttpEndPoint(route){}
    static VideoEndPoint singleton;
    void _post(const HttpRequest* request) const;

};


#endif // VIDEO_ENDPOINT_H
