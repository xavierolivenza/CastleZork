#ifndef __Enemie_normal_soldier__
#define __Enemie_normal_soldier__

#include "Entity.h"
#include "Room.h"
#include "Creature.h"

class Enemie_normal_soldier : public Creature{
public:
	Enemie_normal_soldier();
	Enemie_normal_soldier(const char*, const char*, Room*, EntityType);
	~Enemie_normal_soldier();
public:
	Room* current_room = nullptr;
	unsigned int hp = 50;//health points
	unsigned int attack = 8;//attack, modified by equipped items in player
	unsigned int defense = 2;//defense, modified by equipped items in player
public:
	void creaturemove();
	void creatureattack();
};

#endif //__Enemie_normal_soldier__