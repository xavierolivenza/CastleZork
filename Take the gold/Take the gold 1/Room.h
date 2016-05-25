#ifndef __Room__
#define __Room__

#include "Entity.h"

class Room : public Entity{
public:
	Room();
	Room(const char*, const char*, bool, bool, EntityType);
	~Room();
public:
	bool cupboard = false;//there's a cupboard in the room?, they are inmobile
	bool exploitablewall = false;//there's a wall that you can explode?, only in throne room
};

#endif //__Room__