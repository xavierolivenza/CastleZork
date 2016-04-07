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
	castlerooms[TOWER3].description = "In this tower there is a fireplace, probably something interesting is above it.";
	//North
	exits[8].name = "Wall.";
	exits[8].description = "There's a wall.";
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
	exits[11].description = "There's a wall with a sword and a shield hanging on the wall.";
	exits[11].origin = &castlerooms[TOWER3];
	exits[11].destination = &castlerooms[TOWER3];
	exits[11].direction = West;
	// ---------------------------------------------------------------------------------------------------------------
	// Tower 4
	castlerooms[TOWER4].name = "Tower 4";
	castlerooms[TOWER4].description = "In this tower there is a cupboard, probably something interesting is in there.";
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
	castlerooms[WESTCORRIDOR].description = "In this corridor there's a table.";
	//North
	exits[28].name = "Tower 2 door.";
	exits[28].description = "There is the tower 2.";
	exits[28].origin = &castlerooms[WESTCORRIDOR];
	exits[28].destination = &castlerooms[TOWER2];
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
	exits[34].description = "There's a wall with a canvas.";
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
	// Gas Mask
	items[1].name = "Gas Mask";
	items[1].description = "This gas mask can save you from toxic gases.";
	items[1].attack = 0;
	items[1].defense = 0;
	// Treasure
	items[2].name = "Treasure";
	items[2].description = "Your goal, the mighty treasure of the king.";
	items[2].attack = 0;
	items[2].defense = 0;
	// Venom Gas Granade 1
	items[3].name = "Venom Gas Granade";
	items[3].description = "Usefull against big groups of enemies, but you should search a gas mask.";
	items[3].attack = 100;
	items[3].defense = 0;
	// Venom Gas Granade 2
	items[4].name = "Venom Gas Granade";
	items[4].description = "Usefull against big groups of enemies, but you should search a gas mask.";
	items[4].attack = 100;
	items[4].defense = 0;
	// Sword
	items[5].name = "Sword";
	items[5].description = "Fullmetal sharpened sword, kill enemies with 2 hits.";
	items[5].attack = 50;
	items[5].defense = 0;
	// Shield
	items[6].name = "Shield";
	items[6].description = "Protect you from enemy attacks.";
	items[6].attack = 0;
	items[6].defense = 75;
	// Explosive
	items[7].name = "Explosive";
	items[7].description = "You can blow the treasure wall with that.";
	items[7].attack = 1000;
	items[7].defense = 0;
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
		printf("Player Inventory:\n");
		for (i = 0; i <= 8; i++){
			if (items[i].inventory == true){
				printf("%s\n", items[i].name.c_str());
				j++;
			}
		}
		if (j != 0){
			printf("Nothing in the inventory.\n");
		}
	}
	else if (command1 == EQUIPED){
		printf("Player Equipped stuff:\n");
		for (i = 0; i <= 8; i++){
			if (items[i].equiped == true){
				printf("%s\n", items[i].name.c_str());
				j++;
			}
		}
		if (j != 0){
			printf("Nothing equiped.\n");
		}
	}
	else if (command1 == QUIT){

	}
	else if (command1 == HELP){
		printf("In this game you can move using:\nn/s/e/w\nnorth/east/south/west\ngo north/go east/go south/go west\nAlso you can use the commands:\nlook->to see the description of the room where you are\nlook+north/east/south/west->to see the description of the path\nopen/close+north/east/south/west->to open/close door\nhelp/h->to see this page\nquit/q->to quit the game\n\n");
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
									if (command2 == NORTH){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = false;//open the door of the next room
												printf("The door is opened.\n");
												return;
											}
										}
									}
									else if (command2 == EAST){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = false;//open the door of the next room
												printf("The door is opened.\n");
												return;
											}
										}
									}
									else if (command2 == SOUTH){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = false;//open the door of the next room
												printf("The door is opened.\n");
												return;
											}
										}
									}
									else if (command2 == WEST){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
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
									if (command2 == NORTH){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = true;//open the door of the next room
												printf("The door is closed.\n");
												return;
											}
										}
									}
									else if (command2 == EAST){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = true;//open the door of the next room
												printf("The door is closed.\n");
												return;
											}
										}
									}
									else if (command2 == SOUTH){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
											if (exits[exitnumdoors].destination->name == exits[exitnum].origin->name){
												exits[exitnumdoors].close = true;//open the door of the next room
												printf("The door is closed.\n");
												return;
											}
										}
									}
									else if (command2 == WEST){
										if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
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
}