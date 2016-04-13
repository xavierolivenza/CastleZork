#include "Exits.h"

Exit::Exit(){
}

Exit::Exit(const char* s1, const char* s2, Room* s3, Room* s4, const bool s5, const bool s6){
	this->name = s1;
	this->description = s2;
	this->origin = s3;
	this->destination = s4;
	this->close = s5;
	this->door = s6;
}

Exit::~Exit(){
}