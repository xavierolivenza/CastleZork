#include <stdio.h>
#include <string.h>
#include "World.h"

World::World(){
}

World::~World(){
	for (int i = 0; i < (worldexternpointer->entities.size() - 9); i++){
		delete entities[i];
	}
}

void World::Update(){
	for (int i = 0; i < (worldexternpointer->entities.size()); i++){
		if ((worldexternpointer->entities[i]->type == ENEMIE) || (worldexternpointer->entities[i]->type == MOVINGENEMIE)){
			((NPC*)(worldexternpointer->entities[i]))->NPCUpdate();
		}
	}
}

void World::CreateWorld(){
	// ---------------------------------------------------------------------------------------------------------------
	// Rooms
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 1
	worldexternpointer->entities.pushback(new Room("Tower 1", "In this tower there is nothing interesting, you should keep moving.", false, false, ROOM));
	// Tower 2
	worldexternpointer->entities.pushback(new Room("Tower 2", "A regular tower.", false, false, ROOM));
	// Tower 3
	worldexternpointer->entities.pushback(new Room("Tower 3", "In this tower there is a fireplace and a cupboard.", true, false, ROOM));
	// Tower 4
	worldexternpointer->entities.pushback(new Room("Tower 4", "In this tower there is a cupboard.", true, false, ROOM));
	// North Corridor
	worldexternpointer->entities.pushback(new Room("North corridor", "Nothing interesting in here.", false, false, ROOM));
	// East Corridor
	worldexternpointer->entities.pushback(new Room("East corridor", "In this corridor there's a cupboard.", true, false, ROOM));
	// South Corridor
	worldexternpointer->entities.pushback(new Room("South corridor", "In this corridor there's a cupboard.", true, false, ROOM));
	// West Corridor
	worldexternpointer->entities.pushback(new Room("West corridor", "In this corridor there's a table with a cupboard.", true, false, ROOM));
	// Throne Room
	worldexternpointer->entities.pushback(new Room("Throne room", "This is the mighty throne room of the king, people say that the treasure is hidden here.", true, true, ROOM));

	// ---------------------------------------------------------------------------------------------------------------
	// Items
	// ---------------------------------------------------------------------------------------------------------------
	// Katana
	worldexternpointer->entities.pushback(new Item("Rusty Katana", "This is the ancient rusty katana of a japanese guy, but still sharpened.", (Room*)worldexternpointer->entities[6], 35, 0, 1000, false, false, true, true, false, ITEM));
	// Gas Mask
	worldexternpointer->entities.pushback(new Item("Gas Mask", "This gas mask can save you from toxic gases.", (Room*)worldexternpointer->entities[7], 0, 0, 1000, false, false, true, true, false, ITEM));
	// Treasure
	worldexternpointer->entities.pushback(new Item("Treasure", "Your goal, the mighty treasure of the king.", (Room*)worldexternpointer->entities[8], 0, 0, 0, false, false, false, true, false, ITEM));
	// Venom Gas Granade
	worldexternpointer->entities.pushback(new Item("Venom Gas Grenade", "Usefull against big groups of enemies, but you should search a gas mask to use it safely.", (Room*)worldexternpointer->entities[5], 100, 0, 2, false, false, false, true, false, ITEM));
	// Sword
	worldexternpointer->entities.pushback(new Item("Sword", "Fullmetal sharpened sword, kill enemies with 2 hits.", (Room*)worldexternpointer->entities[2], 50, 0, 1000, false, false, true, true, false, ITEM));
	// Shield
	worldexternpointer->entities.pushback(new Item("Shield", "Protect you from enemy attacks.", (Room*)worldexternpointer->entities[2], 0, 75, 1000, false, false, true, true, false, ITEM));
	// Explosive
	worldexternpointer->entities.pushback(new Item("Explosive", "You can blow the treasure wall with that.", (Room*)worldexternpointer->entities[3], 1000, 0, 1000, false, false, false, true, false, ITEM));
	// Key
	worldexternpointer->entities.pushback(new Item("Key", "Key of tower 4.", (Room*)worldexternpointer->entities[4], 1, 0, 1, false, false, false, false, false, ITEM));
	// Backpack
	worldexternpointer->entities.pushback(new Item("Backpack", "Box to keep items inside.", (Room*)worldexternpointer->entities[1], 5, 0, 1000, false, false, false, false, false, ITEM));

	// ---------------------------------------------------------------------------------------------------------------
	// Exits
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 1
	//North
	worldexternpointer->entities.pushback(new Exit("East corridor door.", "There's a corridor, the east one.", (Room*)worldexternpointer->entities[0], (Room*)worldexternpointer->entities[5], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[0], (Room*)worldexternpointer->entities[0], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[0], (Room*)worldexternpointer->entities[0], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("South corridor door.", "There's a corridor, the south one.", (Room*)worldexternpointer->entities[0], (Room*)worldexternpointer->entities[6], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 2
	//North
	worldexternpointer->entities.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", (Room*)worldexternpointer->entities[1], (Room*)worldexternpointer->entities[7], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("South corridor door.", "There's a corridor, the south one.", (Room*)worldexternpointer->entities[1], (Room*)worldexternpointer->entities[6], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[1], (Room*)worldexternpointer->entities[1], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[1], (Room*)worldexternpointer->entities[1], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 3
	//North
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a fireplace.", (Room*)worldexternpointer->entities[2], (Room*)worldexternpointer->entities[2], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", (Room*)worldexternpointer->entities[2], (Room*)worldexternpointer->entities[4], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", (Room*)worldexternpointer->entities[2], (Room*)worldexternpointer->entities[7], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall with a cupboard.", (Room*)worldexternpointer->entities[2], (Room*)worldexternpointer->entities[2], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 4
	//North
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[3], (Room*)worldexternpointer->entities[3], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", (Room*)worldexternpointer->entities[3], (Room*)worldexternpointer->entities[3], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[3], (Room*)worldexternpointer->entities[3], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", (Room*)worldexternpointer->entities[3], (Room*)worldexternpointer->entities[4], true, true, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// North Corridor
	//North
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[4], (Room*)worldexternpointer->entities[4], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("Tower 4 door.", "There is the tower 4.", (Room*)worldexternpointer->entities[4], (Room*)worldexternpointer->entities[3], true, true, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Throne room door.", "There is a room, the throne room.", (Room*)worldexternpointer->entities[4], (Room*)worldexternpointer->entities[8], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("Tower 3 door.", "There is the tower 3.", (Room*)worldexternpointer->entities[4], (Room*)worldexternpointer->entities[2], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// East Corridor
	//North
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[5], (Room*)worldexternpointer->entities[5], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", (Room*)worldexternpointer->entities[5], (Room*)worldexternpointer->entities[5], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Tower 1 door.", "There is the tower 1.", (Room*)worldexternpointer->entities[5], (Room*)worldexternpointer->entities[0], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("Throne room door.", "There is a room, the throne room.", (Room*)worldexternpointer->entities[5], (Room*)worldexternpointer->entities[8], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// South Corridor
	//North
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall.", (Room*)worldexternpointer->entities[6], (Room*)worldexternpointer->entities[6], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("Tower 1 door.", "There is the tower 1.", (Room*)worldexternpointer->entities[6], (Room*)worldexternpointer->entities[0], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", (Room*)worldexternpointer->entities[6], (Room*)worldexternpointer->entities[6], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("Tower 2 door.", "There is the tower 2.", (Room*)worldexternpointer->entities[6], (Room*)worldexternpointer->entities[1], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// West Corridor
	//North
	worldexternpointer->entities.pushback(new Exit("Tower 2 door.", "There is the tower 2.", (Room*)worldexternpointer->entities[7], (Room*)worldexternpointer->entities[2], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("Throne room door.", "There is a room, the throne room.", (Room*)worldexternpointer->entities[7], (Room*)worldexternpointer->entities[8], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Tower 3 door.", "There is the tower 3.", (Room*)worldexternpointer->entities[7], (Room*)worldexternpointer->entities[1], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", (Room*)worldexternpointer->entities[7], (Room*)worldexternpointer->entities[7], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------
	// Throne Room
	//North
	worldexternpointer->entities.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", (Room*)worldexternpointer->entities[8], (Room*)worldexternpointer->entities[4], false, false, EXIT, north));
	//East
	worldexternpointer->entities.pushback(new Exit("East corridor door.", "There's a corridor, the east one.", (Room*)worldexternpointer->entities[8], (Room*)worldexternpointer->entities[5], false, false, EXIT, east));
	//South
	worldexternpointer->entities.pushback(new Exit("Wall.", "There's a wall with a portrait of the king.", (Room*)worldexternpointer->entities[8], (Room*)worldexternpointer->entities[8], false, false, EXIT, south));
	//West
	worldexternpointer->entities.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", (Room*)worldexternpointer->entities[8], (Room*)worldexternpointer->entities[7], false, false, EXIT, west));
	// ---------------------------------------------------------------------------------------------------------------

	//The enemies
	worldexternpointer->entities.pushback(new Enemie_normal_soldier("Soldier1.", "Soldier1.", (Room*)worldexternpointer->entities[8], ENEMIE));
	worldexternpointer->entities.pushback(new Enemie_normal_soldier("Soldier2.", "Soldier2.", (Room*)worldexternpointer->entities[8], ENEMIE));
	worldexternpointer->entities.pushback(new Enemie_normal_soldier("Soldier3.", "Soldier3.", (Room*)worldexternpointer->entities[8], ENEMIE));
	worldexternpointer->entities.pushback(new Enemie_normal_soldier("Soldier4.", "Soldier4.", (Room*)worldexternpointer->entities[3], ENEMIE));
	worldexternpointer->entities.pushback(new Enemie_normal_soldier("Soldier5.", "Soldier5.", (Room*)worldexternpointer->entities[3], ENEMIE));
	worldexternpointer->entities.pushback(new Enemie_big_soldier("BigSoldier.", "BigSoldier.", (Room*)worldexternpointer->entities[4], ENEMIE));
	worldexternpointer->entities.pushback(new Enemie_moving_soldier("Soldier6.", "Soldier6.", (Room*)worldexternpointer->entities[2], MOVINGENEMIE));
	worldexternpointer->entities.pushback(new Enemie_normal_soldier("Seller.", "Seller.", (Room*)worldexternpointer->entities[1], ENEMIE));

	//The player
	worldexternpointer->entities.pushback(new Player("The mighty hero.", "It's you, the mighty hero.", (Room*)worldexternpointer->entities[0], PLAYER));
}