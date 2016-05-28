#include"Enemie_big_soldier.h"

Enemie_big_soldier::Enemie_big_soldier(){
}

Enemie_big_soldier::Enemie_big_soldier(const char* name, const char* description, Room* initialroom, EntityType type) :NPC(name, description, initialroom, type){
}

Enemie_big_soldier::~Enemie_big_soldier(){
}

void Enemie_big_soldier::NPCUpdate(){
	NPCmove();
	NPCattack();
}

void Enemie_big_soldier::NPCmove(){

}

void Enemie_big_soldier::NPCattack(){

}