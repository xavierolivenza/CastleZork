#ifndef __Entity__
#define __Entity__

#include "String.h"

enum EntityType{ EXIT, ITEM, PLAYER, ROOM , ENEMIE, MOVINGENEMIE, BIGENEMIE, SELLER};

class Entity{

public:
	Entity();
	Entity(const char*, const char*, EntityType);
	~Entity();

public:
	EntityType type;
	String name;
	String description;
};
// ----------------
#endif //__Entity__