#include <stdio.h>
#include <string.h>
#include "World.h"

World::World(){
	castlerooms = new Room[NUMROOMS];
	exits = new Exit[NUMEXITS];
	player = new Player;
}
World::~World(){
	delete[] castlerooms;
	delete[] exits;
	delete player;
}

void World::CreateWorld(){
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER1].name, "Tower 1");
	strcpy_s(castlerooms[TOWER1].description, "In this tower there is nothing interesting.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER2].name, "Tower 2");
	strcpy_s(castlerooms[TOWER2].description, "A regular tower.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER3].name, "Tower 3");
	strcpy_s(castlerooms[TOWER3].description, "In this tower there is a fireplace, probably something interesting is above it.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER4].name, "Tower 4");
	strcpy_s(castlerooms[TOWER4].description, "In this tower there is a cupboard, probably something interesting is in there.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[NORTHCORRIDOR].name, "North corridor");
	strcpy_s(castlerooms[NORTHCORRIDOR].description, "Nothing interesting in here.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[EASTCORRIDOR].name, "East corridor");
	strcpy_s(castlerooms[EASTCORRIDOR].description, "In this corridor there's a cupboard.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[SOUTHCORRIDOR].name, "South corridor");
	strcpy_s(castlerooms[SOUTHCORRIDOR].description, "In this corridor there's a cupboard.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[WESTCORRIDOR].name, "West corridor");
	strcpy_s(castlerooms[WESTCORRIDOR].description, "In this corridor there's a table.");
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[THRONEROOM].name, "Throne room");
	strcpy_s(castlerooms[THRONEROOM].description, "This is de mighty Throne room of the king, people say that the treasure is hidde here.");
	// ---------------------------------------------------------------------------------------------------------------
}