#ifndef __Player__
#define __Player__

#include "Room.h"

class Player{
public:
	Room* current_room = nullptr;
public:
	char* command_split(char*);
	int check_firstcommand(char*);
	int check_secondcommand(char*);
};

enum rooms{ TOWER1, TOWER2, TOWER3, TOWER4, NORTHCORRIDOR, EASTCORRIDOR, SOUTHCORRIDOR, WESTCORRIDOR, THRONEROOM};
enum commandset { LOOK, GO, OPEN, CLOSE, QUIT, HELP, NORTH, EAST, SOUTH, WEST};
#endif //__Player__