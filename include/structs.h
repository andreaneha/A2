#ifndef ___AFERNA06_STRUCTS__
#define ___AFERNA06_STRUCTS__

typedef struct Rooms{
	int height;
	int width;
	int numDoors;
	struct Doors{
        	char wall;
        	int position;
	}doors[4];
	int numOther;
	struct Other{
		char item;
		int xlocal;
		int ylocal;
		int count;
	}other[10];

}Room;

#endif
