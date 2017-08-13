#include "Videos.hpp"

Video::Video(std::string n, int l, int d, int c, std::string u): name(n), like(l), dislike(d), comment(c), user(u){
}

Element* Video::toElement() const{
    ElementObject* e = npp::ElementCreator::creator.object();
    npp::ElementCreator::creator.put(e, "name", npp::ElementCreator::creator.create(name.c_str()))
        ->put(e, "like", npp::ElementCreator::creator.create(like))
        ->put(e, "dislike", npp::ElementCreator::creator.create(dislike))
        ->put(e, "comment", npp::ElementCreator::creator.create(comment))
        ->put(e, "user", npp::ElementCreator::creator.create(user.c_str()));
    return e;
}

void Video::fromElement(ElementObject* e){
    e->getItem("name", &name);
    e->getItem("like", &like);
    e->getItem("dislike", &dislike);
    e->getItem("comment", &comment);
    e->getItem("user", &user);
}
