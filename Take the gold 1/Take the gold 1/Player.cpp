#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Player.h"
#include "World.h"
#include "Exits.h"

Player::Player(){
}

Player::~Player(){
}

int Player::check_firstcommand(const String& firstcommand)const{
	if ((firstcommand == "look") || (firstcommand == "l")){
		return LOOK;
	}
	else if (firstcommand == "go"){
		return GO;
	}
	else if (firstcommand == "open"){
		return OPEN;
	}
	else if (firstcommand == "close"){
		return CLOSE;
	}
	else if ((firstcommand == "quit") || (firstcommand == "q")){
		return QUIT;
	}
	else if ((firstcommand == "help") || (firstcommand == "h")){
		return HELP;
	}
	// ---------------------------------------------------------------------------------------------------------------
	//Detection commands with 1 word
	else if ((firstcommand == "north") || (firstcommand == "n")){
		return NORTH;
	}
	else if ((firstcommand == "east") || (firstcommand == "e")){
		return EAST;
	}
	else if ((firstcommand == "south") || (firstcommand == "s")){
		return SOUTH;
	}
	else if ((firstcommand == "west") || (firstcommand == "w")){
		return WEST;
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (firstcommand == "pick"){
		return PICK;
	}
	else if (firstcommand == "drop"){
		return DROP;
	}
	else if ((firstcommand == "inventory") || (firstcommand == "inv") || (firstcommand == "i")){
		return INVENTORY;
	}
	else if (firstcommand == "equipped"){
		return EQUIPPED;
	}
	else if (firstcommand == "equip"){
		return EQUIP;
	}
	else if (firstcommand == "unequip"){
		return UNEQUIP;
	}
	else if (firstcommand == "put"){
		return PUT;
	}
	else if (firstcommand == "get"){
		return GET;
	}
	else if (firstcommand == "stats"){
		return STATS;
	}
	else if ((firstcommand == "clear") || (firstcommand == "c")){
		return CLEAR;
	}
	else if (firstcommand == "backpacked"){
		return BACKPACKED;
	}
	else{
		return ERROR;
	}
}

int Player::check_secondcommand(const String& secondcommand)const{
	if ((secondcommand == "north") || (secondcommand == "n")){
		return NORTH;
	}
	else if ((secondcommand == "east") || (secondcommand == "e")){
		return EAST;
	}
	else if ((secondcommand == "south") || (secondcommand == "s")){
		return SOUTH;
	}
	else if ((secondcommand == "west") || (secondcommand == "w")){
		return WEST;
	}
	if (secondcommand == "rusty katana"){
		return KATANA;
	}
	else if (secondcommand == "gas mask"){
		return GASMASK;
	}
	else if (secondcommand == "treasure"){
		return TREASURE;
	}
	else if (secondcommand == "venom gas grenade"){
		return GRENADE;
	}
	else if (secondcommand == "sword"){
		return SWORD;
	}
	else if (secondcommand == "shield"){
		return SHIELD;
	}
	else if (secondcommand == "explosive"){
		return EXPLOSIVE;
	}
	else if (secondcommand == "key"){
		return KEY;
	}
	else if (secondcommand == "backpack"){
		return BACKPACK;
	}
	else{
		return ERROR;
	}
}

int Player::check_thirdcommand(const String& firstcommand, const String& thirdcommand)const{
	if ((firstcommand == "put") && (thirdcommand == "into")){
		return INTO;
	}
	else if ((firstcommand == "get") && (thirdcommand == "from")){
		return FROM;
	}
	else{
		return ERROR;
	}
}

int Player::check_fourthcommand(const String& fourthcommand)const{
	if (fourthcommand == "cupboard"){
		return CUPBOARD;
	}
	else if (fourthcommand == "backpack"){
		return BACKPACK;
	}
	else{
		return ERROR;
	}
}

int Player::check_numcommands(const String& firstcommand, const String& secondcommand, const String& thirdcommand, const String& fourthcommand)const{
	int command_words = 0;
	if (firstcommand.c_capacity() != 1){
		command_words++;
		if (secondcommand.c_capacity() != 1){
			command_words++;
			if (thirdcommand.c_capacity() != 1){
				command_words++;
				if (fourthcommand.c_capacity() != 1){
					command_words++;
				}
			}
		}
	}
	return command_words;
}

void Player::dropeditemslook()const{
	int j = 0, i = 0;
	for (j = 0; j < NUMITEMS; j++){//see if in the room there are objects
		if ((worldexternpointer->items[j]->item_room == worldexternpointer->player->current_room) && worldexternpointer->items[j]->inventory == false){
			i++;
		}
	}
	if (i != 0){//if ther are, write their names
		printf("Item/s in this room(dropped or inside cupboards, search for it/them):\n");
		for (j = 0; j < NUMITEMS; j++){
			if ((worldexternpointer->items[j]->item_room == worldexternpointer->player->current_room) && worldexternpointer->items[j]->inventory == false){
				printf("%s\n", worldexternpointer->items[j]->name.c_str());
			}
		}
	}
}

void Player::executecommand1word(const int command1, int& actual_position)const{
	int exitnum = 0, roomnum = 0;
	int i = 0, j = 0, k = 0;
	worldexternpointer->player->current_room = worldexternpointer->castlerooms[actual_position];
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
				if (worldexternpointer->exits[exitnum]->origin == worldexternpointer->player->current_room){
					for (roomnum = 0; roomnum < NUMROOMS; roomnum++){//Check rooms to get the room num for actual_position
						if (worldexternpointer->exits[exitnum]->destination == worldexternpointer->castlerooms[roomnum]){
							if (worldexternpointer->exits[exitnum]->door == true && worldexternpointer->exits[exitnum]->close == true){
								printf("Locked door.\n");
								return;
							}
							else{
								actual_position = roomnum;
								worldexternpointer->player->current_room = worldexternpointer->exits[exitnum]->destination;
								printf("Now you are in %s\n", worldexternpointer->player->current_room->name.c_str());
								return;
							}
						}
					}
				}
			}
		}
		printf("There is a wall.\n");
	}
	else if (command1 == LOOK){
		printf("%s\n\n", worldexternpointer->castlerooms[actual_position]->description.c_str());
	}
	else if (command1 == STATS){
		printf("Player Stats:\nHP:%i\nAttack:%i\nDefense:%i\n", worldexternpointer->player->playerhp, worldexternpointer->player->playerattack, worldexternpointer->player->playerdefense);
	}
	else if (command1 == INVENTORY){
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c Player Inventory:          %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		for (i = 0; i < NUMITEMS; i++){
			if (worldexternpointer->items[i]->inventory == true){
				printf("%c %s", 186, worldexternpointer->items[i]->name.c_str());
				j++;
				for (k = worldexternpointer->items[i]->name.length(); k <= 26; k++){
				printf(" ");
				}
				printf("%c\n", 186);
			}
		}
		if (j == 0){
			printf("%c Nothing in the inventory.  %c\n", 186, 186);
		}
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}
	else if (command1 == BACKPACKED){
		if (worldexternpointer->items[BACKPACK - 22]->inventory == true){
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
			printf("%c Backpack Inventory:        %c\n", 186, 186);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
			for (i = 0; i < NUMITEMS; i++){
				if (worldexternpointer->items[i]->inside_backpack == true){
					printf("%c %s", 186, worldexternpointer->items[i]->name.c_str());
					j++;
					for (k = worldexternpointer->items[i]->name.length(); k <= 26; k++){
						printf(" ");
					}
					printf("%c\n", 186);
				}
			}
			if (j == 0){
				printf("%c Nothing in the box.        %c\n", 186, 186);
			}
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
		}
		else{
			printf("You don't have a backpack.\n");
		}
	}
	else if (command1 == EQUIPPED){
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c Player Equipped stuff:     %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		for (i = 0; i < NUMITEMS; i++){
			if (worldexternpointer->items[i]->equipped == true){
				printf("%c %s", 186, worldexternpointer->items[i]->name.c_str());
				j++;
				for (k = worldexternpointer->items[i]->name.length(); k <= 26; k++){
					printf(" ");
				}
				printf("%c\n", 186);
			}
		}
		if (j == 0){
			printf("%c Nothing in the inventory.  %c\n", 186, 186);
		}
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}
	else if (command1 == CLEAR){
		system("cls");
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c %c%c%c %c%c%c %c %c %c%c   %c%c%c %c %c %c%c   %c%c%c %c%c%c %c   %c%c  %c\n", 186, 196, 194, 196, 218, 196, 191, 179, 47, 218, 196, 196, 194, 196, 179, 179, 218, 196, 218, 196, 196, 218, 196, 191, 179, 218, 191, 186);
		printf("%c  %c  %c%c%c %c%c  %c%c    %c  %c%c%c %c%c   %c%c%c %c %c %c   %c %c %c\n", 186, 179, 195, 196, 195, 179, 180, 195, 196, 179, 195, 196, 180, 195, 196, 195, 196, 191, 179, 179, 179, 179, 179, 186);
		printf("%c  %c  %c %c %c %c %c%c    %c  %c %c %c%c   %c%c%c %c%c%c %c%c%c %c%c  %c\n", 186, 179, 179, 179, 179, 92, 192, 196, 179, 179, 179, 192, 196, 192, 196, 217, 192, 196, 217, 192, 196, 196, 192, 217, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
		printf("By Xavier Olivenza.\n");
	}
	else if (command1 == QUIT){

	}
	else if (command1 == HELP){
		printf("You can move using:\n\tn/s/e/w\n\tnorth/east/south/west\n\tgo north/east/south/west/n/s/e/w\nAlso you can use the commands:\n\tlook/l -> to see the description of the room where you are\n\tlook/l + north/east/south/west/n/s/e/w -> to see the description of the\n\tpath\n\topen/close + north/east/south/west/n/s/e/w -> to open/close door\n\tpick + item name -> you can pick items from the ground\n\tdrop + item name -> you can drop items to the ground\n\tequip + item name -> you can equip items\n\tunequip + item name -> you can unequip items\n\tput + item name + into + cupboard -> put item in the cupboard\n\tget + item name + from + cupboard -> get the item from the cupboard\n\tequipped -> to see the objects that the player has equipped\n\tinventory/inv/i -> to see player inventory\n\tstats -> to see player stats\n\tclear/c -> to clean the screen\n\thelp/h -> to open the help menu\n\tquit/q -> to quit the game\n\n");
	}
	else{
		printf("That's not a valid command.\n");
	}
}

void Player::executecommand2words(const int command1, const int command2, int& actual_position)const{
	int exitnum = 0, roomnum = 0;
	int exitnumdoors = 0, roomnumdoors = 0;
	int opositeroom = 0;
	worldexternpointer->player->current_room = worldexternpointer->castlerooms[actual_position];
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
					if (worldexternpointer->exits[exitnum]->origin == worldexternpointer->player->current_room){
						printf("%s\n", worldexternpointer->exits[exitnum]->description.c_str());
						return;
					}
				}
			}
		}
		else if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if ((worldexternpointer->items[command2 - 22]->inventory == true) && worldexternpointer->items[command2 - 22]->equipped == true){//If the player have it
				printf("%s is in the inventory and equipped.\n%s\nDamage:%i\nDefense:%i\n", worldexternpointer->items[command2 - 22]->name.c_str(), worldexternpointer->items[command2 - 22]->description.c_str(), worldexternpointer->items[command2 - 22]->attack, worldexternpointer->items[command2 - 22]->defense);
			}
			else if ((worldexternpointer->items[command2 - 22]->inventory == true) && worldexternpointer->items[command2 - 22]->equipped == false){//If the player have it
				printf("%s is in the inventory and not equipped.\n%s\nDamage:%i\nDefense:%i\n", worldexternpointer->items[command2 - 22]->name.c_str(), worldexternpointer->items[command2 - 22]->description.c_str(), worldexternpointer->items[command2 - 22]->attack, worldexternpointer->items[command2 - 22]->defense);
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
					if (worldexternpointer->exits[exitnum]->origin == worldexternpointer->player->current_room){
						for (roomnum = 0; roomnum < NUMROOMS; roomnum++){//Check rooms to get the room num for actual_position
							if (worldexternpointer->exits[exitnum]->destination == worldexternpointer->castlerooms[roomnum]){
								if (worldexternpointer->exits[exitnum]->door == true && worldexternpointer->exits[exitnum]->close == true){
									printf("Locked door.\n");
									return;
								}
								else{
									actual_position = roomnum;
									worldexternpointer->player->current_room = worldexternpointer->exits[exitnum]->destination;
									printf("Now you are in %s\n", worldexternpointer->player->current_room->name.c_str());
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
			if (worldexternpointer->items[KEY - 22]->inventory == true){
				for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
					if (worldexternpointer->exits[exitnum]->origin->name == worldexternpointer->player->current_room->name){
						if (exitnum % 4 == command2 - 6){
							//NORTH=6, 6-6=0, exitnum % 4 == 0
							//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
							//EAST=7, 6-6=0, exitnum % 4 == 1
							//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
							//SOUTH=8, 6-6=0, exitnum % 4 == 2
							//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
							//WEST=9, 6-6=0, exitnum % 4 == 3
							//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
							if (worldexternpointer->exits[exitnum]->door == true){//check if there's a door
								if (worldexternpointer->exits[exitnum]->close == true){
									worldexternpointer->exits[exitnum]->close = false;//open the door of the current room
									for (exitnumdoors = 0; exitnumdoors < NUMEXITS; exitnumdoors++){
										if ((command2 == NORTH) || (command2 == EAST)){
											if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
												if (worldexternpointer->exits[exitnumdoors]->destination->name == worldexternpointer->exits[exitnum]->origin->name){
													worldexternpointer->exits[exitnumdoors]->close = false;//open the door of the next room
													printf("The door is opened.\n");
													return;
												}
											}
										}
										else if ((command2 == SOUTH) || (command2 == WEST)){
											if ((exitnumdoors % 4) == (command2 - 8)){//Oposite room
												if (worldexternpointer->exits[exitnumdoors]->destination->name == worldexternpointer->exits[exitnum]->origin->name){
													worldexternpointer->exits[exitnumdoors]->close = false;//open the door of the next room
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
				printf("You don't have the key of this door.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == CLOSE){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			if (worldexternpointer->items[KEY - 22]->inventory == true){
				for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
					if (worldexternpointer->exits[exitnum]->origin->name == worldexternpointer->player->current_room->name){
						if (exitnum % 4 == command2 - 6){
							//NORTH=6, 6-6=0, exitnum % 4 == 0
							//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
							//EAST=7, 6-6=0, exitnum % 4 == 1
							//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
							//SOUTH=8, 6-6=0, exitnum % 4 == 2
							//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
							//WEST=9, 6-6=0, exitnum % 4 == 3
							//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
							if (worldexternpointer->exits[exitnum]->door == true){//check if there's a door
								if (worldexternpointer->exits[exitnum]->close == false){
									worldexternpointer->exits[exitnum]->close = true;//close the door of the current room
									for (exitnumdoors = 0; exitnumdoors < NUMEXITS; exitnumdoors++){
										if ((command2 == NORTH) || (command2 == EAST)){
											if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
												if (worldexternpointer->exits[exitnumdoors]->destination->name == worldexternpointer->exits[exitnum]->origin->name){
													worldexternpointer->exits[exitnumdoors]->close = true;//open the door of the next room
													printf("The door is closed.\n");
													return;
												}
											}
										}
										else if ((command2 == SOUTH) || (command2 == WEST)){
											if ((exitnumdoors % 4) == (command2 - 8)){//Oposite room
												if (worldexternpointer->exits[exitnumdoors]->destination->name == worldexternpointer->exits[exitnum]->origin->name){
													worldexternpointer->exits[exitnumdoors]->close = true;//open the door of the next room
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
				printf("You don't have the key of this door.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == PICK){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (worldexternpointer->items[command2 - 22]->item_room == worldexternpointer->player->current_room){//Looks if the player is in the same room of the item.
				if (worldexternpointer->items[command2 - 22]->inside_cupboard == false){
					if (worldexternpointer->items[command2 - 22]->inventory == false){//If the player don't have it
						worldexternpointer->items[command2 - 22]->inventory = true;
						worldexternpointer->items[command2 - 22]->inside_cupboard = false;
						printf("Now you have %s.\n", worldexternpointer->items[command2 - 22]->name.c_str());
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
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (worldexternpointer->items[command2 - 22]->inventory == true){//If the player have it
				worldexternpointer->items[command2 - 22]->inventory = false;
				worldexternpointer->items[command2 - 22]->item_room = worldexternpointer->player->current_room;
				worldexternpointer->items[command2 - 22]->inside_cupboard = false;
				printf("You had dropped %s.\n", worldexternpointer->items[command2 - 22]->name.c_str());
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
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (worldexternpointer->items[command2 - 22]->inventory == true){//If the player have it
				if (worldexternpointer->items[command2 - 22]->equipable == true){
					if (worldexternpointer->items[command2 - 22]->equipped == false){
						if ((command2 == KATANA) && (worldexternpointer->items[SWORD - 22]->equipped == true)){//if you want to equip katana and you have sword equipped
							//equip katana
							worldexternpointer->items[command2 - 22]->equipped = true;
							worldexternpointer->player->playerattack += worldexternpointer->items[command2 - 22]->attack;
							worldexternpointer->player->playerdefense += worldexternpointer->items[command2 - 22]->defense;
							printf("%s equipped.\n", worldexternpointer->items[command2 - 21]->name.c_str());
							//unequip sword
							worldexternpointer->items[SWORD - 22]->equipped = false;
							worldexternpointer->player->playerattack -= worldexternpointer->items[SWORD - 22]->attack;
							worldexternpointer->player->playerdefense -= worldexternpointer->items[SWORD - 22]->defense;
							printf("%s unequipped.\n", worldexternpointer->items[SWORD - 22]->name.c_str());
						}
						else if (((command2) == SWORD) && (worldexternpointer->items[KATANA - 22]->equipped == true)){//if you want to equip sword and you have katana equipped
							//equip sword
							worldexternpointer->items[command2 - 22]->equipped = true;
							worldexternpointer->player->playerattack += worldexternpointer->items[command2 - 22]->attack;
							worldexternpointer->player->playerdefense += worldexternpointer->items[command2 - 22]->defense;
							printf("%s equipped.\n", worldexternpointer->items[command2 - 22]->name.c_str());
							//unequip katana
							worldexternpointer->items[KATANA - 22]->equipped = false;
							worldexternpointer->player->playerattack -= worldexternpointer->items[KATANA - 22]->attack;
							worldexternpointer->player->playerdefense -= worldexternpointer->items[KATANA - 22]->defense;
							printf("%s unequipped.\n", worldexternpointer->items[KATANA - 22]->name.c_str());
						}
						else{
							worldexternpointer->items[command2 - 22]->equipped = true;
							worldexternpointer->player->playerattack += worldexternpointer->items[command2 - 22]->attack;
							worldexternpointer->player->playerdefense += worldexternpointer->items[command2 - 22]->defense;
							printf("%s equipped.\n", worldexternpointer->items[command2 - 22]->name.c_str());
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
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (worldexternpointer->items[command2 - 22]->equipped == true){//If the player have it
				worldexternpointer->items[command2 - 22]->equipped = false;
				worldexternpointer->player->playerattack -= worldexternpointer->items[command2 - 22]->attack;
				worldexternpointer->player->playerdefense -= worldexternpointer->items[command2 - 22]->defense;
				printf("%s unequipped.\n", worldexternpointer->items[command2 - 22]->name.c_str());
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

void Player::executecommand4words(const int command1, const int command2, const int command3, const int command4, int& actual_position)const{
	if (command1 == PUT){
		if (((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)) && (command3 == INTO)){
			if (command4 == CUPBOARD){
				if (worldexternpointer->player->current_room->cupboard == true){//looks if the player room has a cupboard and player has the item
					if (worldexternpointer->items[command2 - 22]->inventory == true){
						if (worldexternpointer->items[command2 - 22]->equipped == true){//If the player have it equipped
							worldexternpointer->items[command2 - 22]->equipped = false;//unequip
							worldexternpointer->player->playerattack -= worldexternpointer->items[command2 - 22]->attack;
							worldexternpointer->player->playerdefense -= worldexternpointer->items[command2 - 22]->defense;
						}
						worldexternpointer->items[command2 - 22]->inventory = false;
						worldexternpointer->items[command2 - 22]->inside_cupboard = true;
						worldexternpointer->items[command2 - 22]->item_room = worldexternpointer->player->current_room;
						printf("You had put %s inside the cupboard.\n", worldexternpointer->items[command2 - 22]->name.c_str());
					}
					else{
						printf("You don't have it.\n");
					}
				}
				else{
					printf("There's not a cupboard here.\n");
				}
			}
			else if (command4 == BACKPACK){
				if (command2 != command4){
					if (worldexternpointer->items[BACKPACK - 22]->inventory == true){
						if (worldexternpointer->items[command2 - 22]->inventory == true){
							if (worldexternpointer->items[command2 - 22]->equipped == true){//If the player have it equipped
								worldexternpointer->items[command2 - 22]->equipped = false;//unequip
								worldexternpointer->player->playerattack -= worldexternpointer->items[command2 - 22]->attack;
								worldexternpointer->player->playerdefense -= worldexternpointer->items[command2 - 22]->defense;
							}
							worldexternpointer->items[command2 - 22]->inventory = false;
							worldexternpointer->items[command2 - 22]->inside_backpack = true;
							printf("You had put %s inside the backpack.\n", worldexternpointer->items[command2 - 22]->name.c_str());
						}
						else{
							printf("You don't have this item in your inventory.\n");
						}
					}
					else{
						printf("You don't have a backpack.\n");
					}
				}
				else{
					printf("That is not possible, you want to break the space and time?\n");
				}
			}
			else{
				printf("That's not a valid command.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == GET){
		if (((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)) && (command3 == FROM)){
			if (command4 == CUPBOARD){
				if (worldexternpointer->player->current_room == worldexternpointer->items[command2 - 22]->item_room){
					if (worldexternpointer->player->current_room->cupboard == true){//looks if the player room has a cupboard and player has the item
						if (worldexternpointer->items[command2 - 22]->inside_cupboard == true){
							if (worldexternpointer->items[command2 - 22]->inventory == false){
								worldexternpointer->items[command2 - 22]->inventory = true;
								worldexternpointer->items[command2 - 22]->inside_cupboard = false;
								printf("You had put %s inside your inventory.\n", worldexternpointer->items[command2 - 22]->name.c_str());
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
					printf("You are not in the room where this item is.\n");
				}
			}
			else if (command4 == BACKPACK){
				if (command2 != command4){
					if (worldexternpointer->items[BACKPACK - 22]->inventory == true){
						if (worldexternpointer->items[command2 - 22]->inside_backpack == true){
							worldexternpointer->items[command2 - 22]->inventory = true;
							worldexternpointer->items[command2 - 22]->inside_backpack = false;
							printf("You had put %s inside the inventory.\n", worldexternpointer->items[command2 - 22]->name.c_str());
						}
						else{
							printf("You don't have this item in your backpack.\n");
						}
					}
					else{
						printf("You don't have a backpack.\n");
					}
				}
				else{
					printf("That is not possible, you want to break the space and time?\n");
				}
			}
			else{
				printf("That's not a valid command.1\n");
			}
		}
		else{
			printf("That's not a valid command.2\n");
		}
	}
}