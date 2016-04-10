#ifndef __Item__
#define __Item__

#include "Entity.h"
#include "Room.h"
#include "Exits.h"

class Item : public Entity{
public:
	Item();
	~Item();
public:
	Room* item_room = nullptr;
	Exit* item_exit = nullptr;
public:
	int attack;
	int defense;
	int uses;
	bool inventory = false;
	bool equipped = false;
};

#endif //__Item__