typedef struct _game{
	board Board;
	person player[3];
	int numTurn;

}game;

typedef struct _board{
	int regions[19];     //(purple, yellow yellow;
	int roll[19];        //(6 10 8;

}board;

typedef struct _player{
    int numPlayer;
	position posCampuses[];
	position posArcGrants[];
	int kpi;


}player;

typedef struct _position{
	int x;
	int y;
	int direction;

}position;

//define cartesian coord system startin from campusA1 = 0,0
