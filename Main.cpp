#include <stdio.h>
#include <stdlib.h>
#include "World.h"

int main(){
	char full_firstcommand[20];
	int command1 = 0, command2 = 0;
	int command_words = 0, i = 0;

	World createworld;
	Player commandinput;
	createworld.CreateWorld();

	printf("Intoduce the command.\n");
	gets_s(full_firstcommand);

	for (i = 0; i <= (strlen(full_firstcommand)); i++){
		if (full_firstcommand[i] == ' '){
			command_words++;
		}
	}
	
	char* secondcommand = commandinput.command_split(full_firstcommand);
	command1 = commandinput.check_firstcommand(full_firstcommand);
	command2 = commandinput.check_secondcommand(secondcommand);

	if ((command_words + 1) == 1){//Execute commands with 1 word
		commandinput.executecommand1word(command1);
	}
	else{//Execute commands with 2 words
		commandinput.executecommand2words(command1, command2);
	}

	

	







	system("pause");
	return 0;
}