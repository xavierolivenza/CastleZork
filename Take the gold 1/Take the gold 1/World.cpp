#include <stdio.h>
#include <string.h>
#include "World.h"

World::World(){
	castlerooms = new Room[NUMROOMS];
	exits = new Exit[NUMEXITS];
	player = new Player;
	player->current_room = &castlerooms[TOWER1];
	items = new Item[NUMITEMS];
}

World::~World(){
	delete[] castlerooms;
	delete[] exits;
	delete player;
	delete[] items;
}

void World::CreateWorld() const{
	// ---------------------------------------------------------------------------------------------------------------
	// Rooms and exits
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 1
	castlerooms[TOWER1].name = "Tower 1";
	castlerooms[TOWER1].description = "In this tower there is nothing interesting, you should keep moving.";
	//North
	exits[0].name = "East corridor door.";
	exits[0].description = "There's a corridor, the east one.";
	exits[0].origin = &castlerooms[TOWER1];
	exits[0].destination = &castlerooms[EASTCORRIDOR];
	exits[0].direction = North;
	//East
	exits[1].name = "Wall.";
	exits[1].description = "There's a wall.";
	exits[1].origin = &castlerooms[TOWER1];
	exits[1].destination = &castlerooms[TOWER1];
	exits[1].direction = East;
	//South
	exits[2].name = "Wall.";
	exits[2].description = "There's a wall.";
	exits[2].origin = &castlerooms[TOWER1];
	exits[2].destination = &castlerooms[TOWER1];
	exits[2].direction = South;
	//West
	exits[3].name = "South corridor door.";
	exits[3].description = "There's a corridor, the south one.";
	exits[3].origin = &castlerooms[TOWER1];
	exits[3].destination = &castlerooms[SOUTHCORRIDOR];
	exits[3].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 2
	castlerooms[TOWER2].name = "Tower 2";
	castlerooms[TOWER2].description = "A regular tower.";
	//North
	exits[4].name = "West corridor door.";
	exits[4].description = "There's a corridor, the west one.";
	exits[4].origin = &castlerooms[TOWER2];
	exits[4].destination = &castlerooms[WESTCORRIDOR];
	exits[4].direction = North;
	//East
	exits[5].name = "South corridor door.";
	exits[5].description = "There's a corridor, the south one.";
	exits[5].origin = &castlerooms[TOWER2];
	exits[5].destination = &castlerooms[SOUTHCORRIDOR];
	exits[5].direction = East;
	//South
	exits[6].name = "Wall.";
	exits[6].description = "There's a wall.";
	exits[6].origin = &castlerooms[TOWER2];
	exits[6].destination = &castlerooms[TOWER2];
	exits[6].direction = South;
	//West
	exits[7].name = "Wall.";
	exits[7].description = "There's a wall.";
	exits[7].origin = &castlerooms[TOWER2];
	exits[7].destination = &castlerooms[TOWER2];
	exits[7].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 3
	castlerooms[TOWER3].name = "Tower 3";
	castlerooms[TOWER3].description = "In this tower there is a fireplace and a cupboard.";
	castlerooms[TOWER3].cupboard = true;
	//North
	exits[8].name = "Wall.";
	exits[8].description = "There's a fireplace.";
	exits[8].origin = &castlerooms[TOWER3];
	exits[8].destination = &castlerooms[TOWER3];
	exits[8].direction = North;
	//East
	exits[9].name = "North corridor door.";
	exits[9].description = "There's a corridor, the north one.";
	exits[9].origin = &castlerooms[TOWER3];
	exits[9].destination = &castlerooms[NORTHCORRIDOR];
	exits[9].direction = East;
	//South
	exits[10].name = "West corridor door.";
	exits[10].description = "There's a corridor, the west one.";
	exits[10].origin = &castlerooms[TOWER3];
	exits[10].destination = &castlerooms[WESTCORRIDOR];
	exits[10].direction = South;
	//West
	exits[11].name = "Wall.";
	exits[11].description = "There's a wall with a cupboard.";
	exits[11].origin = &castlerooms[TOWER3];
	exits[11].destination = &castlerooms[TOWER3];
	exits[11].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 4
	castlerooms[TOWER4].name = "Tower 4";
	castlerooms[TOWER4].description = "In this tower there is a cupboard.";
	castlerooms[TOWER4].cupboard = true;
	//North
	exits[12].name = "Wall.";
	exits[12].description = "There's a wall.";
	exits[12].origin = &castlerooms[TOWER4];
	exits[12].destination = &castlerooms[TOWER4];
	exits[12].direction = North;
	//East
	exits[13].name = "Wall.";
	exits[13].description = "There's a cupboard that seems that it could be oppened.";
	exits[13].origin = &castlerooms[TOWER4];
	exits[13].destination = &castlerooms[TOWER4];
	exits[13].direction = East;
	//South
	exits[14].name = "Wall.";
	exits[14].description = "There's a wall.";
	exits[14].origin = &castlerooms[TOWER4];
	exits[14].destination = &castlerooms[TOWER4];
	exits[14].direction = South;
	//West
	exits[15].name = "North corridor door.";
	exits[15].description = "There's a corridor, the north one.";
	exits[15].origin = &castlerooms[TOWER4];
	exits[15].destination = &castlerooms[NORTHCORRIDOR];
	exits[15].direction = West;
	exits[15].door = true;
	exits[15].close = true;
	// ---------------------------------------------------------------------------------------------------------------
	// North Corridor
	castlerooms[NORTHCORRIDOR].name = "North corridor";
	castlerooms[NORTHCORRIDOR].description = "Nothing interesting in here.";
	//North
	exits[16].name = "Wall.";
	exits[16].description = "There's a wall.";
	exits[16].origin = &castlerooms[NORTHCORRIDOR];
	exits[16].destination = &castlerooms[NORTHCORRIDOR];
	exits[16].direction = North;
	//East
	exits[17].name = "Tower 4 door.";
	exits[17].description = "There is the tower 4.";
	exits[17].origin = &castlerooms[NORTHCORRIDOR];
	exits[17].destination = &castlerooms[TOWER4];
	exits[17].direction = East;
	exits[17].door = true;
	exits[17].close = true;
	//South
	exits[18].name = "Throne room door.";
	exits[18].description = "There is a room, the throne room.";
	exits[18].origin = &castlerooms[NORTHCORRIDOR];
	exits[18].destination = &castlerooms[THRONEROOM];
	exits[18].direction = South;
	//West
	exits[19].name = "Tower 3 door.";
	exits[19].description = "There is the tower 3.";
	exits[19].origin = &castlerooms[NORTHCORRIDOR];
	exits[19].destination = &castlerooms[TOWER3];
	exits[19].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// East Corridor
	castlerooms[EASTCORRIDOR].name = "East corridor";
	castlerooms[EASTCORRIDOR].description = "In this corridor there's a cupboard.";
	castlerooms[EASTCORRIDOR].cupboard = true;
	//North
	exits[20].name = "Wall.";
	exits[20].description = "There's a wall.";
	exits[20].origin = &castlerooms[EASTCORRIDOR];
	exits[20].destination = &castlerooms[EASTCORRIDOR];
	exits[20].direction = North;
	//East
	exits[21].name = "Wall.";
	exits[21].description = "There's a cupboard that seems that it could be oppened.";
	exits[21].origin = &castlerooms[EASTCORRIDOR];
	exits[21].destination = &castlerooms[EASTCORRIDOR];
	exits[21].direction = East;
	//South
	exits[22].name = "Tower 1 door.";
	exits[22].description = "There is the tower 1.";
	exits[22].origin = &castlerooms[EASTCORRIDOR];
	exits[22].destination = &castlerooms[TOWER1];
	exits[22].direction = South;
	//West
	exits[23].name = "Throne room door.";
	exits[23].description = "There is a room, the throne room.";
	exits[23].origin = &castlerooms[EASTCORRIDOR];
	exits[23].destination = &castlerooms[THRONEROOM];
	exits[23].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// South Corridor
	castlerooms[SOUTHCORRIDOR].name = "South corridor";
	castlerooms[SOUTHCORRIDOR].description = "In this corridor there's a cupboard.";
	castlerooms[SOUTHCORRIDOR].cupboard = true;
	//North
	exits[24].name = "Wall.";
	exits[24].description = "There's a wall.";
	exits[24].origin = &castlerooms[SOUTHCORRIDOR];
	exits[24].destination = &castlerooms[SOUTHCORRIDOR];
	exits[24].direction = North;
	//East
	exits[25].name = "Tower 1 door.";
	exits[25].description = "There is the tower 1.";
	exits[25].origin = &castlerooms[SOUTHCORRIDOR];
	exits[25].destination = &castlerooms[TOWER1];
	exits[25].direction = East;
	//South
	exits[26].name = "Wall.";
	exits[26].description = "There's a cupboard that seems that it could be oppened.";
	exits[26].origin = &castlerooms[SOUTHCORRIDOR];
	exits[26].destination = &castlerooms[SOUTHCORRIDOR];
	exits[26].direction = South;
	//West
	exits[27].name = "Tower 2 door.";
	exits[27].description = "There is the tower 2.";
	exits[27].origin = &castlerooms[SOUTHCORRIDOR];
	exits[27].destination = &castlerooms[TOWER2];
	exits[27].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// West Corridor
	castlerooms[WESTCORRIDOR].name = "West corridor";
	castlerooms[WESTCORRIDOR].description = "In this corridor there's a table with a cupboard.";
	castlerooms[WESTCORRIDOR].cupboard = true;
	//North
	exits[28].name = "Tower 2 door.";
	exits[28].description = "There is the tower 2.";
	exits[28].origin = &castlerooms[WESTCORRIDOR];
	exits[28].destination = &castlerooms[TOWER3];
	exits[28].direction = North;
	//East
	exits[29].name = "Throne room door.";
	exits[29].description = "There is a room, the throne room.";
	exits[29].origin = &castlerooms[WESTCORRIDOR];
	exits[29].destination = &castlerooms[THRONEROOM];
	exits[29].direction = East;
	//South
	exits[30].name = "Tower 3 door.";
	exits[30].description = "There is the tower 3.";
	exits[30].origin = &castlerooms[WESTCORRIDOR];
	exits[30].destination = &castlerooms[TOWER2];
	exits[30].direction = South;
	//West
	exits[31].name = "Wall.";
	exits[31].description = "There's a cupboard that seems that it could be oppened.";
	exits[31].origin = &castlerooms[WESTCORRIDOR];
	exits[31].destination = &castlerooms[WESTCORRIDOR];
	exits[31].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// Throne Room
	castlerooms[THRONEROOM].name = "Throne room";
	castlerooms[THRONEROOM].description = "This is the mighty throne room of the king, people say that the treasure is hidden here.";
	castlerooms[THRONEROOM].cupboard = true;
	//North
	exits[32].name = "North corridor door.";
	exits[32].description = "There's a corridor, the north one.";
	exits[32].origin = &castlerooms[THRONEROOM];
	exits[32].destination = &castlerooms[NORTHCORRIDOR];
	exits[32].direction = North;
	//East
	exits[33].name = "East corridor door.";
	exits[33].description = "There's a corridor, the east one.";
	exits[33].origin = &castlerooms[THRONEROOM];
	exits[33].destination = &castlerooms[EASTCORRIDOR];
	exits[33].direction = East;
	//South
	exits[34].name = "Wall.";
	exits[34].description = "There's a wall with a portrait of the king.";
	exits[34].origin = &castlerooms[THRONEROOM];
	exits[34].destination = &castlerooms[THRONEROOM];
	exits[34].direction = South;
	//West
	exits[35].name = "West corridor door.";
	exits[35].description = "There's a corridor, the west one.";
	exits[35].origin = &castlerooms[THRONEROOM];
	exits[35].destination = &castlerooms[WESTCORRIDOR];
	exits[35].direction = West;
	// ---------------------------------------------------------------------------------------------------------------

	// ---------------------------------------------------------------------------------------------------------------
	// Items
	// ---------------------------------------------------------------------------------------------------------------
	// Katana
	items[0].name = "Rusty Katana";
	items[0].description = "This is the ancient rusty katana of a japanese guy, but still sharpened.";
	items[0].attack = 35;
	items[0].defense = 0;
	items[0].uses = 1000;
	items[0].item_room = &castlerooms[SOUTHCORRIDOR];
	items[0].item_exit = &exits[26];
	items[0].equipable = true;
	// Gas Mask
	items[1].name = "Gas Mask";
	items[1].description = "This gas mask can save you from toxic gases.";
	items[1].attack = 0;
	items[1].defense = 0;
	items[1].uses = 1000;
	items[1].item_room = &castlerooms[WESTCORRIDOR];
	items[1].item_exit = &exits[31];
	items[1].equipable = true;
	// Treasure
	items[2].name = "Treasure";
	items[2].description = "Your goal, the mighty treasure of the king.";
	items[2].attack = 0;
	items[2].defense = 0;
	items[2].uses = 0;
	items[2].item_room = &castlerooms[THRONEROOM];
	items[2].item_exit = &exits[34];
	// Venom Gas Granade
	items[3].name = "Venom Gas Granade";
	items[3].description = "Usefull against big groups of enemies, but you should search a gas mask to use it safely.";
	items[3].attack = 100;
	items[3].defense = 0;
	items[3].uses = 2;
	items[3].item_room = &castlerooms[EASTCORRIDOR];
	items[3].item_exit = &exits[21];
	// Sword
	items[4].name = "Sword";
	items[4].description = "Fullmetal sharpened sword, kill enemies with 2 hits.";
	items[4].attack = 50;
	items[4].defense = 0;
	items[4].uses = 1000;
	items[4].item_room = &castlerooms[TOWER3];
	items[4].item_exit = &exits[11];
	items[4].equipable = true;
	// Shield
	items[5].name = "Shield";
	items[5].description = "Protect you from enemy attacks.";
	items[5].attack = 0;
	items[5].defense = 75;
	items[5].uses = 1000;
	items[5].item_room = &castlerooms[TOWER3];
	items[5].item_exit = &exits[11];
	items[5].equipable = true;
	// Explosive
	items[6].name = "Explosive";
	items[6].description = "You can blow the treasure wall with that.";
	items[6].attack = 1000;
	items[6].defense = 0;
	items[6].uses = 1000;
	items[6].item_room = &castlerooms[TOWER4];
	items[6].item_exit = &exits[13];
	// Key
	items[6].name = "Explosive";
	items[6].description = "You can blow the treasure wall with that.";
	items[6].attack = 1000;
	items[6].defense = 0;
	items[6].uses = 1000;
	items[6].item_room = &castlerooms[TOWER4];
	items[6].item_exit = &exits[13];
}