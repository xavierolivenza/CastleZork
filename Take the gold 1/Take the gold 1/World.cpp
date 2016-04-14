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
	worldexternpointer->items.pushback(new Item("Rusty Katana", "This is the ancient rusty katana of a japanese guy, but still sharpened.", worldexternpointer->castlerooms[SOUTHCORRIDOR], 35, 0, 1000, false, false, true, true));
	// Gas Mask
	worldexternpointer->items.pushback(new Item("Gas Mask", "This gas mask can save you from toxic gases.", worldexternpointer->castlerooms[WESTCORRIDOR], 0, 0, 1000, false, false, true, true));
	// Treasure
	worldexternpointer->items.pushback(new Item("Treasure", "Your goal, the mighty treasure of the king.", worldexternpointer->castlerooms[THRONEROOM], 0, 0, 0, false, false, false, true));
	// Venom Gas Granade
	worldexternpointer->items.pushback(new Item("Venom Gas Granade", "Usefull against big groups of enemies, but you should search a gas mask to use it safely.", worldexternpointer->castlerooms[EASTCORRIDOR], 100, 0, 2, false, false, false, true));
	// Sword
	worldexternpointer->items.pushback(new Item("Sword", "Fullmetal sharpened sword, kill enemies with 2 hits.", worldexternpointer->castlerooms[TOWER3], 50, 0, 1000, false, false, true, true));
	// Shield
	worldexternpointer->items.pushback(new Item("Shield", "Protect you from enemy attacks.", worldexternpointer->castlerooms[TOWER3], 0, 75, 1000, false, false, true, true));
	// Explosive
	worldexternpointer->items.pushback(new Item("Explosive", "You can blow the treasure wall with that.", worldexternpointer->castlerooms[TOWER4], 1000, 0, 1000, false, false, false, true));
	// Key
	worldexternpointer->items.pushback(new Item("Key", "Key of tower 4.", worldexternpointer->castlerooms[NORTHCORRIDOR], 1, 0, 1, false, false, false, false));

	worldexternpointer->player->current_room = worldexternpointer->castlerooms[TOWER1];

	/*
	// ---------------------------------------------------------------------------------------------------------------
	// Rooms
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 1
	worldexternpointer->castlerooms.pushback(new Room("Tower 1", "In this tower there is nothing interesting, you should keep moving.", false));
	// Tower 2
	castlerooms.pushback(new Room("Tower 2", "A regular tower.", false));
	// Tower 3
	castlerooms.pushback(new Room("Tower 3", "In this tower there is a fireplace and a cupboard.", true));
	// Tower 4
	castlerooms.pushback(new Room("Tower 4", "In this tower there is a cupboard.", true));
	// North Corridor
	castlerooms.pushback(new Room("North corridor", "Nothing interesting in here.", false));
	// East Corridor
	castlerooms.pushback(new Room("East corridor", "In this corridor there's a cupboard.", true));
	// South Corridor
	castlerooms.pushback(new Room("South corridor", "In this corridor there's a cupboard.", true));
	// West Corridor
	castlerooms.pushback(new Room("West corridor", "In this corridor there's a table with a cupboard.", true));
	// Throne Room
	castlerooms.pushback(new Room("Throne room", "This is the mighty throne room of the king, people say that the treasure is hidden here.", true));

	// ---------------------------------------------------------------------------------------------------------------
	// Exits
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 1
	//North
	exits.pushback(new Exit("East corridor door.", "There's a corridor, the east one.", castlerooms[TOWER1], castlerooms[EASTCORRIDOR], false, false));
	//East
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[TOWER1], castlerooms[TOWER1], false, false));
	//South
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[TOWER1], castlerooms[TOWER1], false, false));
	//West
	exits.pushback(new Exit("South corridor door.", "There's a corridor, the south one.", castlerooms[TOWER1], castlerooms[SOUTHCORRIDOR], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 2
	//North
	exits.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", castlerooms[TOWER2], castlerooms[WESTCORRIDOR], false, false));
	//East
	exits.pushback(new Exit("South corridor door.", "There's a corridor, the south one.", castlerooms[TOWER2], castlerooms[SOUTHCORRIDOR], false, false));
	//South
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[TOWER2], castlerooms[TOWER2], false, false));
	//West
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[TOWER2], castlerooms[TOWER2], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 3
	//North
	exits.pushback(new Exit("Wall.", "There's a fireplace.", castlerooms[TOWER3], castlerooms[TOWER3], false, false));
	//East
	exits.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", castlerooms[TOWER3], castlerooms[NORTHCORRIDOR], false, false));
	//South
	exits.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", castlerooms[TOWER3], castlerooms[WESTCORRIDOR], false, false));
	//West
	exits.pushback(new Exit("Wall.", "There's a wall with a cupboard.", castlerooms[TOWER3], castlerooms[TOWER3],false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 4
	//North
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[TOWER4], castlerooms[TOWER4], false, false));
	//East
	exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", castlerooms[TOWER4], castlerooms[TOWER4], false, false));
	//South
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[TOWER4], castlerooms[TOWER4], false, false));
	//West
	exits.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", castlerooms[TOWER4], castlerooms[NORTHCORRIDOR], true, true));
	// ---------------------------------------------------------------------------------------------------------------
	// North Corridor
	//North
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[NORTHCORRIDOR], castlerooms[NORTHCORRIDOR], false, false));
	//East
	exits.pushback(new Exit("Tower 4 door.", "There is the tower 4.", castlerooms[NORTHCORRIDOR], castlerooms[TOWER4], true, true));
	//South
	exits.pushback(new Exit("Throne room door.", "There is a room, the throne room.", castlerooms[NORTHCORRIDOR], castlerooms[THRONEROOM], false, false));
	//West
	exits.pushback(new Exit("Tower 3 door.", "There is the tower 3.", castlerooms[NORTHCORRIDOR], castlerooms[TOWER3], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// East Corridor
	//North
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[EASTCORRIDOR], castlerooms[EASTCORRIDOR], false, false));
	//East
	exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", castlerooms[EASTCORRIDOR], castlerooms[EASTCORRIDOR], false, false));
	//South
	exits.pushback(new Exit("Tower 1 door.", "There is the tower 1.", castlerooms[EASTCORRIDOR], castlerooms[TOWER1], false, false));
	//West
	exits.pushback(new Exit("Throne room door.", "There is a room, the throne room.", castlerooms[EASTCORRIDOR], castlerooms[THRONEROOM], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// South Corridor
	//North
	exits.pushback(new Exit("Wall.", "There's a wall.", castlerooms[SOUTHCORRIDOR], castlerooms[SOUTHCORRIDOR], false, false));
	//East
	exits.pushback(new Exit("Tower 1 door.", "There is the tower 1.", castlerooms[SOUTHCORRIDOR], castlerooms[TOWER1], false, false));
	//South
	exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", castlerooms[SOUTHCORRIDOR], castlerooms[SOUTHCORRIDOR], false, false));
	//West
	exits.pushback(new Exit("Tower 2 door.", "There is the tower 2.", castlerooms[SOUTHCORRIDOR], castlerooms[TOWER2], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// West Corridor
	//North
	exits.pushback(new Exit("Tower 2 door.", "There is the tower 2.", castlerooms[WESTCORRIDOR], castlerooms[TOWER3], false, false));
	//East
	exits.pushback(new Exit("Throne room door.", "There is a room, the throne room.", castlerooms[WESTCORRIDOR], castlerooms[THRONEROOM], false, false));
	//South
	exits.pushback(new Exit("Tower 3 door.", "There is the tower 3.", castlerooms[WESTCORRIDOR], castlerooms[TOWER2], false, false));
	//West
	exits.pushback(new Exit("Wall.", "There's a cupboard that seems that it could be oppened.", castlerooms[WESTCORRIDOR], castlerooms[WESTCORRIDOR], false, false));
	// ---------------------------------------------------------------------------------------------------------------
	// Throne Room
	//North
	exits.pushback(new Exit("North corridor door.", "There's a corridor, the north one.", castlerooms[THRONEROOM], castlerooms[NORTHCORRIDOR], false, false));
	//East
	exits.pushback(new Exit("East corridor door.", "There's a corridor, the east one.", castlerooms[THRONEROOM], castlerooms[EASTCORRIDOR], false, false));
	//South
	exits.pushback(new Exit("Wall.", "There's a wall with a portrait of the king.", castlerooms[THRONEROOM], castlerooms[THRONEROOM], false, false));
	//West
	exits.pushback(new Exit("West corridor door.", "There's a corridor, the west one.", castlerooms[THRONEROOM], castlerooms[WESTCORRIDOR], false, false));
	// ---------------------------------------------------------------------------------------------------------------

	// ---------------------------------------------------------------------------------------------------------------
	// Items
	// ---------------------------------------------------------------------------------------------------------------
	// Katana
	items.pushback(new Item("Rusty Katana", "This is the ancient rusty katana of a japanese guy, but still sharpened.", castlerooms[SOUTHCORRIDOR], 35, 0, 1000, false, false, true, true));
	// Gas Mask
	items.pushback(new Item("Gas Mask", "This gas mask can save you from toxic gases.", castlerooms[WESTCORRIDOR], 0, 0, 1000, false, false, true, true));
	// Treasure
	items.pushback(new Item("Treasure", "Your goal, the mighty treasure of the king.", castlerooms[THRONEROOM], 0, 0, 0, false, false, false, true));
	// Venom Gas Granade
	items.pushback(new Item("Venom Gas Granade", "Usefull against big groups of enemies, but you should search a gas mask to use it safely.", castlerooms[EASTCORRIDOR], 100, 0, 2, false, false, false, true));
	// Sword
	items.pushback(new Item("Sword", "Fullmetal sharpened sword, kill enemies with 2 hits.", castlerooms[TOWER3], 50, 0, 1000, false, false, true, true));
	// Shield
	items.pushback(new Item("Shield", "Protect you from enemy attacks.", castlerooms[TOWER3], 0, 75, 1000, false, false, true, true));
	// Explosive
	items.pushback(new Item("Explosive", "You can blow the treasure wall with that.", castlerooms[TOWER4], 1000, 0, 1000, false, false, false, true));
	// Key
	items.pushback(new Item("Key", "Key of tower 4.", castlerooms[NORTHCORRIDOR], 1, 0, 1, false, false, false, false));
	*/
}