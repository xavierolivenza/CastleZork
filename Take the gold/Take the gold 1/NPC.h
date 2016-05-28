#ifndef __NPC__
#define __NPC__

#include "Entity.h"
#include "Room.h"
#include "Creature.h"

class NPC : public Creature{
public:
	NPC();
	NPC(const char*, const char*, Room*, EntityType);
	~NPC();
public:
	virtual void NPCmove() = 0;
	virtual void NPCattack() = 0;
public:
	virtual void NPCUpdate() = 0;
};

#endif //__NPC__