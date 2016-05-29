#include"Enemie_big_soldier.h"

Enemie_big_soldier::Enemie_big_soldier(){
}

Enemie_big_soldier::Enemie_big_soldier(const char* name, const char* description, Room* initialroom, EntityType type) :NPC(name, description, initialroom, type){
}

Enemie_big_soldier::~Enemie_big_soldier(){
}

void Enemie_big_soldier::NPCUpdate(){
	Enemie_big_soldier::NPCmove();
	Enemie_big_soldier::NPCattack();
}

void Enemie_big_soldier::NPCmove(){
	//This NPC doesn't move
}

void Enemie_big_soldier::NPCattack(){
	//if player is in the room auto attack

}