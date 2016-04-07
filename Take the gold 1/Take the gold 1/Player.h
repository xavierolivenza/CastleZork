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
	unsigned int playerhp = 100;
	unsigned int playerattack;
	unsigned int playerdefense;
public:
	int check_firstcommand(char*)const;
	int check_secondcommand(char*)const;
};

enum rooms{ 
	TOWER1, TOWER2, TOWER3, TOWER4, 
	NORTHCORRIDOR, EASTCORRIDOR, SOUTHCORRIDOR, WESTCORRIDOR, 
	THRONEROOM
};
enum commandset { 
	LOOK, GO, OPEN, CLOSE, QUIT, HELP, 
	NORTH, EAST, SOUTH, WEST, 
	PICK, DROP, INVENTORY, EQUIPED, EQUIP, UNEQUIP, PUT, GET, INTO, FROM, STATS
};
#endif //__Player__