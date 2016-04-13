#ifndef __World__
#define __World__

#include <string.h>

#include "Entity.h"
#include "Exits.h"
#include "Item.h"
#include "Player.h"
#include "Room.h"
#include "String.h"

#define NUMDIRECTIONS 4
#define NUMROOMS 9
#define NUMCOMMANDS 7
#define NUMEXITS 36
#define NUMITEMS 8

class World{
public:
	Room* castlerooms = nullptr;
	Exit* exits = nullptr;
	Player* player = nullptr;
	Item* items = nullptr;
public:
	World();
	~World();
public:
	void CreateWorld()const;
};

extern World* worldexternpointer;

#endif //__World__