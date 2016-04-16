#include "Room.h"
Room::Room(){
}

Room::Room(const char* s1, const char* s2, bool s3, bool s4) :Entity(s1, s2), cupboard(s3), exploitablewall(s4){
}

Room::~Room(){
}