#ifndef __World__
#define __World__

#include <string.h>
#include "Room.h"
#include "Player.h"
#include "Exits.h"

#define NUMDIRECTIONS 4
#define NUMROOMS 9
#define NUMCOMMANDS 7
#define NUMEXITS 36

class World{
public:
	Room* castlerooms = nullptr;
	Exit* exits = nullptr;
	Player* player = nullptr;
public:
	World();
	~World();
public:
	void CreateWorld();
	void executecommand1word(int, int&);
	void executecommand2words(int, int, int&);
};
#endif //__World__