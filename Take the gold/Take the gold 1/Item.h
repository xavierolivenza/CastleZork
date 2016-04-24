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
	int attack;//attack of the item
	int defense;//defense of the
	int uses;//uses of the item, by now it is useless, for the next release, this will be usefull
	bool inventory = false;//the item is in the inventory?
	bool equipped = false;//the item is equipped?
	bool equipable = false;//the item is equippable?
	bool inside_cupboard = true;//the item is inside a cupboard?
	bool inside_backpack = false;//the item is inside the backpack?
};

#endif //__Item__