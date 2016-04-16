#ifndef __Item__
#define __Item__

#include "Entity.h"
#include "Room.h"
#include "Exits.h"

class Item : public Entity{
public:
	Item();
	Item(const char*, const char*, Room*, int, int, int, bool, bool, bool, bool, bool);
	~Item();
public:
	Room* item_room = nullptr;
public:
	int attack;
	int defense;
	int uses;
	bool inventory = false;
	bool equipped = false;
	bool equipable = false;
	bool inside_cupboard = true;
	bool inside_backpack = false;
};

#endif //__Item__