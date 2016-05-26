#ifndef __Player__
#define __Player__

#include "Entity.h"
#include "Room.h"
#include "Creature.h"

class Player : public Creature{
public:
	Player();
	Player(const char*, const char*, Room*, EntityType);
	~Player();
public:
	unsigned int playerhp = 100;//player health points
	unsigned int playerattack = 0;//player attack, modified by equipped items
	unsigned int playerdefense = 0;//player defense, modified by equipped items
public:
	int check_firstcommand(Vector <String>)const;
	int check_secondcommand(Vector <String>)const;
	int check_thirdcommand(Vector <String>)const;
	int check_fourthcommand(Vector <String>)const;
	void dropeditemslook()const;
	void executecommand1word(int&, int&)const;
	void executecommand2words(int, int, int&)const;
	void executecommand4words(int, int, int, int, int&)const;
};

enum commandset { 
	LOOK, GO, OPEN, CLOSE, QUIT, HELP,
	NORTH, EAST, SOUTH, WEST,
	PICK, DROP, INVENTORY, EQUIPPED, EQUIP, UNEQUIP, PUT, GET, INTO, FROM, STATS, BACKPACKED,
	KATANA, GASMASK, TREASURE, GRENADE, SWORD, SHIELD, EXPLOSIVE, KEY, BACKPACK,
	CUPBOARD,
	USE, FLEE,
	CLEAR,
	GOD,
	ITEMS,
	COMMANDERROR
};
#endif //__Player__