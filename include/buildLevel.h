#ifndef ___AFERNA06_BUILDLEVEL__
#define ___AFERNA06_BUILDLEVEL__


/**
*buildLevel
*This function recieves a struct from main and prints the room that is specified 
*by the struct. It first positions the curser to the correct location. It prints
*the walls and the floors from there. Then it places all the other items within 
*room. The other items are gold pieces, monsters, etc.
*IN: struct Rooms* room - this is the struct that will be built
*	int room number - this number will determine where
*			the curser will be first positioned. From there,
*			the rest of the room will be build
*OUT: returns 0
*POST: a room specified by a line in the textfile will be build in the terminal window
*ERROR: NA
*/

int drawScreen(struct Rooms * room, int roomNum);

#endif
