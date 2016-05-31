#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "World.h"

#define COMMANDBUFFER 50

World* worldexternpointer = new World();

int main(){
	ReportMemoryLeaks();

	String commandmanagement;
	char command[COMMANDBUFFER];
	int command1 = 0, command2 = 0, command3 = 0, command4 = 0;
	int command_words = 0, i = 0, j = 0;
	int actual_position = 0;
	unsigned int charcommandnum = 0;
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;

	worldexternpointer->CreateWorld();
	printf("Welcome to:\n\n");
	printf("  _______    _          _   _                        _     _ \n |__   __|  | |        | | | |                      | |   | |\n    | | __ _| | _____  | |_| |__   ___    __ _  ___ | | __| |\n    | |/ _` | |/ / _ %c | __| '_ %c / _ %c  / _` |/ _ %c| |/ _` |\n    | | (_| |   <  __/ | |_| | | |  __/ | (_| | (_) | | (_| |\n    |_|%c__,_|_|%c_%c___|  %c__|_| |_|%c___|  %c__, |%c___/|_|%c__,_|\n                                          __/ |              \n                                         |___/               \n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);
	printf("\nThis game is based on Zork for a class project.\nXavier Olivenza\nCITM Terrassa 2015-2016\n\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c Lore:                                                                  %c\n%c You are a thief who must steal the treasure of the king in his castle. %c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\nYou can move using:\n\tn/s/e/w\n\tnorth/east/south/west\n\tgo north/east/south/west/n/s/e/w\nAlso you can use the commands:\n\tlook/l -> to see the description of the room where you are\n\tlook/l + north/east/south/west/n/s/e/w -> to see the description of the\n\tpath\n\tlook/l + item name -> if you have it in the inventory you can see its\n\tlore\n\tlook + items -> to see items in the room\n\topen/close + north/east/south/west/n/s/e/w -> to open/close door\n\tpick + item name -> you can pick items from the ground\n\tdrop + item name -> you can drop items to the ground\n\tequip + item name -> you can equip items\n\tunequip + item name -> you can unequip items\n\tput + item name + into + cupboard -> put item in the cupboard\n\tget + item name + from + cupboard -> get the item from the cupboard\n\tuse + explosive -> use it against the thorne room wall\n\tequipped -> to see the objects that the player has equipped\n\tinventory/inv/i -> to see player inventory\n\tbackpacked -> to see what you had put inside the backpack if you had\n\ttaken it\n\tstats -> to see player stats\n\tflee -> when you have the treasure you can go to Tower 1 and flee to\n\tfinish the game\n\tclear/c -> to clean the screen\n\thelp/h -> to open the help menu\n\tquit/q -> to quit the game\n\nCommands for combat and trade:\n\tWallet -> to see how many coins you have\n\tAttack + enemy name -> attack the enemy until he dies\n\tSpecial + hidden blade -> use an intant kill special attack\n\tuse + venom gas grenade -> with gs mask equipped you can use it\n\tto instant kill all enemies in the room\n\tBuy + seller -> to see what the seller has\n\tBuy + item name + from + seller -> to buy something that seller has\n\tSell + item name + into + seller -> to sell things to seller\nCommand for testing: god\nYou have regeneration\nLet's start!\n\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 186, 186, 186, 186, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	printf("//------------------------------------------------------------------------//\n");

	printf("You are in %s.\n%s\n", ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->name.c_str(), ((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->current_room->description.c_str());
	worldexternpointer->player->dropeditemslook();
	
	printf("What do you want to do?\n");
	
	do{
		//printf("S");
		if (_kbhit()){
			if (charcommandnum < (COMMANDBUFFER - 2)){
				if (charcommandnum == 0){
					printf("//------------------------------------------------------------------------//\n");
				}
				command[charcommandnum] = _getch();
				command[charcommandnum + 1] = '\0';
				if (command[charcommandnum] != '\r'){
					printf("Command input: '%s'\n", command);
				}
				//printf("String: %s\n", command);//print command
				charcommandnum++;
				if (command[charcommandnum - 1] == '\r'){//Enter-> erase command and execute
					printf("//------------------------------------------------------------------------//\n");
					//printf("Your command is: %s\n", command);
					command[charcommandnum - 1] = '\0';
					//---------------------------------------------------
					if ((command[0] != NULL) && (command[0] != ' ')){
						Vector <String> commands = commandmanagement.tokenize(command, command_words);

						command1 = command2 = command3 = command4 = 0;

						switch (command_words){
						case 1:
							command1 = worldexternpointer->player->check_firstcommand(commands);
							worldexternpointer->player->executecommand1word(command1, actual_position);
							break;
						case 2:
							command1 = worldexternpointer->player->check_firstcommand(commands);
							command2 = worldexternpointer->player->check_secondcommand(commands);
							worldexternpointer->player->executecommand2words(command1, command2, actual_position);
							break;
						case 4:
							command1 = worldexternpointer->player->check_firstcommand(commands);
							command2 = worldexternpointer->player->check_secondcommand(commands);
							command3 = worldexternpointer->player->check_thirdcommand(commands);
							command4 = worldexternpointer->player->check_fourthcommand(commands);
							worldexternpointer->player->executecommand4words(command1, command2, command3, command4, actual_position);
							break;
						default:
							printf("That's not a valid command.\n");
							break;
						}
					}
					else{
						printf("You must put a valid command.\n");
					}
					//---------------------------------------------------
					command[charcommandnum] = '\0';
					charcommandnum = 0;
				}
			}
			else{
				command[COMMANDBUFFER - 1] = '\0';
			}
		}
		if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->attackactive == true){
			worldexternpointer->player->executecommand2words(command1, command2, actual_position);
		}
		//regeneration
		currenttime = GetTickCount();
		if (currenttime >= (initialtime + 5000)){
			((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->hp += 1;
			if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->hp > 100){
				((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->hp = 100;
			}
			initialtime = currenttime;
		}
		worldexternpointer->Update();
		if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->god == true){
			((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->hp = 100;
		}
		if (((Player*)worldexternpointer->entities[worldexternpointer->entities.size() - 1])->dead == true){
			command1 = QUIT;
		}
	} while (command1 != QUIT);
	system("pause");
	delete worldexternpointer;
	return 0;
}