#include "Enemie_moving_soldier.h"

Enemie_moving_soldier::Enemie_moving_soldier(){
}

Enemie_moving_soldier::Enemie_moving_soldier(const char* name, const char* description, Room* initialroom, EntityType type) :NPC(name, description, initialroom, type){
}

Enemie_moving_soldier::~Enemie_moving_soldier(){
}

void Enemie_moving_soldier::NPCUpdate(){
	NPCmove();
	NPCattack();
}

void Enemie_moving_soldier::NPCmove(){

}

void Enemie_moving_soldier::NPCattack(){

}