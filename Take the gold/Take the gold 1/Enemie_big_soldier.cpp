#include <stdio.h>
#include <Windows.h>
#include "World.h"
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
	currenttime = GetTickCount();
	if (currenttime >= (initialtime + 5000)){
		if (((NPC*)this)->current_room == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room){
			if (((Enemie_moving_soldier*)this)->hp > 0){
				((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->hp -= ((Enemie_big_soldier*)this)->attack - (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->defense / 4);
				printf("%s Had attacked you with %i of damage.\n", ((Enemie_big_soldier*)this)->name.c_str(), ((Enemie_big_soldier*)this)->attack - (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->defense / 4));
			}
		}
		initialtime = currenttime;
	}
}