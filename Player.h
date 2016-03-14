#ifndef __Player__
#define __Player__

class Player{
public:
	char* command_split(char*);
	int check_firstcommand(char*);
	int check_secondcommand(char*);
	void executecommand1word(int);
	void executecommand2words(int, int);
};

enum commandset { LOOK, GO, OPEN, CLOSE, QUIT, HELP, ERROR };
enum directions { NORTH, EAST, SOUTH, WEST};
#endif //__Player__