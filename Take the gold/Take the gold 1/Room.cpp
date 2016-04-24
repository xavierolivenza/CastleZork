#include "Room.h"
Room::Room(){
}

Room::Room(const char* name, const char* description, bool cupboard, bool exploitablewall) :Entity(name, description), cupboard(cupboard), exploitablewall(exploitablewall){
}

Room::~Room(){
}