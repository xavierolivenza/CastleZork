#ifndef __Item__
#define __Item__

#include "Entity.h"
#include "Room.h"
#include "Exits.h"

class Item : public Entity{
public:
	Item();
	Item(const char*, const char*, Room*, const int, const int, const int, const bool, const bool, const bool, const bool);
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
};

#endif //__Item__