#include<stdio.h>
#include<stdlib.h>
#include"structs.h"
#include"buildLevel.h"
#include"checkChar.h"
#include"fileparse.h"
#include"heroloc.h"
#include"navigate.h"
#include"roomLoc.h"


int * roomLoc(int roomNumber)
{
	if (roomNumber >=6){
	printf("this room doesn't exist\n");
	exit(0);
	}



	//variable declaration
	int * roomCorner;
	// create dynamic memory for the room location
	roomCorner = (int*)malloc(2*sizeof(int)+1);
	if (roomCorner == NULL)
	{
		printf("out of memory\n");
		exit(1);
	}

	//returns top left corner of room
	switch(roomNumber){
        	case(0):
			roomCorner[0] = 1;
			roomCorner[1] = 0;
                	break;
        	case(1):
	                roomCorner[0] = 1;
	                roomCorner[1] = 28;
                	break;
        	case(2):
                	roomCorner[0] = 1;
                	roomCorner[1] = 56;
                	break;
        	case(3):
                	roomCorner[0] = 21;
                	roomCorner[1] = 0;
                	break;
        	case(4):
                	roomCorner[0] = 21;
                	roomCorner[1] = 28;
                break;
	        case(5):
                	roomCorner[0] = 21;
                	roomCorner[1] = 56;
                break;
        }
	roomCorner[2] = '\0';
	return roomCorner;
}



