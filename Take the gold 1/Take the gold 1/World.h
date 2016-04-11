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
#define NUMITEMS 7

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
	void dropeditemslook()const;
	void executecommand1word(const int, int&)const;
	void executecommand2words(const int, const int, int&)const;
	void executecommand4words(const int, const int, const int, const int, int&)const;
};
#endif //__World__