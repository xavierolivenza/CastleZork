#ifndef __Creature__
#define __Creature__

#include "Entity.h"
#include "Room.h"

class Creature : public Entity{
public:
	Creature();
	Creature(const char*, const char*, Room*, EntityType);
	~Creature();
public:
	Room* current_room = nullptr;
	unsigned int hp = 100;//health points
	unsigned int attack = 10;//attack, modified by equipped items in player
	unsigned int defense = 0;//defense, modified by equipped items in player
};

#endif //__Creature__
