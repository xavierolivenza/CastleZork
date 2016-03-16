#ifndef __Exits__
#define __Exits__

#define TEXTLENGTH 100
#include "Room.h"

class Exit{
public:
	Room *origin;
	Room *destination;
public:
	Exit();
	~Exit();
public:
	char name[25];
	char description[TEXTLENGTH];
	bool close = false;
	bool door = false;
};

enum roomsdirs{ 
	TOWER1dir1, 
	TOWER1dir2,
	TOWER1dir3,
	TOWER1dir4,
	// ----------------
	TOWER2dir1,
	TOWER2dir2,
	TOWER2dir3,
	TOWER2dir4,
	// ----------------
	TOWER3dir1,
	TOWER3dir2,
	TOWER3dir3,
	TOWER3dir4,
	// ----------------
	TOWER4dir1,
	TOWER4dir2,
	TOWER4dir3,
	TOWER4dir4,
	// ----------------
	NORTHCORRIDORdir1,
	NORTHCORRIDORdir2,
	NORTHCORRIDORdir3,
	NORTHCORRIDORdir4, 
	// ----------------
	EASTCORRIDORdir1, 
	EASTCORRIDORdir2,
	EASTCORRIDORdir3,
	EASTCORRIDORdir4,
	// ----------------
	SOUTHCORRIDORdir1,
	SOUTHCORRIDORdir2,
	SOUTHCORRIDORdir3,
	SOUTHCORRIDORdir4, 
	// ----------------
	WESTCORRIDORdir1, 
	WESTCORRIDORdir2,
	WESTCORRIDORdir3,
	WESTCORRIDORdir4,
	// ----------------
	THRONEROOMdir1, 
	THRONEROOMdir2,
	THRONEROOMdir3,
	THRONEROOMdir4
};
// ----------------
#endif //__Exits__