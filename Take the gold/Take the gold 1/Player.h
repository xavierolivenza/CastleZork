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
	int check_firstcommand(Vector <String> &)const;
	int check_secondcommand(Vector <String> &)const;
	int check_thirdcommand(Vector <String> &)const;
	int check_fourthcommand(Vector <String> &)const;
	void dropeditemslook()const;
	void enemieslook()const;
	void executecommand1word(int&, int&)const;
	void executecommand2words(int, int, int&)const;
	void executecommand4words(int, int, int, int, int&)const;
public:
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	bool attackactive = false;
	unsigned int actualtarget = 0;
public:
	bool dead = false;
	unsigned int hp = 100;//health points
	unsigned int attack = 10;//attack, modified by equipped items in player
	unsigned int defense = 0;//defense, modified by equipped items in player
	void move(int&, int&);
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
	ATTACK, SPECIAL, BUY, SELL, HIDDENBLADE,
	SOLDIER1, SOLDIER2, SOLDIER3, SOLDIER4, SOLDIER5, SOLDIER6, BIGSOLDIER, SELLER,
	COMMANDERROR
};
#endif //__Player__