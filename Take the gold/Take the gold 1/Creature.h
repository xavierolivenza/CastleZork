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
	unsigned int attack = 0;//attack, modified by equipped items in player
	unsigned int defense = 0;//defense, modified by equipped items in player
public:
	virtual void creaturemove() = 0;
	virtual void creatureattack() = 0;
};

#endif //__Creature__
