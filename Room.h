#ifndef __Room__
#define __Room__

#define TEXTLENGTH 100

class Room{
public:
	char name[20];
	char description[TEXTLENGTH];
};

enum rooms{TOWER1, TOWER2, TOWER3, TOWER4, NORTHCORRIDOR, EASTCORRIDOR, SOUTHCORRIDOR, WESTCORRIDOR, THRONEROOM};
#endif //__Room__