#include "../../includes/npp_parser.hpp"
#include "../streams/Element.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>

npp::ElementCreator npp::ElementCreator::creator;

ElementInt* npp::ElementCreator::create(int value) const{
	ElementInt* e = new ElementInt();
	e->value = value;
	return e;
}
ElementString* npp::ElementCreator::create(const char* value) const{
	ElementString* e = new ElementString();
	e->value = value;
	return e;
}
ElementBoolean* npp::ElementCreator::create(bool value) const{
	ElementBoolean* e = new ElementBoolean();
	e->value = value;
	return e;
}
ElementArray* npp::ElementCreator::array() const{
	ElementArray* e = new ElementArray();
	return e;
}
ElementObject* npp::ElementCreator::object() const{
	ElementObject* e = new ElementObject();
	return e;
}
npp::ElementCreator* npp::ElementCreator::add(ElementArray* e, Element* value){
	e->values.push_back(value);
	return this;
}
npp::ElementCreator* npp::ElementCreator::put(ElementObject* e, const char* key, Element* value){
	e->values[new std::string(key)] = value;
	return this;
}
ElementDouble* npp::ElementCreator::create(double value) const{
	ElementDouble* e = new ElementDouble();
	e->value = value;
	return e;
}
npp::ElementCreator::ElementCreator(){
}
npp::ElementCreator::~ElementCreator(){
}
