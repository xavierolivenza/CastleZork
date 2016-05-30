#ifndef __Enemie_moving_soldier__
#define __Enemie_moving_soldier__

#include "Entity.h"
#include "Room.h"
#include "NPC.h"

class Enemie_moving_soldier : public NPC{
public:
	Enemie_moving_soldier();
	Enemie_moving_soldier(const char*, const char*, Room*, EntityType);
	~Enemie_moving_soldier();
public:
	Room* current_room = nullptr;
	unsigned int hp = 40;//health points
	unsigned int attack = 5;//attack, modified by equipped items in player
	unsigned int defense = 0;//defense, modified by equipped items in player
public:
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int currenttime2 = 0;
	unsigned int initialtime2 = 0;
public:
	void NPCmove();
	void NPCattack();
	void NPCUpdate();
};

#endif //__Enemie_moving_soldier__