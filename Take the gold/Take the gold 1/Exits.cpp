#include "Exits.h"

Exit::Exit(){
}

Exit::Exit(const char* name, const char* description, Room* origin, Room* destination, bool close, bool door, EntityType type, directions exitdirection) : Entity(name, description, type), origin(origin), destination(destination), close(close), door(door), direct(exitdirection){
}

Exit::~Exit(){
}