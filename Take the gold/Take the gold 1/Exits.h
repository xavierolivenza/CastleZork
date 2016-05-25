#ifndef __Exits__
#define __Exits__

#include "Entity.h"
#include "Room.h"

enum directions{ north, east, south, west };

class Exit: public Entity{
public:
	Room *origin;//pointer to origin room of the exit
	Room *destination;//pointer to destination room of the exit
	directions direct;
public:
	Exit();
	Exit(const char*, const char*, Room*, Room*, bool, bool, EntityType, directions);
	~Exit();
public:
	bool close = false;//door open/close
	bool door = false;//exit with door?
};
// ----------------
#endif //__Exits__