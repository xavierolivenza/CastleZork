#ifndef __Room__
#define __Room__

#define TEXTLENGTH 100

class Room{
public:
	Room();
	~Room();
public:
	char name[25];
	char description[TEXTLENGTH];
};

#endif //__Room__