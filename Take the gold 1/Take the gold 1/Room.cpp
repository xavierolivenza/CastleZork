#include "Room.h"
Room::Room(){
}

Room::Room(const char* s1, const char* s2, bool s3) :Entity(s1, s2), cupboard(s3){
}

Room::~Room(){
}