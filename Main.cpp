#include <stdio.h>
#include <stdlib.h>
#include "World.h"

int main(){
	char full_firstcommand[20];
	int command1 = 0, command2 = 0;

	World createworld;
	Player commandinput;
	createworld.CreateWorld();

	printf("Intoduce the command.\n");
	gets_s(full_firstcommand);

	char* secondcommand = commandinput.command_split(full_firstcommand);

	command1 = commandinput.check_firstcommand(full_firstcommand);
	command2 = commandinput.check_secondcommand(secondcommand);










	system("pause");
	return 0;
}