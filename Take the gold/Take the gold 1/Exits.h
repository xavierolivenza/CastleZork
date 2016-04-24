#ifndef __Exits__
#define __Exits__

#include "Entity.h"
#include "Room.h"

class Exit: public Entity{
public:
	Room *origin;//pointer to origin room of the exit
	Room *destination;//pointer to destination room of the exit
public:
	Exit();
	Exit(const char*, const char*, Room*, Room*, bool, bool);
	~Exit();
public:
	bool close = false;//door open/close
	bool door = false;//exit with door?
};
// ----------------
#endif //__Exits__