#include"Enemie_normal_soldier.h"

Enemie_normal_soldier::Enemie_normal_soldier(){
}

Enemie_normal_soldier::Enemie_normal_soldier(const char* name, const char* description, Room* initialroom, EntityType type) :NPC(name, description, initialroom, type){
}

Enemie_normal_soldier::~Enemie_normal_soldier(){
}

void Enemie_normal_soldier::NPCUpdate(){
	NPCmove();
	NPCattack();
}

void Enemie_normal_soldier::NPCmove(){

}

void Enemie_normal_soldier::NPCattack(){

}