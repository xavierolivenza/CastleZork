#include <stdio.h>
#include <stdlib.h>
#include "World.h"

int main(){
	char full_firstcommand[20];
	int command1 = 0, command2 = 0;
	int command_words = 0, i = 0;
	int actual_position = 0;

	World createworld;
	World commandexecution;
	Player commandinput;
	createworld.CreateWorld();

	do{
		printf("What do you want to do?\n");
		gets_s(full_firstcommand);

		for (i = 0; i <= (strlen(full_firstcommand)); i++){//Detects if the command has 1 or more words
			if (full_firstcommand[i] == ' '){
				command_words++;
			}
		}

		char* secondcommand = commandinput.command_split(full_firstcommand);
		command1 = commandinput.check_firstcommand(full_firstcommand);

		if ((command_words + 1) == 1){//Execute commands with 1 word
			commandexecution.executecommand1word(command1, actual_position);
		}
		else{//Execute commands with 2 words
			command2 = commandinput.check_secondcommand(secondcommand);
			commandexecution.executecommand2words(command1, command2, actual_position);
		}
	} while (command1 != 4);
	system("pause");
	return 0;
}