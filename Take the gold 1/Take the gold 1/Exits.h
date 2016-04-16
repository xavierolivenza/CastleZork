#ifndef __Exits__
#define __Exits__

#include "Entity.h"
#include "Room.h"

class Exit: public Entity{
public:
	Room *origin;
	Room *destination;
public:
	Exit();
	Exit(const char*, const char*, Room*, Room*, bool, bool);
	~Exit();
public:
	bool close = false;
	bool door = false;
};
// ----------------
#endif //__Exits__