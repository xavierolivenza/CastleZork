


/*
#include <stdio.h>
#include <string.h>
#include "Player.h"

void move(){
	char fullcommand[20];
	char *command;
	char *firstcommand;
	char *secondcommand;
	int command1 = 0, command2 = 0;
	char *context;

	printf("What do you want to do?\n");
	scanf_s("%s", &fullcommand);
	command = strtok_s(fullcommand, " ", &context);
	firstcommand = command;
	command = strtok_s(NULL, " ", &context);
	secondcommand = command;

	command1 = check_firstcommand(firstcommand);
	command2 = check_secondcommand(secondcommand);
}

int check_firstcommand(char* str){
	if (str == "look"){
		return LOOK;
	}
	else if (str == "go"){
		return GO;
	}
	else if (str == "open"){
		return OPEN;
	}
	else if (str == "close"){
		return CLOSE;
	}
	else if (str == "quit"){
		return QUIT;
	}
	else if (str == "help"){
		return HELP;
	}
	else{
		return ERROR;
	}
}
int check_secondcommand(char* str){
	if (str == "north"){
		return NORTH;
	}
	else if (str == "east"){
		return EAST;
	}
	else if (str == "south"){
		return SOUTH;
	}
	else if (str == "west"){
		return WEST;
	}
	else{
		return ERROR;
	}
}
*/