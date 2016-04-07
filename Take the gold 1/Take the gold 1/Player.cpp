#include <stdio.h>
#include <string.h>

#include "World.h"

Player::Player(){
}
Player::~Player(){
}

int Player::check_firstcommand(char* firstcommand)const{
	if (firstcommand == "look"){
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
	else if (firstcommand == "quit"){
		return QUIT;
	}
	else if (firstcommand == "q"){
		return QUIT;
	}
	else if (firstcommand == "help"){
		return HELP;
	}
	else if (firstcommand == "h"){
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
}

int Player::check_secondcommand(char* secondcommand)const{
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
}