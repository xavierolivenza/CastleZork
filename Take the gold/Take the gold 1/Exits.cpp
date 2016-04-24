#include "Exits.h"

Exit::Exit(){
}

Exit::Exit(const char* name, const char* description, Room* origin, Room* destination, bool close, bool door) : Entity(name, description), origin(origin), destination(destination), close(close), door(door){
}

Exit::~Exit(){
}