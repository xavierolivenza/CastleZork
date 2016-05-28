#include"NPC.h"

NPC::NPC(){
}

NPC::NPC(const char* name, const char* description, Room* initialroom, EntityType type) :Creature(name, description, initialroom, type){
}

NPC::~NPC(){
}