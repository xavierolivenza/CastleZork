#include "Room.h"
Room::Room(){
}

Room::Room(const char* name, const char* description, bool cupboard, bool exploitablewall, EntityType type) :Entity(name, description, type), cupboard(cupboard), exploitablewall(exploitablewall){
}

Room::~Room(){
}