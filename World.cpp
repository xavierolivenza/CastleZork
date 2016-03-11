#include <stdio.h>
#include <string.h>
#include "World.h"

Rooms* rooms = nullptr;

World::World(){
	rooms = new Rooms[9];
}
World::~World(){
	delete[]rooms;
}

void CreateWorld(){
	Rooms tower1;
	Rooms tower2;
	Rooms tower3;
	Rooms tower4;
	Rooms northcorridor;
	Rooms eastcorridor;
	Rooms southcorridor;
	Rooms westcorridor;
	Rooms throneroom;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(tower1.name, "Tower 1");
	strcpy_s(tower1.description, "In this tower there is nothing interesting.");
	strcpy_s(tower1.north, "There is ananother room.");
	tower1.roomchangenorth = EASTCORRIDOR;
	strcpy_s(tower1.east, "There is a wall.");
	tower1.roomchangeeast = TOWER1;
	strcpy_s(tower1.south, "There is a wall.");
	tower1.roomchangesouth = TOWER1;
	strcpy_s(tower1.west, "There is ananother room.");
	tower1.roomchangewest = SOUTHCORRIDOR;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(tower2.name, "Tower 2");
	strcpy_s(tower2.description, "A regular tower.");
	strcpy_s(tower2.north, "There is ananother room.");
	tower2.roomchangenorth = WESTCORRIDOR;
	strcpy_s(tower2.east, "There is ananother room.");
	tower2.roomchangeeast = SOUTHCORRIDOR;
	strcpy_s(tower2.south, "There is a wall.");
	tower2.roomchangesouth = TOWER2;
	strcpy_s(tower2.west, "There is a wall.");
	tower2.roomchangewest = TOWER2;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(tower3.name, "Tower 3");
	strcpy_s(tower3.description, "In this tower there is a fireplace, probably something interesting is above it.");
	strcpy_s(tower3.north, "There is a wall.");
	tower3.roomchangenorth = TOWER3;
	strcpy_s(tower3.east, "There is ananother room.");
	tower3.roomchangeeast = NORTHCORRIDOR;
	strcpy_s(tower3.south, "There is ananother room.");
	tower3.roomchangesouth = WESTCORRIDOR;
	strcpy_s(tower3.west, "There is a wall.");
	tower3.roomchangewest = TOWER3;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(tower4.name, "Tower 4");
	strcpy_s(tower4.description, "In this tower there is a cupboard, probably something interesting is in there.");
	strcpy_s(tower4.north, "There is a wall.");
	tower4.roomchangenorth = TOWER4;
	strcpy_s(tower4.east, "There is a wall.");
	tower4.roomchangeeast = TOWER4;
	strcpy_s(tower4.south, "There is a wall.");
	tower4.roomchangesouth = TOWER4;
	strcpy_s(tower4.west, "There is a door.");
	tower4.roomchangewest = NORTHCORRIDOR;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(northcorridor.name, "North corridor");
	strcpy_s(northcorridor.description, "Nothing interesting in here.");
	strcpy_s(northcorridor.north, "There is a wall.");
	northcorridor.roomchangenorth = NORTHCORRIDOR;
	strcpy_s(northcorridor.east, "There is a door.");
	northcorridor.roomchangeeast = TOWER4;
	strcpy_s(northcorridor.south, "There is ananother room.");
	northcorridor.roomchangesouth = THRONEROOM;
	strcpy_s(northcorridor.west, "There is ananother room.");
	northcorridor.roomchangewest = TOWER3;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(eastcorridor.name, "East corridor");
	strcpy_s(eastcorridor.description, "In this corridor there's a cupboard.");
	strcpy_s(eastcorridor.north, "There is a wall.");
	eastcorridor.roomchangenorth = EASTCORRIDOR;
	strcpy_s(eastcorridor.east, "There is a wall.");
	eastcorridor.roomchangeeast = EASTCORRIDOR;
	strcpy_s(eastcorridor.south, "There is ananother room.");
	eastcorridor.roomchangesouth = TOWER1;
	strcpy_s(eastcorridor.west, "There is ananother room.");
	eastcorridor.roomchangewest = THRONEROOM;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(southcorridor.name, "South corridor");
	strcpy_s(southcorridor.description, "In this corridor there's a cupboard.");
	strcpy_s(southcorridor.north, "There is a wall.");
	southcorridor.roomchangenorth = SOUTHCORRIDOR;
	strcpy_s(southcorridor.east, "There is ananother room.");
	southcorridor.roomchangeeast = TOWER1;
	strcpy_s(southcorridor.south, "There is a wall.");
	southcorridor.roomchangesouth = SOUTHCORRIDOR;
	strcpy_s(southcorridor.west, "There is ananother room.");
	southcorridor.roomchangewest = TOWER2;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(westcorridor.name, "West corridor");
	strcpy_s(westcorridor.description, "In this corridor there's a table.");
	strcpy_s(westcorridor.north, "There is ananother room.");
	westcorridor.roomchangenorth = TOWER3;
	strcpy_s(westcorridor.east, "There is ananother room.");
	westcorridor.roomchangeeast = THRONEROOM;
	strcpy_s(westcorridor.south, "There is ananother room.");
	westcorridor.roomchangesouth = TOWER2;
	strcpy_s(westcorridor.west, "There is a wall.");
	westcorridor.roomchangewest = WESTCORRIDOR;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(throneroom.name, "Throne room");
	strcpy_s(throneroom.description, "This is de mighty Throne room of the king, people say that the treasure is hidde here.");
	strcpy_s(throneroom.north, "There is ananother room.");
	throneroom.roomchangenorth = NORTHCORRIDOR;
	strcpy_s(throneroom.east, "There is ananother room.");
	throneroom.roomchangeeast = EASTCORRIDOR;
	strcpy_s(throneroom.south, "There is a throne, and behind it a canvas.");
	throneroom.roomchangesouth = THRONEROOM;
	strcpy_s(throneroom.west, "There is ananother room.");
	throneroom.roomchangewest = WESTCORRIDOR;
	// ---------------------------------------------------------------------------------------------------------------
}