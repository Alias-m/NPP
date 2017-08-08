#include "Videos.hpp"

VideoEndPoint VideoEndPoint::singleton("/videos");

void VideoEndPoint::_get(const Request* request) const
{
    std::cout << "Endpoint reached" << std::endl;
}
