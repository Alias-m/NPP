#ifndef VIDEO_H
#define VIDEO_H
#include "../../src/includes/object.hpp"
#include <string>

class Video: public Object
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
