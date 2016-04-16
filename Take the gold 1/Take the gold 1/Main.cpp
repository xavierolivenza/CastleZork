#include <stdio.h>
#include <stdlib.h>
#include "World.h"

World* worldexternpointer = new World();

int main(){
	String commandmanagement;
	char command[50];
	int command1 = 0, command2 = 0, command3 = 0, command4 = 0;
	int command_words = 0, i = 0, j = 0;
	int actual_position = 0;
	Player commandinput;

	worldexternpointer->CreateWorld();
	printf("Welcome to:\n\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	printf("%c %c%c%c %c%c%c %c %c %c%c   %c%c%c %c %c %c%c   %c%c%c %c%c%c %c   %c%c  %c\n", 186, 196, 194, 196, 218, 196, 191, 179, 47, 218, 196, 196, 194, 196, 179, 179, 218, 196, 218, 196, 196, 218, 196, 191, 179, 218, 191, 186);
	printf("%c  %c  %c%c%c %c%c  %c%c    %c  %c%c%c %c%c   %c%c%c %c %c %c   %c %c %c\n", 186, 179, 195, 196, 195, 179, 180, 195, 196, 179, 195, 196, 180, 195, 196, 195, 196, 191, 179, 179, 179, 179, 179, 186);
	printf("%c  %c  %c %c %c %c %c%c    %c  %c %c %c%c   %c%c%c %c%c%c %c%c%c %c%c  %c\n", 186, 179, 179, 179, 179, 92, 192, 196, 179, 179, 179, 192, 196, 192, 196, 217, 192, 196, 217, 192, 196, 196, 192, 217, 186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	printf("\nThis game is based on Zork for a class project.\nXavier Olivenza\nCITM Terrassa 2015-2016\n\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c Lore:                                                                  %c\n%c You are a thief who must steal the treasure of the king in his castle. %c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\nYou can move using:\n\tn/s/e/w\n\tnorth/east/south/west\n\tgo north/east/south/west/n/s/e/w\nAlso you can use the commands:\n\tlook/l -> to see the description of the room where you are\n\tlook/l + north/east/south/west/n/s/e/w -> to see the description of the\n\tpath\n\topen/close + north/east/south/west/n/s/e/w -> to open/close door\n\tpick + item name -> you can pick items from the ground\n\tdrop + item name -> you can drop items to the ground\n\tequip + item name -> you can equip items\n\tunequip + item name -> you can unequip items\n\tput + item name + into + cupboard -> put item in the cupboard\n\tget + item name + from + cupboard -> get the item from the cupboard\n\tequipped -> to see the objects that the player has equipped\n\tinventory/inv/i -> to see player inventory\n\tbackpacked -> to see what you had put inside the backpack if you had\n\ttaken it\n\tstats -> to see player stats\n\tclear/c -> to clean the screen\n\thelp/h -> to open the help menu\n\tquit/q -> to quit the game\nLet's start!\n\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 186, 186, 186, 186, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	do{
		printf("//------------------------------------------------------------------------//\n");

		printf("You are in %s.\n%s\n", worldexternpointer->player->current_room->name.c_str(), worldexternpointer->player->current_room->description.c_str());
		commandinput.dropeditemslook();
		
		printf("What do you want to do?\n");
		gets_s(command);
		
		if ((command[0] != NULL) && (command[0] != ' ')){
			Vector <String> commands = commandmanagement.tokenize(command, command_words);

			command1 = command2 = command3 = command4 = 0;
			
			switch (command_words){
			case 1:
				command1 = commandinput.check_firstcommand(commands);
				commandinput.executecommand1word(command1, actual_position);
				break;
			case 2:
				command1 = commandinput.check_firstcommand(commands);
				command2 = commandinput.check_secondcommand(commands);
				commandinput.executecommand2words(command1, command2, actual_position);
				break;
			case 4:
				command1 = commandinput.check_firstcommand(commands);
				command2 = commandinput.check_secondcommand(commands);
				command3 = commandinput.check_thirdcommand(commands);
				command4 = commandinput.check_fourthcommand(commands);
				commandinput.executecommand4words(command1, command2, command3, command4, actual_position);
				break;
			default:
				printf("That's not a valid command.\n");
				break;
			}
		}
		else{
			printf("You must put a valid command.\n");
		}
	} while (command1 != QUIT);
	system("pause");
	delete worldexternpointer;
	return 0;
}