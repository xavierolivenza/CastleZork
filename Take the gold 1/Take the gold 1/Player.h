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
	unsigned int playerattack = 0;
	unsigned int playerdefense = 0;
public:
	int check_firstcommand(const String&)const;
	int check_secondcommand(const String&)const;
	int check_thirdcommand(const String&, const String&)const;
	int check_fourthcommand(const String&)const;
	int check_numcommands(const String&, const String&, const String&, const String&)const;
};

enum rooms{ 
	TOWER1, TOWER2, TOWER3, TOWER4, 
	NORTHCORRIDOR, EASTCORRIDOR, SOUTHCORRIDOR, WESTCORRIDOR, 
	THRONEROOM
};
enum commandset { 
	LOOK, GO, OPEN, CLOSE, QUIT, HELP, 
	NORTH, EAST, SOUTH, WEST, 
	PICK, DROP, INVENTORY, EQUIPPED, EQUIP, UNEQUIP, PUT, GET, INTO, FROM, STATS,
	KATANA, GASMASK, TREASURE, GRANADE, SWORD, SHIELD, EXPLOSIVE,
	CUPBOARD
};
#endif //__Player__