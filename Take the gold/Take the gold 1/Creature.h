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
};

#endif //__Creature__
