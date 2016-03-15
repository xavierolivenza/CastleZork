#include <stdio.h>
#include <string.h>
#include "World.h"

World::World(){
	castlerooms = new Room[NUMROOMS];
	exits = new Exit[NUMEXITS];
	player = new Player;
	player->current_room = &castlerooms[TOWER1];
}
World::~World(){
	delete[] castlerooms;
	delete[] exits;
	delete player;
}

void World::CreateWorld(){
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER1].name, "Tower 1");
	strcpy_s(castlerooms[TOWER1].description, "In this tower there is nothing interesting, you should keep moving.");
	strcpy_s(exits[TOWER1dir1].name, "East corridor door.");
	strcpy_s(exits[TOWER1dir1].description, "There's a corridor, the east one.");
	exits[TOWER1dir1].origin = &castlerooms[TOWER1];
	exits[TOWER1dir1].destination = &castlerooms[EASTCORRIDOR];
	exits[TOWER1dir1].direction = north;
	strcpy_s(exits[TOWER1dir2].name, "Wall.");
	strcpy_s(exits[TOWER1dir2].description, "There's a wall.");
	exits[TOWER1dir2].origin = &castlerooms[TOWER1];
	exits[TOWER1dir2].destination = &castlerooms[TOWER1];
	exits[TOWER1dir2].direction = east;
	strcpy_s(exits[TOWER1dir3].name, "Wall.");
	strcpy_s(exits[TOWER1dir3].description, "There's a wall.");
	exits[TOWER1dir3].origin = &castlerooms[TOWER1];
	exits[TOWER1dir3].destination = &castlerooms[TOWER1];
	exits[TOWER1dir3].direction = south;
	strcpy_s(exits[TOWER1dir4].name, "South corridor door.");
	strcpy_s(exits[TOWER1dir4].description, "There's a corridor, the south one.");
	exits[TOWER1dir4].origin = &castlerooms[TOWER1];
	exits[TOWER1dir4].destination = &castlerooms[SOUTHCORRIDOR];
	exits[TOWER1dir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER2].name, "Tower 2");
	strcpy_s(castlerooms[TOWER2].description, "A regular tower.");
	strcpy_s(exits[TOWER2dir1].name, "West corridor door.");
	strcpy_s(exits[TOWER2dir1].description, "There's a corridor, the west one.");
	exits[TOWER2dir1].origin = &castlerooms[TOWER2];
	exits[TOWER2dir1].destination = &castlerooms[WESTCORRIDOR];
	exits[TOWER2dir1].direction = north;
	strcpy_s(exits[TOWER2dir2].name, "South corridor door.");
	strcpy_s(exits[TOWER2dir2].description, "There's a corridor, the south one.");
	exits[TOWER2dir2].origin = &castlerooms[TOWER2];
	exits[TOWER2dir2].destination = &castlerooms[SOUTHCORRIDOR];
	exits[TOWER2dir2].direction = east;
	strcpy_s(exits[TOWER2dir3].name, "Wall.");
	strcpy_s(exits[TOWER2dir3].description, "There's a wall.");
	exits[TOWER2dir3].origin = &castlerooms[TOWER2];
	exits[TOWER2dir3].destination = &castlerooms[TOWER2];
	exits[TOWER2dir3].direction = south;
	strcpy_s(exits[TOWER2dir4].name, "Wall.");
	strcpy_s(exits[TOWER2dir4].description, "There's a wall.");
	exits[TOWER2dir4].origin = &castlerooms[TOWER2];
	exits[TOWER2dir4].destination = &castlerooms[TOWER2];
	exits[TOWER2dir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER3].name, "Tower 3");
	strcpy_s(castlerooms[TOWER3].description, "In this tower there is a fireplace, probably something interesting is above it.");
	strcpy_s(exits[TOWER3dir1].name, "Wall.");
	strcpy_s(exits[TOWER3dir1].description, "There's a wall.");
	exits[TOWER3dir1].origin = &castlerooms[TOWER3];
	exits[TOWER3dir1].destination = &castlerooms[TOWER3];
	exits[TOWER3dir1].direction = north;
	strcpy_s(exits[TOWER3dir2].name, "North corridor door.");
	strcpy_s(exits[TOWER3dir2].description, "There's a corridor, the north one.");
	exits[TOWER3dir2].origin = &castlerooms[TOWER3];
	exits[TOWER3dir2].destination = &castlerooms[NORTHCORRIDOR];
	exits[TOWER3dir2].direction = east;
	strcpy_s(exits[TOWER3dir3].name, "West corridor door.");
	strcpy_s(exits[TOWER3dir3].description, "There's a corridor, the west one.");
	exits[TOWER3dir3].origin = &castlerooms[TOWER3];
	exits[TOWER3dir3].destination = &castlerooms[WESTCORRIDOR];
	exits[TOWER3dir3].direction = south;
	strcpy_s(exits[TOWER3dir4].name, "Wall.");
	strcpy_s(exits[TOWER3dir4].description, "There's a wall.");
	exits[TOWER3dir4].origin = &castlerooms[TOWER3];
	exits[TOWER3dir4].destination = &castlerooms[TOWER3];
	exits[TOWER3dir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[TOWER4].name, "Tower 4");
	strcpy_s(castlerooms[TOWER4].description, "In this tower there is a cupboard, probably something interesting is in there.");
	strcpy_s(exits[TOWER4dir1].name, "Wall.");
	strcpy_s(exits[TOWER4dir1].description, "There's a wall.");
	exits[TOWER4dir1].origin = &castlerooms[TOWER4];
	exits[TOWER4dir1].destination = &castlerooms[TOWER4];
	exits[TOWER4dir1].direction = north;
	strcpy_s(exits[TOWER4dir2].name, "Wall.");
	strcpy_s(exits[TOWER4dir2].description, "There's a wall.");
	exits[TOWER4dir2].origin = &castlerooms[TOWER4];
	exits[TOWER4dir2].destination = &castlerooms[TOWER4];
	exits[TOWER4dir2].direction = east;
	strcpy_s(exits[TOWER4dir3].name, "Wall.");
	strcpy_s(exits[TOWER4dir3].description, "There's a wall.");
	exits[TOWER4dir3].origin = &castlerooms[TOWER4];
	exits[TOWER4dir3].destination = &castlerooms[TOWER4];
	exits[TOWER4dir3].direction = south;
	strcpy_s(exits[TOWER4dir4].name, "North corridor door.");
	strcpy_s(exits[TOWER4dir4].description, "There's a corridor, the north one.");
	exits[TOWER4dir4].origin = &castlerooms[TOWER4];
	exits[TOWER4dir4].destination = &castlerooms[NORTHCORRIDOR];
	exits[TOWER4dir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[NORTHCORRIDOR].name, "North corridor");
	strcpy_s(castlerooms[NORTHCORRIDOR].description, "Nothing interesting in here.");
	strcpy_s(exits[NORTHCORRIDORdir1].name, "Wall.");
	strcpy_s(exits[NORTHCORRIDORdir1].description, "There's a wall.");
	exits[NORTHCORRIDORdir1].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir1].destination = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir1].direction = north;
	strcpy_s(exits[NORTHCORRIDORdir2].name, "Tower 4 door.");
	strcpy_s(exits[NORTHCORRIDORdir2].description, "There is the tower 4.");
	exits[NORTHCORRIDORdir2].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir2].destination = &castlerooms[TOWER4];
	exits[NORTHCORRIDORdir2].direction = east;
	strcpy_s(exits[NORTHCORRIDORdir3].name, "Throne room door.");
	strcpy_s(exits[NORTHCORRIDORdir3].description, "There is a room, the throne room.");
	exits[NORTHCORRIDORdir3].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir3].destination = &castlerooms[THRONEROOM];
	exits[NORTHCORRIDORdir3].direction = south;
	strcpy_s(exits[NORTHCORRIDORdir4].name, "Tower 3 door.");
	strcpy_s(exits[NORTHCORRIDORdir4].description, "There is the tower 3.");
	exits[NORTHCORRIDORdir4].origin = &castlerooms[NORTHCORRIDOR];
	exits[NORTHCORRIDORdir4].destination = &castlerooms[TOWER3];
	exits[NORTHCORRIDORdir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[EASTCORRIDOR].name, "East corridor");
	strcpy_s(castlerooms[EASTCORRIDOR].description, "In this corridor there's a cupboard.");
	strcpy_s(exits[EASTCORRIDORdir1].name, "Wall.");
	strcpy_s(exits[EASTCORRIDORdir1].description, "There's a wall.");
	exits[EASTCORRIDORdir1].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir1].destination = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir1].direction = north;
	strcpy_s(exits[EASTCORRIDORdir2].name, "Wall.");
	strcpy_s(exits[EASTCORRIDORdir2].description, "There's a wall.");
	exits[EASTCORRIDORdir2].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir2].destination = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir2].direction = east;
	strcpy_s(exits[EASTCORRIDORdir3].name, "Tower 1 door.");
	strcpy_s(exits[EASTCORRIDORdir3].description, "There is the tower 1.");
	exits[EASTCORRIDORdir3].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir3].destination = &castlerooms[TOWER1];
	exits[EASTCORRIDORdir3].direction = south;
	strcpy_s(exits[EASTCORRIDORdir4].name, "Throne room door.");
	strcpy_s(exits[EASTCORRIDORdir4].description, "There is a room, the throne room.");
	exits[EASTCORRIDORdir4].origin = &castlerooms[EASTCORRIDOR];
	exits[EASTCORRIDORdir4].destination = &castlerooms[THRONEROOM];
	exits[EASTCORRIDORdir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[SOUTHCORRIDOR].name, "South corridor");
	strcpy_s(castlerooms[SOUTHCORRIDOR].description, "In this corridor there's a cupboard.");
	strcpy_s(exits[SOUTHCORRIDORdir1].name, "Wall.");
	strcpy_s(exits[SOUTHCORRIDORdir1].description, "There's a wall.");
	exits[SOUTHCORRIDORdir1].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir1].destination = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir1].direction = north;
	strcpy_s(exits[SOUTHCORRIDORdir2].name, "Tower 1 door.");
	strcpy_s(exits[SOUTHCORRIDORdir2].description, "There is the tower 1.");
	exits[SOUTHCORRIDORdir2].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir2].destination = &castlerooms[TOWER1];
	exits[SOUTHCORRIDORdir2].direction = east;
	strcpy_s(exits[SOUTHCORRIDORdir3].name, "Wall.");
	strcpy_s(exits[SOUTHCORRIDORdir3].description, "There's a wall.");
	exits[SOUTHCORRIDORdir3].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir3].destination = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir3].direction = south;
	strcpy_s(exits[SOUTHCORRIDORdir4].name, "Tower 2 door.");
	strcpy_s(exits[SOUTHCORRIDORdir4].description, "There is the tower 2.");
	exits[SOUTHCORRIDORdir4].origin = &castlerooms[SOUTHCORRIDOR];
	exits[SOUTHCORRIDORdir4].destination = &castlerooms[TOWER2];
	exits[SOUTHCORRIDORdir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[WESTCORRIDOR].name, "West corridor");
	strcpy_s(castlerooms[WESTCORRIDOR].description, "In this corridor there's a table.");
	strcpy_s(exits[WESTCORRIDORdir1].name, "Tower 2 door.");
	strcpy_s(exits[WESTCORRIDORdir1].description, "There is the tower 2.");
	exits[WESTCORRIDORdir1].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir1].destination = &castlerooms[TOWER3];
	exits[WESTCORRIDORdir1].direction = north;
	strcpy_s(exits[WESTCORRIDORdir2].name, "Throne room door.");
	strcpy_s(exits[WESTCORRIDORdir2].description, "There is a room, the throne room.");
	exits[WESTCORRIDORdir2].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir2].destination = &castlerooms[THRONEROOM];
	exits[WESTCORRIDORdir2].direction = east;
	strcpy_s(exits[WESTCORRIDORdir3].name, "Tower 3 door.");
	strcpy_s(exits[WESTCORRIDORdir3].description, "There is the tower 3.");
	exits[WESTCORRIDORdir3].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir3].destination = &castlerooms[TOWER3];
	exits[WESTCORRIDORdir3].direction = south;
	strcpy_s(exits[WESTCORRIDORdir4].name, "Wall.");
	strcpy_s(exits[WESTCORRIDORdir4].description, "There's a wall.");
	exits[WESTCORRIDORdir4].origin = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir4].destination = &castlerooms[WESTCORRIDOR];
	exits[WESTCORRIDORdir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
	strcpy_s(castlerooms[THRONEROOM].name, "Throne room");
	strcpy_s(castlerooms[THRONEROOM].description, "This is the mighty throne room of the king, people say that the treasure is hidden here.");
	strcpy_s(exits[THRONEROOMdir1].name, "North corridor door.");
	strcpy_s(exits[THRONEROOMdir1].description, "There's a corridor, the north one.");
	exits[THRONEROOMdir1].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir1].destination = &castlerooms[NORTHCORRIDOR];
	exits[THRONEROOMdir1].direction = north;
	strcpy_s(exits[THRONEROOMdir2].name, "East corridor door.");
	strcpy_s(exits[THRONEROOMdir2].description, "There's a corridor, the east one.");
	exits[THRONEROOMdir2].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir2].destination = &castlerooms[EASTCORRIDOR];
	exits[THRONEROOMdir2].direction = east;
	strcpy_s(exits[THRONEROOMdir3].name, "Wall.");
	strcpy_s(exits[THRONEROOMdir3].description, "There's a wall with a canvas.");
	exits[THRONEROOMdir3].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir3].destination = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir3].direction = south;
	strcpy_s(exits[THRONEROOMdir4].name, "West corridor door.");
	strcpy_s(exits[THRONEROOMdir4].description, "There's a corridor, the west one.");
	exits[THRONEROOMdir4].origin = &castlerooms[THRONEROOM];
	exits[THRONEROOMdir4].destination = &castlerooms[WESTCORRIDOR];
	exits[THRONEROOMdir4].direction = west;
	// ---------------------------------------------------------------------------------------------------------------
}

void World::executecommand1word(int command1, int& actual_position){
	int exitnum = 0, roomnum = 0;
	player->current_room = &castlerooms[actual_position];

	if (command1 == NORTH){
		for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
			if (exitnum % 4 == 0){//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
				if (exits[exitnum].origin == player->current_room){
					
					for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
							actual_position = roomnum;
							player->current_room = exits[exitnum].destination;
							printf("Now you are in %s\n\n", player->current_room);
							return;
					}
				}
			}
		}
	}
	else if (command1 == EAST){
		for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
			if (exitnum % 4 == 1){//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
				if (exits[exitnum].origin == player->current_room){
					for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
						if (exits[exitnum].destination == &castlerooms[roomnum]){
							player->current_room = exits[exitnum].destination;
							printf("Now you are in %s\n\n", player->current_room);
							actual_position = roomnum;
							return;
						}
					}
				}
			}
		}
	}
	else if (command1 == SOUTH){
		for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
			if (exitnum % 4 == 2){//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
				if (exits[exitnum].origin == player->current_room){
					for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
						if (exits[exitnum].destination == &castlerooms[roomnum]){
							player->current_room = exits[exitnum].destination;
							printf("Now you are in %s\n\n", player->current_room);
							actual_position = roomnum;
							return;
						}
					}
				}
			}
		}
	}
	else if (command1 == WEST){
		for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
			if (exitnum % 4 == 3){//North exits are each 4 exits, starting from 0, North exits = 3, 7, 11, 15, 19...
				if (exits[exitnum].origin == player->current_room){
					for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
						if (exits[exitnum].destination == &castlerooms[roomnum]){
							player->current_room = exits[exitnum].destination;
							printf("Now you are in %s\n\n", player->current_room);
							actual_position = roomnum;
							return;
						}
					}
				}
			}
		}
	}
	else if (command1 == LOOK){
		printf("%s\n", castlerooms[actual_position].description, actual_position);
	}
	else if (command1 == QUIT){

	}
	else if (command1 == HELP){
		printf("In this game you can move using:\nn/s/e/w\nnorth/east/south/west\ngo north/go east/go south/go west\nalso you can use the commands:\nlook->to see the description of the room where you are\nlook+north/east/south/west->to see the description of the path\nopen/close+north/east/south/west->to open/close door\nquit->to quit the game\n");
	}
	else{
		printf("That's not a valid command.\n");
	}
}

void World::executecommand2words(int command1, int command2, int& actual_position){

	int exitnum = 0, roomnum = 0;
	player->current_room = &castlerooms[actual_position];
	// ---------------------------------------------------------------------------------------------------------------
	if (command1 == LOOK){
		if ((command2 == NORTH)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 0){//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
					if (exits[exitnum].origin == player->current_room){
							printf("%s\n\n", exits[exitnum].description);
							return;
					}
				}
			}
		}
		else if ((command2 == EAST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 1){//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
					if (exits[exitnum].origin == player->current_room){
						printf("%s\n\n", exits[exitnum].description);
						return;
					}
				}
			}
		}
		else if ((command2 == SOUTH)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 2){//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
					if (exits[exitnum].origin == player->current_room){
						printf("%s\n\n", exits[exitnum].description);
						return;
					}
				}
			}
		}
		else if ((command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 0){//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
					if (exits[exitnum].origin == player->current_room){
						printf("%s\n\n", exits[exitnum].description);
						return;
					}
				}
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == GO){
		if ((command2 == NORTH)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 0){//North exits are each 4 exits, starting from 0, North exits = 0, 4, 8, 12, 16...
					if (exits[exitnum].origin == player->current_room){

						for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
							actual_position = roomnum;
							player->current_room = exits[exitnum].destination;
							printf("Now you are in %s\n\n", player->current_room);
							return;
						}
					}
				}
			}
		}
		else if ((command2 == EAST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 1){//East exits are each 4 exits, starting from 1, East exits = 1, 5, 9, 13...
					if (exits[exitnum].origin == player->current_room){
						for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
							if (exits[exitnum].destination == &castlerooms[roomnum]){
								player->current_room = exits[exitnum].destination;
								printf("Now you are in %s\n\n", player->current_room);
								actual_position = roomnum;
								return;
							}
						}
					}
				}
			}
		}
		else if ((command2 == SOUTH)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 2){//South exits are each 4 exits, starting from 2, South exits = 2, 6, 10, 14, 18...
					if (exits[exitnum].origin == player->current_room){
						for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
							if (exits[exitnum].destination == &castlerooms[roomnum]){
								player->current_room = exits[exitnum].destination;
								printf("Now you are in %s\n\n", player->current_room);
								actual_position = roomnum;
								return;
							}
						}
					}
				}
			}
		}
		else if ((command2 == WEST)){
			for (exitnum = 0; exitnum < NUMEXITS; exitnum++){
				if (exitnum % 4 == 3){//North exits are each 4 exits, starting from 0, North exits = 3, 7, 11, 15, 19...
					if (exits[exitnum].origin == player->current_room){
						for (roomnum = 0; roomnum < NUMROOMS; roomnum++){
							if (exits[exitnum].destination == &castlerooms[roomnum]){
								player->current_room = exits[exitnum].destination;
								printf("Now you are in %s\n\n", player->current_room);
								actual_position = roomnum;
								return;
							}
						}
					}
				}
			}
		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == OPEN){
		if ((command2 == NORTH)){

		}
		else if ((command2 == EAST)){

		}
		else if ((command2 == SOUTH)){

		}
		else if ((command2 == WEST)){

		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else if (command1 == CLOSE){
		if ((command2 == NORTH)){

		}
		else if ((command2 == EAST)){

		}
		else if ((command2 == SOUTH)){

		}
		else if ((command2 == WEST)){

		}
		else{
			printf("That's not a valid command.\n");
		}
	}
	// ---------------------------------------------------------------------------------------------------------------
	else{
		printf("That's not a valid command.\n");
	}
}