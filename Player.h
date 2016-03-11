class CurrentRoom{
public:
	char name[20];
	char description[250];
	char north[250];
	char east[250];
	char south[250];
	char west[250];

	void move();
};

int check_firstcommand(char*);
int check_secondcommand(char*);

enum commandset { LOOK, GO, OPEN, CLOSE, QUIT, HELP, NORTH, EAST, SOUTH, WEST, ERROR };