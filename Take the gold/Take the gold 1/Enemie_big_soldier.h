#ifndef __Enemie_big_soldier__
#define __Enemie_big_soldier__

#include "Entity.h"
#include "Room.h"
#include "NPC.h"

class Enemie_big_soldier : public NPC{
public:
	Enemie_big_soldier();
	Enemie_big_soldier(const char*, const char*, Room*, EntityType);
	~Enemie_big_soldier();
public:
	Room* current_room = nullptr;
	unsigned int hp = 100;//health points
	unsigned int attack = 16;//attack, modified by equipped items in player
	unsigned int defense = 4;//defense, modified by equipped items in player
public:
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
public:
	void NPCmove();
	void NPCattack();
	void NPCUpdate();
};

#endif //__Enemie_big_soldier__