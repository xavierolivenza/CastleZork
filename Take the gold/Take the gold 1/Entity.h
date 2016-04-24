#ifndef __Entity__
#define __Entity__

#include "String.h"

class Entity{

public:
	Entity();
	Entity(const char*, const char*);
	~Entity();

public:
	String name;
	String description;
};
// ----------------
#endif //__Entity__