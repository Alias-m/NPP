#include "ElementCreator.hpp"
#include "../streams/Element.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>

ElementCreator ElementCreator::creator;

ElementInt* ElementCreator::create(int value) const{
	ElementInt* e = new ElementInt();
	e->value = value;
	return e;
}
ElementString* ElementCreator::create(const char* value) const{
	ElementString* e = new ElementString();
	e->value = value;
	return e;
}
ElementBoolean* ElementCreator::create(bool value) const{
	ElementBoolean* e = new ElementBoolean();
	e->value = value;
	return e;
}
ElementArray* ElementCreator::array() const{
	ElementArray* e = new ElementArray();
	return e;
}
ElementObject* ElementCreator::object() const{
	ElementObject* e = new ElementObject();
	return e;
}
ElementCreator* ElementCreator::add(ElementArray* e, Element* value){
	e->values.push_back(value);
	return this;
}
ElementCreator* ElementCreator::put(ElementObject* e, const char* key, Element* value){
	e->values[new std::string(key)] = value;
	return this;
}
ElementDouble* ElementCreator::create(double value) const{
	ElementDouble* e = new ElementDouble();
	e->value = value;
	return e;
}
ElementCreator::ElementCreator(){
}
ElementCreator::~ElementCreator(){
}
