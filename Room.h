class Rooms{
public:
	char name[20];
	char description[250];
	char north[250];
	int roomchangenorth;
	char east[250];
	int roomchangeeast;
	char south[250];
	int roomchangesouth;
	char west[250];
	int roomchangewest;

	void create_rooms();
};

enum rooms{ TOWER1, TOWER2, TOWER3, TOWER4, NORTHCORRIDOR, EASTCORRIDOR, SOUTHCORRIDOR, WESTCORRIDOR, THRONEROOM };