#ifndef __Player__
#define __Player__

#include "Room.h"

class Player{
public:
	Room* current_room = nullptr;
public:
	Player();
	~Player();
public:
	char* command_split(char*)const;
	int check_firstcommand(char*)const;
	int check_secondcommand(char*)const;
};
enum rooms{ TOWER1, TOWER2, TOWER3, TOWER4, NORTHCORRIDOR, EASTCORRIDOR, SOUTHCORRIDOR, WESTCORRIDOR, THRONEROOM};
enum commandset { LOOK, GO, OPEN, CLOSE, QUIT, HELP, NORTH, EAST, SOUTH, WEST};
#endif //__Player__