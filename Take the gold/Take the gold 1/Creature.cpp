#include "Creature.h"

Creature::Creature(){
}

Creature::Creature(const char* name, const char* description, Room* initialroom, EntityType type) :Entity(name, description, type), current_room(initialroom){
}

Creature::~Creature(){
}