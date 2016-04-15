#include <stdio.h>
#include <string.h>
#include "World.h"

World::World(){
	player = new Player;
}

World::~World(){
	delete player;
}

void World::CreateWorld(){
	// ---------------------------------------------------------------------------------------------------------------
	// Rooms
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 1
	worldexternpointer->castlerooms.pushback(new Room("Tower 1", "In this tower there is nothing interesting, you should keep moving.", false));
	// Tower 2
	worldexternpointer->castlerooms.pushback(new Room("Tower 2", "A regular tower.", false));
	// Tower 3
	worldexternpointer->castlerooms.pushback(new Room("Tower 3", "In this tower there is a fireplace and a cupboard.", true));
	// Tower 4
	worldexternpointer->castlerooms.pushback(new Room("Tower 4", "In this tower there is a cupboard.", true));
	// North Corridor
	worldexternpointer->castlerooms.pushback(new Room("North corridor", "Nothing interesting in here.", false));
	// East Corridor
	worldexternpointer->castlerooms.pushback(new Room("East corridor", "In this corridor there's a cupboard.", true));
	// South Corridor
	worldexternpointer->castlerooms.pushback(new Room("South corridor", "In this corridor there's a cupboard.", true));
	// West Corridor
	worldexternpointer->castlerooms.pushback(new Room("West corridor", "In this corridor there's a table with a cupboard.", true));
	// Throne Room
	worldexternpointer->castlerooms.pushback(new Room("Throne room", "This is the mighty throne room of the king, people say that the treasure is hidden here.", true));

	// ---------------------------------------------------------------------------------------------------------------
	// Exits
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 1
	//North
	worldexternpointer->exits.pushback(new Exit("East corridor door.", "There's a corridor, the east one.", worldexternpointer->castlerooms[TOWER1], worldexternpointer->castlerooms[EASTCORRIDOR], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[TOWER1], worldexternpointer->castlerooms[TOWER1], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[TOWER1], worldexternpointer->castlerooms[TOWER1], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("South corridor door.", "There's a corridor, the south one.", worldexternpointer->castlerooms[TOWER1], worldexternpointer->castlerooms[SOUTHCORRIDOR], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 2
	//North
	worldexternpointer->exits.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", worldexternpointer->castlerooms[TOWER2], worldexternpointer->castlerooms[WESTCORRIDOR], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("South corridor door.", "There's a corridor, the south one.", worldexternpointer->castlerooms[TOWER2], worldexternpointer->castlerooms[SOUTHCORRIDOR], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[TOWER2], worldexternpointer->castlerooms[TOWER2], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[TOWER2], worldexternpointer->castlerooms[TOWER2], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 3
	//North
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a fireplace.", worldexternpointer->castlerooms[TOWER3], worldexternpointer->castlerooms[TOWER3], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", worldexternpointer->castlerooms[TOWER3], worldexternpointer->castlerooms[NORTHCORRIDOR], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", worldexternpointer->castlerooms[TOWER3], worldexternpointer->castlerooms[WESTCORRIDOR], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall with a cupboard.", worldexternpointer->castlerooms[TOWER3], worldexternpointer->castlerooms[TOWER3], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 4
	//North
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[TOWER4], worldexternpointer->castlerooms[TOWER4], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", worldexternpointer->castlerooms[TOWER4], worldexternpointer->castlerooms[TOWER4], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[TOWER4], worldexternpointer->castlerooms[TOWER4], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", worldexternpointer->castlerooms[TOWER4], worldexternpointer->castlerooms[NORTHCORRIDOR], true, true));
	// ---------------------------------------------------------------------------------------------------------------
	// North Corridor
	//North
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[NORTHCORRIDOR], worldexternpointer->castlerooms[NORTHCORRIDOR], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("Tower 4 door.", "There is the tower 4.", worldexternpointer->castlerooms[NORTHCORRIDOR], worldexternpointer->castlerooms[TOWER4], true, true));
	//South
	worldexternpointer->exits.pushback(new Exit("Throne room door.", "There is a room, the throne room.", worldexternpointer->castlerooms[NORTHCORRIDOR], worldexternpointer->castlerooms[THRONEROOM], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("Tower 3 door.", "There is the tower 3.", worldexternpointer->castlerooms[NORTHCORRIDOR], worldexternpointer->castlerooms[TOWER3], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// East Corridor
	//North
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[EASTCORRIDOR], worldexternpointer->castlerooms[EASTCORRIDOR], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", worldexternpointer->castlerooms[EASTCORRIDOR], worldexternpointer->castlerooms[EASTCORRIDOR], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("Tower 1 door.", "There is the tower 1.", worldexternpointer->castlerooms[EASTCORRIDOR], worldexternpointer->castlerooms[TOWER1], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("Throne room door.", "There is a room, the throne room.", worldexternpointer->castlerooms[EASTCORRIDOR], worldexternpointer->castlerooms[THRONEROOM], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// South Corridor
	//North
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall.", worldexternpointer->castlerooms[SOUTHCORRIDOR], worldexternpointer->castlerooms[SOUTHCORRIDOR], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("Tower 1 door.", "There is the tower 1.", worldexternpointer->castlerooms[SOUTHCORRIDOR], worldexternpointer->castlerooms[TOWER1], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", worldexternpointer->castlerooms[SOUTHCORRIDOR], worldexternpointer->castlerooms[SOUTHCORRIDOR], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("Tower 2 door.", "There is the tower 2.", worldexternpointer->castlerooms[SOUTHCORRIDOR], worldexternpointer->castlerooms[TOWER2], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// West Corridor
	//North
	worldexternpointer->exits.pushback(new Exit("Tower 2 door.", "There is the tower 2.", worldexternpointer->castlerooms[WESTCORRIDOR], worldexternpointer->castlerooms[TOWER3], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("Throne room door.", "There is a room, the throne room.", worldexternpointer->castlerooms[WESTCORRIDOR], worldexternpointer->castlerooms[THRONEROOM], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("Tower 3 door.", "There is the tower 3.", worldexternpointer->castlerooms[WESTCORRIDOR], worldexternpointer->castlerooms[TOWER2], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", worldexternpointer->castlerooms[WESTCORRIDOR], worldexternpointer->castlerooms[WESTCORRIDOR], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Throne Room
	//North
	worldexternpointer->exits.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", worldexternpointer->castlerooms[THRONEROOM], worldexternpointer->castlerooms[NORTHCORRIDOR], false, false));
	//East
	worldexternpointer->exits.pushback(new Exit("East corridor door.", "There's a corridor, the east one.", worldexternpointer->castlerooms[THRONEROOM], worldexternpointer->castlerooms[EASTCORRIDOR], false, false));
	//South
	worldexternpointer->exits.pushback(new Exit("Wall.", "There's a wall with a portrait of the king.", worldexternpointer->castlerooms[THRONEROOM], worldexternpointer->castlerooms[THRONEROOM], false, false));
	//West
	worldexternpointer->exits.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", worldexternpointer->castlerooms[THRONEROOM], worldexternpointer->castlerooms[WESTCORRIDOR], false, false));
	// ---------------------------------------------------------------------------------------------------------------

	// ---------------------------------------------------------------------------------------------------------------
	// Items
	// ---------------------------------------------------------------------------------------------------------------
	// Katana
	worldexternpointer->items.pushback(new Item("Rusty Katana", "This is the ancient rusty katana of a japanese guy, but still sharpened.", worldexternpointer->castlerooms[SOUTHCORRIDOR], 35, 0, 1000, false, false, true, true, false));
	// Gas Mask
	worldexternpointer->items.pushback(new Item("Gas Mask", "This gas mask can save you from toxic gases.", worldexternpointer->castlerooms[WESTCORRIDOR], 0, 0, 1000, false, false, true, true, false));
	// Treasure
	worldexternpointer->items.pushback(new Item("Treasure", "Your goal, the mighty treasure of the king.", worldexternpointer->castlerooms[THRONEROOM], 0, 0, 0, false, false, false, true, false));
	// Venom Gas Granade
	worldexternpointer->items.pushback(new Item("Venom Gas Granade", "Usefull against big groups of enemies, but you should search a gas mask to use it safely.", worldexternpointer->castlerooms[EASTCORRIDOR], 100, 0, 2, false, false, false, true, false));
	// Sword
	worldexternpointer->items.pushback(new Item("Sword", "Fullmetal sharpened sword, kill enemies with 2 hits.", worldexternpointer->castlerooms[TOWER3], 50, 0, 1000, false, false, true, true, false));
	// Shield
	worldexternpointer->items.pushback(new Item("Shield", "Protect you from enemy attacks.", worldexternpointer->castlerooms[TOWER3], 0, 75, 1000, false, false, true, true, false));
	// Explosive
	worldexternpointer->items.pushback(new Item("Explosive", "You can blow the treasure wall with that.", worldexternpointer->castlerooms[TOWER4], 1000, 0, 1000, false, false, false, true, false));
	// Key
	worldexternpointer->items.pushback(new Item("Key", "Key of tower 4.", worldexternpointer->castlerooms[NORTHCORRIDOR], 1, 0, 1, false, false, false, false, false));
	// Backpack
	worldexternpointer->items.pushback(new Item("Backpack", "Box to keep items inside.", worldexternpointer->castlerooms[TOWER2], 5, 0, 1000, false, false, false, false, false));


	worldexternpointer->player->current_room = worldexternpointer->castlerooms[TOWER1];
}