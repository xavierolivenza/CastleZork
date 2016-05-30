#include <stdio.h>
#include <windows.h>
#include "Enemie_Seller.h"
#include "World.h"

Enemie_seller::Enemie_seller(){
}

Enemie_seller::Enemie_seller(const char* name, const char* description, Room* initialroom, EntityType type) :NPC(name, description, initialroom, type){
}

Enemie_seller::~Enemie_seller(){
}

void Enemie_seller::NPCUpdate(){
	Enemie_seller::NPCmove();
	Enemie_seller::NPCattack();
}

void Enemie_seller::NPCmove(){
	//This NPC doesn't move
}

void Enemie_seller::NPCattack(){
	//This NPC doesn't attack
}