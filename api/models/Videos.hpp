#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include "../../src/includes/npp.hpp"
#include "../../src/includes/npp_parser.hpp"

class Video: public npp::Object
{
public:
    std::string name;
    int like;
    int dislike;
    int comment;
    std::string user;
    Video(std::string n, int l, int d, int c, std::string u);
    virtual Element* toElement() const;
    virtual void fromElement(ElementObject*);
};

#endif // VIDEO_H
