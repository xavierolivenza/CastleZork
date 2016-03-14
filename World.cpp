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
	strcpy_s(exits[TOWER1dir1].description, "There's a corridor, the east one.");
	exits[TOWER1dir1].origin = &castlerooms[TOWER1];
	exits[TOWER1dir1].destination = &castlerooms[EASTCORRIDOR];
	strcpy_s(exits[TOWER1dir2].description, "There's a wall.");
	exits[TOWER1dir2].origin = &castlerooms[TOWER1];
	exits[TOWER1dir2].destination = &castlerooms[TOWER1];
	strcpy_s(exits[TOWER1dir3].description, "There's a wall.");
	exits[TOWER1dir3].origin = &castlerooms[TOWER1];
	exits[TOWER1dir3].destination = &castlerooms[TOWER1];
	strcpy_s(exits[TOWER1dir4].description, "There's a corridor, the south one.");
	exits[TOWER1dir4].origin = &castlerooms[TOWER1];
	exits[TOWER1dir4].destination = &castlerooms[SOUTHCORRIDOR];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER2].name, "Tower 2");
	strcpy_s(castlerooms[TOWER2].description, "A regular tower.");
	strcpy_s(exits[TOWER2dir1].description, "There's a corridor, the west one.");
	exits[TOWER2dir1].origin = &castlerooms[TOWER2];
	exits[TOWER2dir1].destination = &castlerooms[WESTCORRIDOR];
	strcpy_s(exits[TOWER2dir2].description, "There's a corridor, the south one.");
	exits[TOWER2dir2].origin = &castlerooms[TOWER2];
	exits[TOWER2dir2].destination = &castlerooms[SOUTHCORRIDOR];
	strcpy_s(exits[TOWER2dir3].description, "There's a wall.");
	exits[TOWER2dir3].origin = &castlerooms[TOWER2];
	exits[TOWER2dir3].destination = &castlerooms[TOWER2];
	strcpy_s(exits[TOWER2dir4].description, "There's a wall.");
	exits[TOWER2dir4].origin = &castlerooms[TOWER2];
	exits[TOWER2dir4].destination = &castlerooms[TOWER2];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER3].name, "Tower 3");
	strcpy_s(castlerooms[TOWER3].description, "In this tower there is a fireplace, probably something interesting is above it.");
	strcpy_s(exits[TOWER3dir1].description, "There's a wall.");
	exits[TOWER3dir1].origin = &castlerooms[TOWER3];
	exits[TOWER3dir1].destination = &castlerooms[TOWER3];
	strcpy_s(exits[TOWER3dir2].description, "There's a corridor, the north one.");
	exits[TOWER3dir2].origin = &castlerooms[TOWER3];
	exits[TOWER3dir2].destination = &castlerooms[NORTHCORRIDOR];
	strcpy_s(exits[TOWER3dir3].description, "There's a corridor, the west one.");
	exits[TOWER3dir3].origin = &castlerooms[TOWER3];
	exits[TOWER3dir3].destination = &castlerooms[WESTCORRIDOR];
	strcpy_s(exits[TOWER3dir4].description, "There's a wall.");
	exits[TOWER3dir4].origin = &castlerooms[TOWER3];
	exits[TOWER3dir4].destination = &castlerooms[TOWER3];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER4].name, "Tower 4");
	strcpy_s(castlerooms[TOWER4].description, "In this tower there is a cupboard, probably something interesting is in there.");
	strcpy_s(exits[TOWER4dir1].description, "There's a wall.");
	exits[TOWER4dir1].origin = &castlerooms[TOWER4];
	exits[TOWER4dir1].destination = &castlerooms[TOWER4];
	strcpy_s(exits[TOWER4dir2].description, "There's a wall.");
	exits[TOWER4dir2].origin = &castlerooms[TOWER4];
	exits[TOWER4dir2].destination = &castlerooms[TOWER4];
	strcpy_s(exits[TOWER4dir3].description, "There's a wall.");
	exits[TOWER4dir3].origin = &castlerooms[TOWER4];
	exits[TOWER4dir3].destination = &castlerooms[TOWER4];
	strcpy_s(exits[TOWER4dir4].description, "There's a corridor, the north one.");
	exits[TOWER4dir4].origin = &castlerooms[TOWER4];
	exits[TOWER4dir4].destination = &castlerooms[NORTHCORRIDOR];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[NORTHCORRIDOR].name, "North corridor");
	strcpy_s(castlerooms[NORTHCORRIDOR].description, "Nothing interesting in here.");
	strcpy_s(exits[NORTHCORRIDORdir1].description, "There's a wall.");
	exits[NORTHCORRIDORdir1].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir1].destination = &castlerooms[NORTHCORRIDOR];
	strcpy_s(exits[NORTHCORRIDORdir2].description, "There is the tower 4.");
	exits[NORTHCORRIDORdir2].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir2].destination = &castlerooms[TOWER4];
	strcpy_s(exits[NORTHCORRIDORdir3].description, "There is a room, the throne room.");
	exits[NORTHCORRIDORdir3].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir3].destination = &castlerooms[THRONEROOM];
	strcpy_s(exits[NORTHCORRIDORdir4].description, "There is the tower 3.");
	exits[NORTHCORRIDORdir4].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir4].destination = &castlerooms[TOWER3];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[EASTCORRIDOR].name, "East corridor");
	strcpy_s(castlerooms[EASTCORRIDOR].description, "In this corridor there's a cupboard.");
	strcpy_s(exits[EASTCORRIDORdir1].description, "There's a wall.");
	exits[EASTCORRIDORdir1].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir1].destination = &castlerooms[EASTCORRIDOR];
	strcpy_s(exits[EASTCORRIDORdir2].description, "There's a wall.");
	exits[EASTCORRIDORdir2].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir2].destination = &castlerooms[EASTCORRIDOR];
	strcpy_s(exits[EASTCORRIDORdir3].description, "There is the tower 1.");
	exits[EASTCORRIDORdir3].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir3].destination = &castlerooms[TOWER1];
	strcpy_s(exits[EASTCORRIDORdir4].description, "There is a room, the throne room.");
	exits[EASTCORRIDORdir4].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir4].destination = &castlerooms[THRONEROOM];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[SOUTHCORRIDOR].name, "South corridor");
	strcpy_s(castlerooms[SOUTHCORRIDOR].description, "In this corridor there's a cupboard.");
	strcpy_s(exits[SOUTHCORRIDORdir1].description, "There's a wall.");
	exits[SOUTHCORRIDORdir1].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir1].destination = &castlerooms[SOUTHCORRIDOR];
	strcpy_s(exits[SOUTHCORRIDORdir2].description, "There is the tower 1.");
	exits[SOUTHCORRIDORdir2].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir2].destination = &castlerooms[TOWER1];
	strcpy_s(exits[SOUTHCORRIDORdir3].description, "There's a wall.");
	exits[SOUTHCORRIDORdir3].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir3].destination = &castlerooms[SOUTHCORRIDOR];
	strcpy_s(exits[SOUTHCORRIDORdir4].description, "There is the tower 2.");
	exits[SOUTHCORRIDORdir4].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir4].destination = &castlerooms[TOWER2];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[WESTCORRIDOR].name, "West corridor");
	strcpy_s(castlerooms[WESTCORRIDOR].description, "In this corridor there's a table.");
	strcpy_s(exits[WESTCORRIDORdir1].description, "There is the tower 2.");
	exits[WESTCORRIDORdir1].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir1].destination = &castlerooms[TOWER2];
	strcpy_s(exits[WESTCORRIDORdir2].description, "There is a room, the throne room.");
	exits[WESTCORRIDORdir2].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir2].destination = &castlerooms[THRONEROOM];
	strcpy_s(exits[WESTCORRIDORdir3].description, "There is the tower 3.");
	exits[WESTCORRIDORdir3].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir3].destination = &castlerooms[TOWER3];
	strcpy_s(exits[WESTCORRIDORdir4].description, "There's a wall.");
	exits[WESTCORRIDORdir4].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir4].destination = &castlerooms[WESTCORRIDOR];
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[THRONEROOM].name, "Throne room");
	strcpy_s(castlerooms[THRONEROOM].description, "This is de mighty Throne room of the king, people say that the treasure is hidde here.");
	strcpy_s(exits[THRONEROOMdir1].description, "There's a corridor, the north one.");
	exits[THRONEROOMdir1].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir1].destination = &castlerooms[NORTHCORRIDOR];
	strcpy_s(exits[THRONEROOMdir2].description, "There's a corridor, the east one.");
	exits[THRONEROOMdir2].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir2].destination = &castlerooms[EASTCORRIDOR];
	strcpy_s(exits[THRONEROOMdir3].description, "There's a wall with a canvas.");
	exits[THRONEROOMdir3].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir3].destination = &castlerooms[THRONEROOM];
	strcpy_s(exits[THRONEROOMdir4].description, "There's a corridor, the west one.");
	exits[THRONEROOMdir4].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir4].destination = &castlerooms[WESTCORRIDOR];
	// ---------------------------------------------------------------------------------------------------------------
}