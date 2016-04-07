#ifndef __Item__
#define __Item__

#include "Entity.h"

class Item : public Entity{
public:
	Item();
	~Item();
public:
	int attack;
	int defense;
	bool inventory = false;
	bool equiped = false;
};

#endif //__Item__