#include <stdio.h>
#include <windows.h>
#include "Enemie_normal_soldier.h"
#include "World.h"

Enemie_normal_soldier::Enemie_normal_soldier(){
}

Enemie_normal_soldier::Enemie_normal_soldier(const char* name, const char* description, Room* initialroom, EntityType type) :NPC(name, description, initialroom, type){
}

Enemie_normal_soldier::~Enemie_normal_soldier(){
}

void Enemie_normal_soldier::NPCUpdate(){
	Enemie_normal_soldier::NPCmove();
	Enemie_normal_soldier::NPCattack();
}

void Enemie_normal_soldier::NPCmove(){
	//This NPC doesn't move
}

void Enemie_normal_soldier::NPCattack(){
	//if player is in the room auto attack
	currenttime = GetTickCount();
	if (currenttime >= (initialtime + 5000)){
		if (((NPC*)this)->current_room == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room){
			if (((Enemie_moving_soldier*)this)->hp > 0){
				((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->hp -= ((Enemie_normal_soldier*)this)->attack - (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->defense / 4);
				printf("%s Had attacked you with %i of damage.\n", ((Enemie_normal_soldier*)this)->name.c_str(), ((Enemie_normal_soldier*)this)->attack - (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->defense / 4));
			}
		}
		initialtime = currenttime;
	}
}