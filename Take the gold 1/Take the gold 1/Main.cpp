#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "World.h"

int main(){
	char full_firstcommand[20];
	int command1 = 0, command2 = 0;
	int command_words = 0, i = 0;
	int actual_position = 0;
	int j = 0;

	World world;
	Player commandinput;
	world.CreateWorld();
	printf("Welcome to Take the gold\nThis game is based on Zork for a class project.\nCITM Terrassa 2015-2016\nYou can move using:\nn/s/e/w\nnorth/east/south/west\ngo north/go east/go south/go west\nalso you can use the commands:\nlook->to see the description of the room where you are\nlook+north/east/south/west->to see the description of the path\nopen/close+north/east/south/west->to open/close door\nquit->to quit the game\nLet's start!\n\n");

	do{
		printf("You are in %s.\n%s\n", world.player->current_room->name, world.player->current_room->description);
		printf("What do you want to do?\n");
		gets_s(full_firstcommand);

		command_words = 0;

		for (i = 0; i <= (strlen(full_firstcommand)); i++){//Detects if the command has 1 or more words
			if (full_firstcommand[i] == ' '){
				command_words++;
			}
			full_firstcommand[i] = tolower(full_firstcommand[i]);
		}

		char* secondcommand = commandinput.command_split(full_firstcommand);
		command1 = commandinput.check_firstcommand(full_firstcommand);

		if ((command_words) == 0){//Execute commands with 1 word
			world.executecommand1word(command1, actual_position);
		}
		else if ((command_words) == 1){//Execute commands with 2 words
			command2 = commandinput.check_secondcommand(secondcommand);
			world.executecommand2words(command1, command2, actual_position);
		}

	} while (command1 != 4);
	system("pause");
	return 0;
}