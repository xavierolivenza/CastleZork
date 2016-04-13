#include "Room.h"
Room::Room(){
}

Room::Room(const char* s1, const char* s2, const bool s3){
	this->name = s1;
	this->description = s2;
	this->cupboard = s3;
}

Room::~Room(){
}