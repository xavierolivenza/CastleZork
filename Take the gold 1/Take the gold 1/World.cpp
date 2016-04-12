#include <stdio.h>
#include <stdlib.h>
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
}

void World::dropeditemslook()const{
	int j = 0, i = 0;
	for (j = 0; j < NUMITEMS; j++){//see if in the room there are objects
		if ((items[j].item_room == player->current_room) && items[j].inventory == false){
			i++;
		}
	}
	if (i != 0){//if ther are, write their names
		printf("Item/s in this room(dropped or inside cupboards, search for it/them):\n");
		for (j = 0; j < NUMITEMS; j++){
			if ((items[j].item_room == player->current_room) && items[j].inventory == false){
				printf("%s\n", items[j].name);
			}
		}
	}
}

void World::executecommand1word(const int command1, int& actual_position)const{
	int exitnum = 0, roomnum = 0;
	int i = 0, j = 0;
	player->current_room = &castlerooms[actual_position];
	if ((command1 == NORTH) || (command1 == EAST) || (command1 == SOUTH) || (command1 == WEST)){
		for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
			if (exitnum % 4 == (command1 - 6)){
				//NORTH=6, 6-6=0, exitnum % 4 == 0
				//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
				//EAST=7, 6-6=0, exitnum % 4 == 1
				//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
				//SOUTH=8, 6-6=0, exitnum % 4 == 2
				//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
				//WEST=9, 6-6=0, exitnum % 4 == 3
				//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
				if (exits[exitnum].origin == player->current_room){
					for (roomnum = 0; roomnum < NUMROOMS; roomnum++){//Check rooms to get the room num for actual_position
						if (exits[exitnum].destination == &castlerooms[roomnum]){
							if (exits[exitnum].door == true && exits[exitnum].close == true){
								printf("Locked door.\n");
								return;
							}
							else{
								actual_position = roomnum;
								player->current_room = exits[exitnum].destination;
								printf("Now you are in %s\n", player->current_room->name.c_str());
								return;
							}
						}
					}
				}
			}
		}
		printf("There is a wall.\n");
	}
	if (command1 == LOOK){
		printf("%s\n\n", castlerooms[actual_position].description.c_str());
	}
	else if (command1 == STATS){
		printf("Player Stats:\nHP:%i\nAttack:%i\nDefense:%i\n", player->playerhp, player->playerattack, player->playerdefense);
	}
	else if (command1 == INVENTORY){
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c Player Inventory:          %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		for (i = 0; i <= 8; i++){
			if (items[i].inventory == true){
				printf("%c %s", 186, items[i].name.c_str());
				j++;
				/*
				for (i = 0; items[i].name.length() <= 20; i++){
					printf(" ");
				}
				printf("%c\n", 186);
				*/
			}
		}
		if (j == 0){
			printf("%c Nothing in the inventory.  %c\n", 186, 186);
		}
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}
	else if (command1 == EQUIPPED){
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c Player Equipped stuff:     %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		for (i = 0; i <= 8; i++){
			if (items[i].equipped == true){
				printf("%c %s", 186, items[i].name.c_str());
				j++;
				/*
				for (i = 0; items[i].name.length() <= 20; i++){
					printf(" ");
				}
				printf("%c\n", 186);
				*/
			}
		}
		if (j == 0){
			printf("%c Nothing in the inventory.  %c\n", 186, 186);
		}
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}
	else if (command1 == CLEAR){
		system("cls");
	}
	else if (command1 == QUIT){

	}
	else if (command1 == HELP){
		printf("You can move using:\n\tn/s/e/w\n\tnorth/east/south/west\n\tgo north/east/south/west/n/s/e/w\nAlso you can use the commands:\n\tlook/l -> to see the description of the room where you are\n\tlook/l + north/east/south/west/n/s/e/w -> to see the description of the\n\tpath\n\topen/close + north/east/south/west/n/s/e/w -> to open/close door\n\tpick + item name -> you can pick items from the ground\n\tdrop + item name -> you can drop items to the ground\n\tequip + item name -> you can equip items\n\tunequip + item name -> you can unequip items\n\tput + item name + into + cupboard -> put item in the cupboard\n\tget + item name + from + cupboard -> get the item from the cupboard\n\tequipped -> to see the objects that the player has equipped\n\tinventory/inv/i -> to see player inventory\n\tstats -> to see player stats\n\thelp/h -> to open the help menu\n\tquit/q -> to quit the game\n\n");
	}
	else{
		printf("That's not a valid command.\n");
	}
}

void World::executecommand2words(const int command1, const int command2, int& actual_position)const{
	int exitnum = 0, roomnum = 0;
	int exitnumdoors = 0, roomnumdoors = 0;
	int opositeroom = 0;
	player->current_room = &castlerooms[actual_position];
	// ---------------------------------------------------------------------------------------------------------------
	if (command1 == LOOK){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == command2 - 6){
					//NORTH=6, 6-6=0, exitnum % 4 == 0
					//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
					//EAST=7, 6-6=0, exitnum % 4 == 1
					//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
					//SOUTH=8, 6-6=0, exitnum % 4 == 2
					//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
					//WEST=9, 6-6=0, exitnum % 4 == 3
					//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
					if (exits[exitnum].origin == player->current_room){
						printf("%s\n", exits[exitnum].description.c_str());
						return;
					}
				}
			}
		}
		else if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE)){
			if ((items[command2 - 21].inventory == true) && items[command2 - 21].equipped == true){//If the player have it
				printf("%s is in the inventory and equipped.\n%s\n", items[command2 - 21].name.c_str(), items[command2 - 21].description.c_str());
			}
			else if ((items[command2 - 21].inventory == true) && items[command2 - 21].equipped == false){//If the player have it
				printf("%s is in the inventory and not equipped.\n%s\n", items[command2 - 21].name.c_str(), items[command2 - 21].description.c_str());
			}
			else{
				printf("You don't have this item.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == GO){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == command2 - 6){
					//NORTH=6, 6-6=0, exitnum % 4 == 0
					//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
					//EAST=7, 6-6=0, exitnum % 4 == 1
					//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
					//SOUTH=8, 6-6=0, exitnum % 4 == 2
					//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
					//WEST=9, 6-6=0, exitnum % 4 == 3
					//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
					if (exits[exitnum].origin == player->current_room){
						for (roomnum = 0; roomnum < NUMROOMS; roomnum++){//Check rooms to get the room num for actual_position
							if (exits[exitnum].destination == &castlerooms[roomnum]){
								if (exits[exitnum].door == true && exits[exitnum].close == true){
									printf("Locked door.\n");
									return;
								}
								else{
									actual_position = roomnum;
									player->current_room = exits[exitnum].destination;
									printf("Now you are in %s\n", player->current_room->name.c_str());
									return;
								}
							}
						}
					}
				}

			}
			printf("There is a wall.\n");
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == OPEN){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exits[exitnum].origin->name == player->current_room->name){
					if (exitnum % 4 == command2 - 6){
						//NORTH=6, 6-6=0, exitnum % 4 == 0
						//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
						//EAST=7, 6-6=0, exitnum % 4 == 1
						//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
						//SOUTH=8, 6-6=0, exitnum % 4 == 2
						//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
						//WEST=9, 6-6=0, exitnum % 4 == 3
						//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
						if (exits[exitnum].door == true){//check if there's a door
							if (exits[exitnum].close == true){
								exits[exitnum].close = false;//open the door of the current room
								for (exitnumdoors = 0; exitnumdoors < NUMEXITS; exitnumdoors++){
									if ((command2 == NORTH) || (command2 == EAST)){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = false;//open the door of the next room
												printf("The door is opened.\n");
												return;
											}
										}
									}
									else if ((command2 == SOUTH) || (command2 == WEST)){
										if ((exitnumdoors % 4) == (command2 - 8)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = false;//open the door of the next room
												printf("The door is opened.\n");
												return;
											}
										}
									}
								}
							}
							else{
								printf("The door was already opened.\n");
								break;
							}
						}
						else{
							printf("There is not a door here.\n");
							break;
						}
					}
				}
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == CLOSE){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exits[exitnum].origin->name == player->current_room->name){
					if (exitnum % 4 == command2 - 6){
						//NORTH=6, 6-6=0, exitnum % 4 == 0
						//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
						//EAST=7, 6-6=0, exitnum % 4 == 1
						//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
						//SOUTH=8, 6-6=0, exitnum % 4 == 2
						//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
						//WEST=9, 6-6=0, exitnum % 4 == 3
						//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
						if (exits[exitnum].door == true){//check if there's a door
							if (exits[exitnum].close == false){
								exits[exitnum].close = true;//close the door of the current room
								for (exitnumdoors = 0; exitnumdoors < NUMEXITS; exitnumdoors++){
									if ((command2 == NORTH) || (command2 == EAST)){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = true;//open the door of the next room
												printf("The door is closed.\n");
												return;
											}
										}
									}
									else if ((command2 == SOUTH) || (command2 == WEST)){
										if ((exitnumdoors % 4) == (command2 - 8)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = true;//open the door of the next room
												printf("The door is closed.\n");
												return;
											}
										}
									}
								}
							}
							else{
								printf("The door was already closed.\n");
								break;
							}
						}
						else{
							printf("There is not a door here.\n");
							break;
						}
					}
				}
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == PICK){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE)){
			if (items[command2 - 21].item_room == player->current_room){//Looks if the player is in the same room of the item.
				if (items[command2 - 21].inside_cupboard == false){
					if (items[command2 - 21].inventory == false){//If the player don't have it
						items[command2 - 21].inventory = true;
						items[command2 - 21].inside_cupboard = false;
						printf("Now you have %s.\n", items[command2 - 21].name);
					}
					else{
						printf("You already have this item.\n");
					}
				}
				else{
					printf("This object is inside a cupboard.\n");
				}
			}
			else{
				printf("That item is not here.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == DROP){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE)){
			if (items[command2 - 21].inventory == true){//If the player have it
				items[command2 - 21].inventory = false;
				items[command2 - 21].item_room = player->current_room;
				items[command2 - 21].inside_cupboard = false;
				printf("You had dropped %s.\n", items[command2 - 21].name);
			}
			else{
				printf("You don't have this item.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == EQUIP){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE)){
			if (items[command2 - 21].inventory == true){//If the player have it
				if (items[command2 - 21].equipable == true){
					if (items[command2 - 21].equipped == false){
						if ((command2 == KATANA) && (items[SWORD - 21].equipped == true)){//if you want to equip katana and you have sword equipped
							//equip katana
							items[command2 - 21].equipped = true;
							player->playerattack += items[command2 - 21].attack;
							player->playerdefense += items[command2 - 21].defense;
							printf("%s equipped.\n", items[command2 - 21].name.c_str());
							//unequip sword
							items[SWORD - 21].equipped = false;
							player->playerattack -= items[SWORD - 21].attack;
							player->playerdefense -= items[SWORD - 21].defense;
							printf("%s unequipped.\n", items[SWORD - 21].name.c_str());
						}
						else if (((command2) == SWORD) && (items[KATANA - 21].equipped == true)){//if you want to equip sword and you have katana equipped
							//equip sword
							items[command2 - 21].equipped = true;
							player->playerattack += items[command2 - 21].attack;
							player->playerdefense += items[command2 - 21].defense;
							printf("%s equipped.\n", items[command2 - 21].name.c_str());
							//unequip katana
							items[KATANA - 21].equipped = false;
							player->playerattack -= items[KATANA - 21].attack;
							player->playerdefense -= items[KATANA - 21].defense;
							printf("%s unequipped.\n", items[KATANA - 21].name.c_str());
						}
						else{
							items[command2 - 21].equipped = true;
							player->playerattack += items[command2 - 21].attack;
							player->playerdefense += items[command2 - 21].defense;
							printf("%s equipped.\n", items[command2 - 21].name.c_str());
						}
					}
					else{
						printf("You have already equipped this item.\n");
					}
				}
				else{
					printf("This item is not equipable.\n");
				}
			}
			else{
				printf("You don't have this item.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == UNEQUIP){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE)){
			if (items[command2 - 21].equipped == true){//If the player have it
				items[command2 - 21].equipped = false;
				player->playerattack -= items[command2 - 21].attack;
				player->playerdefense -= items[command2 - 21].defense;
				printf("%s unequipped.\n", items[command2 - 21].name.c_str());
			}
			else{
				printf("You don't have this item.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
}

void World::executecommand4words(const int command1, const int command2, const int command3, const int command4, int& actual_position)const{
	if (command1 == PUT){
		if (((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE)) && (command3 == INTO) && (command4 == CUPBOARD)){
			if (player->current_room->cupboard == true){//looks if the player room has a cupboard and player has the item
				if (items[command2 - 21].inventory == true){
					if (items[command2 - 21].equipped == true){//If the player have it equipped
						items[command2 - 21].equipped = false;//unequip
						player->playerattack -= items[command2 - 21].attack;
						player->playerdefense -= items[command2 - 21].defense;
					}
					items[command2 - 21].inventory = false;
					items[command2 - 21].inside_cupboard = true;
					items[command2 - 21].item_room = player->current_room;
					printf("You had put a %s inside the cupboard.\n", items[command2 - 21].name.c_str());
				}
				else{
					printf("You don't have it.\n");
				}
			}
			else{
				printf("There's not a cupboard here.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == GET){
		if (((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE)) && (command3 == FROM) && (command4 == CUPBOARD)){
			if (player->current_room->cupboard == true){//looks if the player room has a cupboard and player has the item
				if (items[command2 - 21].inside_cupboard == true){
					if (items[command2 - 21].inventory == false){
						items[command2 - 21].inventory = true;
						items[command2 - 21].inside_cupboard = false;
						printf("You had put a %s inside your inventory.\n", items[command2 - 21].name.c_str());
					}
					else{
						printf("You have it.\n");
					}
				}
				else{
					printf("This item is not inside a cupboard.\n");
				}
			}
			else{
				printf("There's not a cupboard here.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
}