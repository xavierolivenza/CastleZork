#include "Exits.h"

Exit::Exit(){
}

Exit::Exit(const char* s1, const char* s2, Room* s3, Room* s4, const bool s5, const bool s6) : origin(s3), destination(s4), close(s5), door(s6){
	this->name = s1;
	this->description = s2;
}

Exit::~Exit(){
}