#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> //Sleep, this freeze the game X miliseconds, used in command use+explosive, for the countdown
#include "Player.h"
#include "World.h"
#include "Exits.h"

Player::Player(){
}

Player::Player(const char* name, const char* description, Room* initialroom, EntityType type): Creature(name, description, initialroom, type) {
}

Player::~Player(){
}

int Player::check_firstcommand(Vector <String> commands)const{
	//this method recibes the vector of commands and check the first one and return its value of the enum
	if ((commands[0] == "look") || (commands[0] == "l")){
		return LOOK;
	}
	else if (commands[0] == "go"){
		return GO;
	}
	else if (commands[0] == "open"){
		return OPEN;
	}
	else if (commands[0] == "close"){
		return CLOSE;
	}
	else if ((commands[0] == "quit") || (commands[0] == "q")){
		return QUIT;
	}
	else if ((commands[0] == "help") || (commands[0] == "h")){
		return HELP;
	}
	// ---------------------------------------------------------------------------------------------------------------
	//Detection commands with 1 word
	else if ((commands[0] == "north") || (commands[0] == "n")){
		return NORTH;
	}
	else if ((commands[0] == "east") || (commands[0] == "e")){
		return EAST;
	}
	else if ((commands[0] == "south") || (commands[0] == "s")){
		return SOUTH;
	}
	else if ((commands[0] == "west") || (commands[0] == "w")){
		return WEST;
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (commands[0] == "pick"){
		return PICK;
	}
	else if (commands[0] == "drop"){
		return DROP;
	}
	else if ((commands[0] == "inventory") || (commands[0] == "inv") || (commands[0] == "i")){
		return INVENTORY;
	}
	else if (commands[0] == "equipped"){
		return EQUIPPED;
	}
	else if (commands[0] == "equip"){
		return EQUIP;
	}
	else if (commands[0] == "unequip"){
		return UNEQUIP;
	}
	else if (commands[0] == "put"){
		return PUT;
	}
	else if (commands[0] == "get"){
		return GET;
	}
	else if (commands[0] == "stats"){
		return STATS;
	}
	else if (commands[0] == "flee"){
		return FLEE;
	}
	else if ((commands[0] == "clear") || (commands[0] == "c")){
		return CLEAR;
	}
	else if (commands[0] == "backpacked"){
		return BACKPACKED;
	}
	else if (commands[0] == "use"){
		return USE;
	}
	else if (commands[0] == "god"){
		return GOD;
	}
	else{
		return COMMANDERROR;
	}
}

int Player::check_secondcommand(Vector <String> commands)const{
	//this method recibes the vector of commands and check the second one and return its value of the enum
	if ((commands[1] == "north") || (commands[1] == "n")){
		return NORTH;
	}
	else if ((commands[1] == "east") || (commands[1] == "e")){
		return EAST;
	}
	else if ((commands[1] == "south") || (commands[1] == "s")){
		return SOUTH;
	}
	else if ((commands[1] == "west") || (commands[1] == "w")){
		return WEST;
	}
	if (commands[1] == "rusty katana"){
		return KATANA;
	}
	else if (commands[1] == "gas mask"){
		return GASMASK;
	}
	else if (commands[1] == "treasure"){
		return TREASURE;
	}
	else if (commands[1] == "venom gas grenade"){
		return GRENADE;
	}
	else if (commands[1] == "sword"){
		return SWORD;
	}
	else if (commands[1] == "shield"){
		return SHIELD;
	}
	else if (commands[1] == "explosive"){
		return EXPLOSIVE;
	}
	else if (commands[1] == "key"){
		return KEY;
	}
	else if (commands[1] == "backpack"){
		return BACKPACK;
	}
	else{
		return COMMANDERROR;
	}
}

int Player::check_thirdcommand(Vector <String> commands)const{
	//this method recibes the vector of commands and check the third one and return its value of the enum
	if ((commands[0] == "put") && (commands[2] == "into")){
		return INTO;
	}
	else if ((commands[0] == "get") && (commands[2] == "from")){
		return FROM;
	}
	else{
		return COMMANDERROR;
	}
}

int Player::check_fourthcommand(Vector <String> commands)const{
	//this method recibes the vector of commands and check the forth one and return its value of the enum
	if (commands[3] == "cupboard"){
		return CUPBOARD;
	}
	else if (commands[3] == "backpack"){
		return BACKPACK;
	}
	else{
		return COMMANDERROR;
	}
}

void Player::dropeditemslook()const{
	//this method see if there are items in the current room
	int j = 0, i = 0;
	for (j = 0; j < NUMITEMS; j++){//see if in the room there are objects
		if ((((Item*)worldexternpointer->entities[j + 9])->item_room == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room) && (((Item*)worldexternpointer->entities[j + 9])->inventory == false)){
			i++;
		}
	}
	if (i != 0){//if ther are, write their names
		printf("Item/s in this room(dropped or inside cupboards, search for it/them):\n");
		for (j = 0; j < NUMITEMS; j++){
			if ((((Item*)worldexternpointer->entities[j + 9])->item_room == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room) && ((Item*)worldexternpointer->entities[j + 9])->inventory == false){
				printf("%s\n", ((Item*)worldexternpointer->entities[j + 9])->name.c_str());
			}
		}
	}
}

void Player::executecommand1word(int& command1, int& actual_position)const{

	//this method executes the 1 word commands

	int exitnum = 0, roomnum = 0;
	int i = 0, j = 0, k = 0, l = 0, m = 0;
	((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room = ((Room*)worldexternpointer->entities[actual_position]);

	//movement commands
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
				if (((Exit*)worldexternpointer->entities[exitnum + 18])->origin == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room){
					for (roomnum = 0; roomnum < NUMROOMS; roomnum++){//Check rooms to get the room num for actual_position
						if (((Exit*)worldexternpointer->entities[exitnum + 18])->destination == ((Room*)worldexternpointer->entities[roomnum])){
							if (((Exit*)worldexternpointer->entities[exitnum + 18])->door == true && ((Exit*)worldexternpointer->entities[exitnum + 18])->close == true){
								printf("Locked door.\n");
								return;
							}
							else{
								actual_position = roomnum;
								((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room = ((Exit*)worldexternpointer->entities[exitnum + 18])->destination;
								printf("Now you are in %s\n", ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->name.c_str());
								return;
							}
						}
					}
				}
			}
		}
		printf("There is a wall.\n");
	}

	//look room command
	else if (command1 == LOOK){
		printf("%s\n\n", worldexternpointer->entities[actual_position]->description.c_str());
	}

	//stats command
	else if (command1 == STATS){
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c Player Stats: %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		// HP
		printf("%c HP:%i", 186, ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp);
		//This lines are for draw the box which contains stats
		if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp < 10){
			m = 1;
		}
		else if ((((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp >= 10) && (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp < 100)){
			m = 2;
		}
		else if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp == 100){
			m = 3;
		}
		else if ((((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp > 100) && (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp <= 1000)){
			m = 4;
		}
		for (l = m; l < 11; l++){
			printf(" ");
		}
		printf("%c\n", 186);

		// Attack
		printf("%c Attack:%i", 186, ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack);
		//This lines are for draw the box which contains stats
		if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack < 10){
			m = 1;
		}
		else if ((((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack >= 10) && (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack < 100)){
			m = 2;
		}
		else if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack == 100){
			m = 3;
		}
		else if ((((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack > 100) && (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack <= 1000)){
			m = 4;
		}
		for (l = m; l < 7; l++){
			printf(" ");
		}
		printf("%c\n", 186);

		// Defense
		printf("%c Defense:%i", 186, ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense);
		//This lines are for draw the box which contains stats
		if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense < 10){
			m = 1;
		}
		else if ((((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense >= 10) && (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense < 100)){
			m = 2;
		}
		else if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense == 100){
			m = 3;
		}
		else if ((((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense > 100) && (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense <= 1000)){
			m = 4;
		}
		for (l = m; l < 6; l++){
			printf(" ");
		}
		printf("%c\n", 186);

		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}

	//see inventory command
	else if (command1 == INVENTORY){
		i = j = 0;
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c Player Inventory:          %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		for (i = 0; i < worldexternpointer->entities.size(); i++){
			if (worldexternpointer->entities[i]->type == ITEM){
				if (((Item*)worldexternpointer->entities[i])->inventory == true){
					printf("%c %s", 186, worldexternpointer->entities[i]->name.c_str());
					j++;
					for (k = worldexternpointer->entities[i]->name.length(); k <= 26; k++){
						printf(" ");
					}
					printf("%c\n", 186);
				}
			}
		}
		if (j == 0){
			printf("%c Nothing in the inventory.  %c\n", 186, 186);
		}
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}

	
	//see backpacked items command
	else if (command1 == BACKPACKED){
		i = j = 0;
		if (((Item*)worldexternpointer->entities[17])->inventory == true){
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
			printf("%c Backpack Inventory:        %c\n", 186, 186);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
			for (i = 0; i < worldexternpointer->entities.size(); i++){
				if (worldexternpointer->entities[i]->type == ITEM){
					if (((Item*)worldexternpointer->entities[i])->inside_backpack == true){
						printf("%c %s", 186, ((Item*)worldexternpointer->entities[i])->name.c_str());
						j++;
						for (k = ((Item*)worldexternpointer->entities[i])->name.length(); k <= 26; k++){
							printf(" ");
						}
						printf("%c\n", 186);
					}
				}
			}
			if (j == 0){
				printf("%c Nothing in the backpack.   %c\n", 186, 186);
			}
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
		}
		else{
			printf("You don't have a backpack.\n");
		}
	}

	//see equipped items command
	else if (command1 == EQUIPPED){
		i = j = 0;
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c Player Equipped stuff:     %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
		for (i = 0; i < worldexternpointer->entities.size(); i++){
			if (worldexternpointer->entities[i]->type == ITEM){
				if (((Item*)worldexternpointer->entities[i])->equipped == true){
					printf("%c %s", 186, ((Item*)worldexternpointer->entities[i])->name.c_str());
					j++;
					for (k = ((Item*)worldexternpointer->entities[i])->name.length(); k <= 26; k++){
						printf(" ");
					}
					printf("%c\n", 186);
				}
			}
		}
		if (j == 0){
			printf("%c Nothing in the inventory.  %c\n", 186, 186);
		}
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	}

	//flee command to escape qhen you have the treasure
	else if (command1 == FLEE){
		if (((Item*)worldexternpointer->entities[11])->inventory == true){
			if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room == worldexternpointer->entities[0]){
				system("cls");
				//Ascii art code purpouse
				printf("   _____                            _         _       _   _                 \n  / ____|                          | |       | |     | | (_)                \n | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___ \n | |    / _ %c| '_ %c / _` | '__/ _` | __| | | | |/ _` | __| |/ _ %c| '_ %c/ __|\n | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | %c__ %c\n  %c_____%c___/|_| |_|%c__, |_|  %c__,_|%c__|%c__,_|_|%c__,_|%c__|_|%c___/|_| |_|___/\n  / _|               __/ |                 | |          | | (_)             \n | |_ ___  _ __    _|___/_  _ __ ___  _ __ | | ___  __ _| |_ _ _ __   __ _  \n |  _/ _ %c| '__|  / __/ _ %c| '_ ` _ %c| '_ %c| |/ _ %c/ _` | __| | '_ %c / _` | \n | || (_) | |    | (_| (_) | | | | | | |_) | |  __/ (_| | |_| | | | | (_| | \n |_| %c___/|_|     %c___%c___/|_| |_| |_| .__/|_|%c___|%c__,_|%c__|_|_| |_|%c__, | \n   _______    _          _   _       | |              _     _         __/ | \n  |__   __|  | |        | | | |      |_|             | |   | |       |___/  \n     | | __ _| | _____  | |_| |__   ___    __ _  ___ | | __| |              \n     | |/ _` | |/ / _ %c | __| '_ %c / _ %c  / _` |/ _ %c| |/ _` |              \n     | | (_| |   <  __/ | |_| | | |  __/ | (_| | (_) | | (_| |              \n     |_|%c__,_|_|%c_%c___|  %c__|_| |_|%c___|  %c__, |%c___/|_|%c__,_|              \n                                           __/ |                            \n                                          |___/                             \n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);
				command1 = QUIT;
			}
			else{
				printf("You can't flee here, you must go to the room where you had started.\n");
			}
		}
		else{
			printf("You can't flee until you take the treasure.\n");
		}
	}

	//clear screen command
	else if (command1 == CLEAR){
		system("cls");
		//Ascii art code purpouse
		printf("  _______    _          _   _                        _     _ \n |__   __|  | |        | | | |                      | |   | |\n    | | __ _| | _____  | |_| |__   ___    __ _  ___ | | __| |\n    | |/ _` | |/ / _ %c | __| '_ %c / _ %c  / _` |/ _ %c| |/ _` |\n    | | (_| |   <  __/ | |_| | | |  __/ | (_| | (_) | | (_| |\n    |_|%c__,_|_|%c_%c___|  %c__|_| |_|%c___|  %c__, |%c___/|_|%c__,_|\n                                          __/ |              \n                                         |___/               \n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);
		printf("By Xavier Olivenza.\n");
	}

	//quit command, this don't do anything, it's just to avoid the else printf
	else if (command1 == QUIT){

	}

	//help command
	else if (command1 == HELP){
		printf("You can move using:\n\tn/s/e/w\n\tnorth/east/south/west\n\tgo north/east/south/west/n/s/e/w\nAlso you can use the commands:\n\tlook/l -> to see the description of the room where you are\n\tlook/l + north/east/south/west/n/s/e/w -> to see the description of the\n\tpath\n\tlook/l + item name -> if you have it in the inventory you can see its\n\tlore\n\topen/close + north/east/south/west/n/s/e/w -> to open/close door\n\tpick + item name -> you can pick items from the ground\n\tdrop + item name -> you can drop items to the ground\n\tequip + item name -> you can equip items\n\tunequip + item name -> you can unequip items\n\tput + item name + into + cupboard -> put item in the cupboard\n\tget + item name + from + cupboard -> get the item from the cupboard\n\tuse + item name -> to use it\n\tequipped -> to see the objects that the player has equipped\n\tinventory/inv/i -> to see player inventory\n\tbackpacked -> to see what you had put inside the backpack if you had\n\ttaken it\n\tstats -> to see player stats\n\tflee -> when you have the treasure you can go to Tower 1 and flee\n\tto finish the game\n\tclear/c -> to clean the screen\n\thelp/h -> to open the help menu\n\tquit/q -> to quit the game\n\n");
	}

	else if (command1 == GOD){
		((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerhp = 1000;
		((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack = 1000;
		((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense = 1000;
		printf("God mode activated, you should been testing something...\n");
	}

	//error print
	else{
		printf("That's not a valid command.\n");
	}
}


void Player::executecommand2words(int command1, int command2, int& actual_position)const{
	//this method executes commands with 2 words

	int exitnum = 0, roomnum = 0;
	int exitnumdoors = 0, roomnumdoors = 0;
	int opositeroom = 0;
	((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room = ((Room*)worldexternpointer->entities[actual_position]);
	// ---------------------------------------------------------------------------------------------------------------
	//look command
	if (command1 == LOOK){
		//for directions
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == (command2 - 6)){
					//NORTH=6, 6-6=0, exitnum % 4 == 0
					//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
					//EAST=7, 6-6=0, exitnum % 4 == 1
					//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
					//SOUTH=8, 6-6=0, exitnum % 4 == 2
					//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
					//WEST=9, 6-6=0, exitnum % 4 == 3
					//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
					if (((Exit*)worldexternpointer->entities[exitnum + 18])->origin == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room){
						printf("%s\n", ((Exit*)worldexternpointer->entities[exitnum + 18])->description.c_str());
						return;
					}
				}
			}
		}
		//for inventory items
		else if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if ((((Item*)worldexternpointer->entities[command2 - 13])->inventory == true) && ((Item*)worldexternpointer->entities[command2 - 13])->equipped == true){//If the player have it
				printf("%s is in the inventory and equipped.\n%s\nDamage:%i\nDefense:%i\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str(), ((Item*)worldexternpointer->entities[command2 - 13])->description.c_str(), ((Item*)worldexternpointer->entities[command2 - 13])->attack, ((Item*)worldexternpointer->entities[command2 - 13])->defense);
			}
			else if ((((Item*)worldexternpointer->entities[command2 - 13])->inventory == true) && ((Item*)worldexternpointer->entities[command2 - 13])->equipped == false){//If the player have it
				printf("%s is in the inventory and not equipped.\n%s\nDamage:%i\nDefense:%i\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str(), ((Item*)worldexternpointer->entities[command2 - 13])->description.c_str(), ((Item*)worldexternpointer->entities[command2 - 13])->attack, ((Item*)worldexternpointer->entities[command2 - 13])->defense);
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
	//movement commands
	else if (command1 == GO){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == (command2 - 6)){
					//NORTH=6, 6-6=0, exitnum % 4 == 0
					//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
					//EAST=7, 6-6=0, exitnum % 4 == 1
					//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
					//SOUTH=8, 6-6=0, exitnum % 4 == 2
					//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
					//WEST=9, 6-6=0, exitnum % 4 == 3
					//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
					if (((Exit*)worldexternpointer->entities[exitnum + 18])->origin == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room){
						for (roomnum = 0; roomnum < NUMROOMS; roomnum++){//Check rooms to get the room num for actual_position
							if (((Exit*)worldexternpointer->entities[exitnum + 18])->destination == ((Room*)worldexternpointer->entities[roomnum])){
								if (((Exit*)worldexternpointer->entities[exitnum + 18])->door == true && ((Exit*)worldexternpointer->entities[exitnum + 18])->close == true){
									printf("Locked door.\n");
									return;
								}
								else{
									actual_position = roomnum;
									((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room = ((Exit*)worldexternpointer->entities[exitnum + 18])->destination;
									printf("Now you are in %s\n", ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->name.c_str());
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
	//open command
	else if (command1 == OPEN){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			if (((Item*)worldexternpointer->entities[16])->inventory == true){
				for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
					if (((Exit*)worldexternpointer->entities[exitnum + 18])->origin->name == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->name){
						if (exitnum % 4 == command2 - 6){
							//NORTH=6, 6-6=0, exitnum % 4 == 0
							//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
							//EAST=7, 6-6=0, exitnum % 4 == 1
							//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
							//SOUTH=8, 6-6=0, exitnum % 4 == 2
							//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
							//WEST=9, 6-6=0, exitnum % 4 == 3
							//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
							if (((Exit*)worldexternpointer->entities[exitnum + 18])->door == true){//check if there's a door
								if (((Exit*)worldexternpointer->entities[exitnum + 18])->close == true){
									((Exit*)worldexternpointer->entities[exitnum + 18])->close = false;//open the door of the current room
									for (exitnumdoors = 0; exitnumdoors < NUMEXITS; exitnumdoors++){
										if ((command2 == NORTH) || (command2 == EAST)){
											if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
												if (((Exit*)worldexternpointer->entities[exitnumdoors + 18])->destination->name == ((Exit*)worldexternpointer->entities[exitnum + 18])->origin->name){
													((Exit*)worldexternpointer->entities[exitnumdoors + 18])->close = false;//open the door of the next room
													printf("The door is opened.\n");
													return;
												}
											}
										}
										else if ((command2 == SOUTH) || (command2 == WEST)){
											if ((exitnumdoors % 4) == (command2 - 8)){//Oposite room
												if (((Exit*)worldexternpointer->entities[exitnumdoors + 18])->destination->name == ((Exit*)worldexternpointer->entities[exitnum + 18])->origin->name){
													((Exit*)worldexternpointer->entities[exitnumdoors + 18])->close = false;//open the door of the next room
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
	//close command
	else if (command1 == CLOSE){
		if ((command2 == NORTH) || (command2 == EAST) || (command2 == SOUTH) || (command2 == WEST)){
			if (((Item*)worldexternpointer->entities[16])->inventory == true){
				for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
					if (((Exit*)worldexternpointer->entities[exitnum + 18])->origin->name == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->name){
						if (exitnum % 4 == command2 - 6){
							//NORTH=6, 6-6=0, exitnum % 4 == 0
							//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
							//EAST=7, 6-6=0, exitnum % 4 == 1
							//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
							//SOUTH=8, 6-6=0, exitnum % 4 == 2
							//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
							//WEST=9, 6-6=0, exitnum % 4 == 3
							//West exits are each 4 exits, starting from 3, West exits = 3, 7, 11, 15, 19...
							if (((Exit*)worldexternpointer->entities[exitnum + 18])->door == true){//check if there's a door
								if (((Exit*)worldexternpointer->entities[exitnum + 18])->close == false){
									((Exit*)worldexternpointer->entities[exitnum + 18])->close = true;//close the door of the current room
									for (exitnumdoors = 0; exitnumdoors < NUMEXITS; exitnumdoors++){
										if ((command2 == NORTH) || (command2 == EAST)){
											if ((exitnumdoors % 4) == (command2 - 4)){//Oposite room
												if (((Exit*)worldexternpointer->entities[exitnumdoors + 18])->destination->name == ((Exit*)worldexternpointer->entities[exitnum + 18])->origin->name){
													((Exit*)worldexternpointer->entities[exitnumdoors + 18])->close = true;//close the door of the next room
													printf("The door is closed.\n");
													return;
												}
											}
										}
										else if ((command2 == SOUTH) || (command2 == WEST)){
											if ((exitnumdoors % 4) == (command2 - 8)){//Oposite room
												if (((Exit*)worldexternpointer->entities[exitnumdoors + 18])->destination->name == ((Exit*)worldexternpointer->entities[exitnum + 18])->origin->name){
													((Exit*)worldexternpointer->entities[exitnumdoors + 18])->close = true;//close the door of the next room
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
	//pick command
	else if (command1 == PICK){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (((Item*)worldexternpointer->entities[command2 - 13])->item_room == ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room){//Looks if the player is in the same room of the item.
				if (((Item*)worldexternpointer->entities[command2 - 13])->inside_cupboard == false){
					if (((Item*)worldexternpointer->entities[command2 - 13])->inventory == false){//If the player don't have it
						((Item*)worldexternpointer->entities[command2 - 13])->inventory = true;
						((Item*)worldexternpointer->entities[command2 - 13])->inside_cupboard = false;
						printf("Now you have %s.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
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
	//drop command
	else if (command1 == DROP){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (((Item*)worldexternpointer->entities[command2 - 13])->inventory == true){//If the player have it
				if (((Item*)worldexternpointer->entities[command2 - 13])->equipped == true){//If the player have it equipped
					((Item*)worldexternpointer->entities[command2 - 13])->equipped = false;//unequip
					((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack -= ((Item*)worldexternpointer->entities[command2 - 13])->attack;
					((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense -= ((Item*)worldexternpointer->entities[command2 - 13])->defense;
				}
				((Item*)worldexternpointer->entities[command2 - 13])->inventory = false;
				((Item*)worldexternpointer->entities[command2 - 13])->item_room = ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room;
				((Item*)worldexternpointer->entities[command2 - 13])->inside_cupboard = false;
				printf("You had dropped %s.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
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
	//equip command
	else if (command1 == EQUIP){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (((Item*)worldexternpointer->entities[command2 - 13])->inventory == true){//If the player have it
				if (((Item*)worldexternpointer->entities[command2 - 13])->equipable == true){
					if (((Item*)worldexternpointer->entities[command2 - 13])->equipped == false){
						if ((command2 == KATANA) && (((Item*)worldexternpointer->entities[13])->equipped == true)){//if you want to equip katana and you have sword equipped
							//equip katana
							((Item*)worldexternpointer->entities[command2 - 22])->equipped = true;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack += ((Item*)worldexternpointer->entities[command2 - 13])->attack;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense += ((Item*)worldexternpointer->entities[command2 - 13])->defense;
							printf("%s equipped.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
							//unequip sword
							((Item*)worldexternpointer->entities[13])->equipped = false;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack -= ((Item*)worldexternpointer->entities[13])->attack;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense -= ((Item*)worldexternpointer->entities[13])->defense;
							printf("%s unequipped.\n", ((Item*)worldexternpointer->entities[13])->name.c_str());
						}
						else if (((command2) == SWORD) && (((Item*)worldexternpointer->entities[9])->equipped == true)){//if you want to equip sword and you have katana equipped
							//equip sword
							((Item*)worldexternpointer->entities[command2 - 22])->equipped = true;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack += ((Item*)worldexternpointer->entities[command2 - 13])->attack;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense += ((Item*)worldexternpointer->entities[command2 - 13])->defense;
							printf("%s equipped.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
							//unequip katana
							((Item*)worldexternpointer->entities[9])->equipped = false;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack -= ((Item*)worldexternpointer->entities[9])->attack;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense -= ((Item*)worldexternpointer->entities[9])->defense;
							printf("%s unequipped.\n", ((Item*)worldexternpointer->entities[9])->name.c_str());
						}
						else{
							((Item*)worldexternpointer->entities[command2 - 13])->equipped = true;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack += ((Item*)worldexternpointer->entities[command2 - 13])->attack;
							((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense += ((Item*)worldexternpointer->entities[command2 - 13])->defense;
							printf("%s equipped.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
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
	//unequip command
	else if (command1 == UNEQUIP){
		if ((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)){
			if (((Item*)worldexternpointer->entities[command2 - 13])->equipped == true){//If the player have it
				((Item*)worldexternpointer->entities[command2 - 13])->equipped = false;
				((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack -= ((Item*)worldexternpointer->entities[command2 - 13])->attack;
				((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense -= ((Item*)worldexternpointer->entities[command2 - 13])->defense;
				printf("%s unequipped.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
			}
			else{
				printf("You don't have this item.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	//use command, by now this only works for use explosive

	else if (command1 == USE){
		if (command2 == GRENADE){
			if (((Item*)worldexternpointer->entities[12])->inventory == true){
				printf("By now this don't work, wait until battle update comes.\n");
			}
			else{
				printf("You don't have this item.\n");
			}
		}
		else if (command2 == EXPLOSIVE){
			if (((Item*)worldexternpointer->entities[15])->inventory == true){
				if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->exploitablewall == true){
					((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->exploitablewall = false;
					((Item*)worldexternpointer->entities[15])->inventory = false;

					//Ascii art code purpouse
					//countdown
					printf("You had armed your explosive.\n");
					Sleep(2000);
					printf("                _____ \n               |___ / \n                 |_ %c \n                ___) |\n               |____/", 92);
					Sleep(333);
					printf(".");
					Sleep(333);
					printf(".");
					Sleep(333);
					printf(".\n");
					printf("                ____  \n               |___ %c \n                 __) |\n                / __/ \n               |_____|", 92);
					Sleep(333);
					printf(".");
					Sleep(333);
					printf(".");
					Sleep(333);
					printf(".\n");
					printf("                  _ \n                 / |\n                 | |\n                 | |\n                 |_|");
					Sleep(333);
					printf(".");
					Sleep(333);
					printf(".");
					Sleep(333);
					printf(".\n");

					printf("   ___  ____  ____  ____  __  _________\n  / _ )/ __ %c/ __ %c/ __ %c/  |/  / / / /\n / _  / /_/ / /_/ / /_/ / /|_/ /_/_/_/ \n/____/%c____/%c____/%c____/_/  /_(_|_|_)  \n", 92, 92, 92, 92, 92, 92);
					printf("You had used your explosive against the wall.\n");
				}
				else{
					printf("You can't blow this wall.\n");
				}
			}
			else{
				printf("You don't have this item.\n");
			}
		}
		else{
			printf("You can't use that.\n");
		}
	}
}

void Player::executecommand4words(int command1, int command2, int command3, int command4, int& actual_position)const{
	//this method executes commands with four words

	//put command
	if (command1 == PUT){
		if (((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)) && (command3 == INTO)){
			if (command4 == CUPBOARD){
				if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->cupboard == true){//looks if the player room has a cupboard and player has the item
					if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->exploitablewall == false){
						if (((Item*)worldexternpointer->entities[command2 - 13])->inventory == true){
							if (((Item*)worldexternpointer->entities[command2 - 13])->equipped == true){//If the player have it equipped
								((Item*)worldexternpointer->entities[command2 - 13])->equipped = false;//unequip
								((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack -= ((Item*)worldexternpointer->entities[command2 - 13])->attack;
								((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense -= ((Item*)worldexternpointer->entities[command2 - 13])->defense;
							}
							((Item*)worldexternpointer->entities[command2 - 13])->inventory = false;
							((Item*)worldexternpointer->entities[command2 - 13])->inside_cupboard = true;
							((Item*)worldexternpointer->entities[command2 - 13])->item_room = ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room;
							printf("You had put %s inside the cupboard.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
						}
						else{
							printf("You don't have it.\n");
						}
					}
					else{
						printf("You can not reach the cupboard, is behind a wall, but it seems that you can blow it.\n");
					}
				}
				else{
					printf("There's not a cupboard here.\n");
				}
			}
			else if (command4 == BACKPACK){
				if (command2 != command4){
					if (((Item*)worldexternpointer->entities[17])->inventory == true){
						if (((Item*)worldexternpointer->entities[command2 - 13])->inventory == true){
							if (((Item*)worldexternpointer->entities[command2 - 13])->equipped == true){//If the player have it equipped
								((Item*)worldexternpointer->entities[command2 - 13])->equipped = false;//unequip
								((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerattack -= ((Item*)worldexternpointer->entities[command2 - 13])->attack;
								((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->playerdefense -= ((Item*)worldexternpointer->entities[command2 - 13])->defense;
							}
							((Item*)worldexternpointer->entities[command2 - 13])->inventory = false;
							((Item*)worldexternpointer->entities[command2 - 13])->inside_backpack = true;
							printf("You had put %s inside the backpack.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
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
	//get command
	else if (command1 == GET){
		if (((command2 == KATANA) || (command2 == GASMASK) || (command2 == TREASURE) || (command2 == GRENADE) || (command2 == SWORD) || (command2 == SHIELD) || (command2 == EXPLOSIVE) || (command2 == KEY) || (command2 == BACKPACK)) && (command3 == FROM)){
			if (command4 == CUPBOARD){
				if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room == ((Item*)worldexternpointer->entities[command2 - 13])->item_room){
					if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->exploitablewall == false){
						if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->cupboard == true){//looks if the player room has a cupboard and player has the item
							if (((Item*)worldexternpointer->entities[command2 - 13])->inside_cupboard == true){
								if (((Item*)worldexternpointer->entities[command2 - 13])->inventory == false){
									((Item*)worldexternpointer->entities[command2 - 13])->inventory = true;
									((Item*)worldexternpointer->entities[command2 - 13])->inside_cupboard = false;
									printf("You had put %s inside your inventory.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
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
						printf("You can not reach the cupboard, is behind a wall, but it seems that you can blow it.\n");
					}
				}
				else{
					printf("You are not in the room where this item is.\n");
				}
			}
			else if (command4 == BACKPACK){
				if (command2 != command4){
					if (((Item*)worldexternpointer->entities[17])->inventory == true){
						if (((Item*)worldexternpointer->entities[command2 - 13])->inside_backpack == true){
							((Item*)worldexternpointer->entities[command2 - 13])->inventory = true;
							((Item*)worldexternpointer->entities[command2 - 13])->inside_backpack = false;
							printf("You had put %s inside the inventory.\n", ((Item*)worldexternpointer->entities[command2 - 13])->name.c_str());
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
				printf("That's not a valid command.\n");
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
}