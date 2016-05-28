#include <stdio.h>
#include <Windows.h>
#include "Enemie_moving_soldier.h"
#include "World.h"

#define DELAY 10000//10 seconds delay of the soldier movement

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
	currenttime = GetTickCount();
	Room* dasd = ((NPC*)worldexternpointer->entities[60])->current_room;
	if (((NPC*)worldexternpointer->entities[60])->current_room != ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room){//if player is not in the room
		if (currenttime >= (initialtime + DELAY)){
			if (((NPC*)worldexternpointer->entities[60])->current_room == (Room*)worldexternpointer->entities[2]){
				((NPC*)worldexternpointer->entities[60])->current_room = (Room*)worldexternpointer->entities[4];
			}
			else if (((NPC*)worldexternpointer->entities[60])->current_room == (Room*)worldexternpointer->entities[4]){
				((NPC*)worldexternpointer->entities[60])->current_room = (Room*)worldexternpointer->entities[8];
			}
			else if (((NPC*)worldexternpointer->entities[60])->current_room == (Room*)worldexternpointer->entities[8]){
				((NPC*)worldexternpointer->entities[60])->current_room = (Room*)worldexternpointer->entities[7];
			}
			else if (((NPC*)worldexternpointer->entities[60])->current_room == (Room*)worldexternpointer->entities[7]){
				((NPC*)worldexternpointer->entities[60])->current_room = (Room*)worldexternpointer->entities[2];
			}
			if (((NPC*)worldexternpointer->entities[60])->current_room == ((Room*)((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room)){
				printf("//------------------------------------------------------------------------//\n");
				printf("%s\nHad arrived.\n", name.c_str());
				printf("//------------------------------------------------------------------------//\n");
			}
			initialtime = currenttime;
		}
	}
}

void Enemie_moving_soldier::NPCattack(){

}