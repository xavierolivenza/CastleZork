#ifndef __Exits__
#define __Exits__

#include "Entity.h"
#include "Room.h"

enum dir { North, East, South, West };

class Exit: public Entity{
public:
	Room *origin;
	Room *destination;
public:
	Exit();
	~Exit();
public:
	dir direction;
	bool close = false;
	bool door = false;
};
// ----------------
#endif //__Exits__