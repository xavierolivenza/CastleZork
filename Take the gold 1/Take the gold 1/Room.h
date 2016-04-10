#ifndef __Room__
#define __Room__

#include "Entity.h"

class Room : public Entity{
public:
	Room();
	~Room();
public:
	bool cupboard = false;
};

#endif //__Room__