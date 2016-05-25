#ifndef __World__
#define __World__

#include <string.h>

#include "MemLeaks.h"
#include "Entity.h"
#include "Exits.h"
#include "Item.h"
#include "Player.h"
#include "Room.h"
#include "String.h"
#include "Vector.h"

#define NUMROOMS 9
#define NUMEXITS 36
#define NUMITEMS 9

class World{
public:
	Vector <Entity*> entities;
	Player* player = nullptr;
public:
	World();
	~World();
public:
	void CreateWorld();
};

extern World* worldexternpointer;

#endif //__World__