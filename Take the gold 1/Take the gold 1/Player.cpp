#include <stdio.h>
#include <string.h>
#include "World.h"

Player::Player(){
}

Player::~Player(){
}

char* Player::command_split(char* fullcommand)const{
	char *context, *firstcommand, *secondcommand;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	firstcommand = strtok_s(fullcommand, " ", &context);
	secondcommand = strtok_s(NULL, " ", &context);
	// --------------------------------------------------------------------------------------------------------------
	return secondcommand;
}

int Player::check_firstcommand(char* firstcommand)const{
	if (strcmp(firstcommand, "look") == 0){
		return LOOK;
	}
	else if (strcmp(firstcommand, "go") == 0){
		return GO;
	}
	else if (strcmp(firstcommand, "open") == 0){
		return OPEN;
	}
	else if (strcmp(firstcommand, "close") == 0){
		return CLOSE;
	}
	else if (strcmp(firstcommand, "quit") == 0){
		return QUIT;
	}
	else if (strcmp(firstcommand, "q") == 0){
		return QUIT;
	}
	else if (strcmp(firstcommand, "help") == 0){
		return HELP;
	}
	else if (strcmp(firstcommand, "h") == 0){
		return HELP;
	}
	// ---------------------------------------------------------------------------------------------------------------
	//Detection commands with 1 word
	else if (strcmp(firstcommand, "north")== 0){
		return NORTH;
	}
	else if ((strcmp(firstcommand, "n")) == 0){
		return NORTH;
	}
	else if (strcmp(firstcommand, "east") == 0){
		return EAST;
	}
	else if (strcmp(firstcommand, "e") == 0){
		return EAST;
	}
	else if (strcmp(firstcommand, "south") == 0){
		return SOUTH;
	}
	else if (strcmp(firstcommand, "s") == 0){
		return SOUTH;
	}
	else if (strcmp(firstcommand, "west") == 0){
		return WEST;
	}
	else if (strcmp(firstcommand, "w") == 0){
		return WEST;
	}
	// ---------------------------------------------------------------------------------------------------------------
}

int Player::check_secondcommand(char* secondcommand)const{
	if (strcmp(secondcommand, "north") == 0){
		return NORTH;
	}
	else if (strcmp(secondcommand, "east") == 0){
		return EAST;
	}
	else if (strcmp(secondcommand, "south") == 0){
		return SOUTH;
	}
	else if (strcmp(secondcommand, "west") == 0){
		return WEST;
	}
}