#ifndef __Enemie_seller__
#define __Enemie_seller__

#include "Entity.h"
#include "Room.h"
#include "NPC.h"

class Enemie_seller : public NPC{
public:
	Enemie_seller();
	Enemie_seller(const char*, const char*, Room*, EntityType);
	~Enemie_seller();
public:
	Room* current_room = nullptr;
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int hp = 10;//health points
	unsigned int attack = 0;//attack, modified by equipped items in player
	unsigned int defense = 0;//defense, modified by equipped items in player
public:
	void NPCmove();
	void NPCattack();
	void NPCUpdate();
};

#endif //__Enemie_seller__