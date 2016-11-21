#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>

#include"structs.h"
#include"buildLevel.h"
#include"checkChar.h"
#include"fileparse.h"
#include"heroloc.h"
#include"navigate.h"
#include"roomLoc.h"



int drawScreen(struct Rooms * room, int roomNum){
	//initialize screen
	initscr();
	noecho();

	//declare variables
	int * roomCorner;
	int x;
	int y;
	int i;

	//initalize variables
		// roomLoc returns location of topleft corner of the room
	roomCorner = roomLoc(roomNum);
		//this location is where the curser will be set to 
	x = roomCorner[0];
	y = roomCorner[1];
	free(roomCorner);
	move(x,y);

	//draw room walls
	for(i = 0; i <room->width+2; i++)
	{
		move(x,y+i);
		printw("-");
		move(x+room->height+1, y+i);
		printw("-");
	}

	for(i = 1; i<=room->height; i++)
	{
		move(x+i, y);
		printw("|");
		move(x+i, y+room->width+1);
		printw("|");
	}
	
	//draw room floors
	for(i = 0; i<= room->height -1;i++)
	{
		int j;
		for(j = 0; j<= room->width -1; j++)
		{
			move(x+i+1,y+j+1);
			printw(".");
		}
	}
	if(room->numDoors ==0){
		endwin();
		printf("Rooms must have at least one door\n");
		exit(0);
	}
	//place doors
	for(i = 0; i < room->numDoors; i++)
	{

		switch (room->doors[i].wall){
			case 'n':
				if(room->doors[i].position+1 >= room-> width){
					endwin();
					printf("specifications for doors provided in text file fall out of room dimensions\n");
					exit(0);
				}
				move(x,y+room->doors[i].position+1);
				printw("+");
				break;
			case 'e':
				if(room->doors[i].position +1>= room-> height){
					endwin();
					printf("specifications for doors provided in text file fall out of room dimensions\n");
					exit(0);
				}
				move(x+room->doors[i].position +1, y+room->width+1);
				printw("+");
				break;
			case 's':
				if(room->doors[i].position+1 > room-> width){
					endwin();
					printf("specifications for doors provided in text file fall out of room dimensions\n");
					exit(0);
				}
				move(x+room->height+1,y+ room->doors[i].position+1);
				printw("+");
				break;
			case 'w':
				if(room->doors[i].position +1 > room-> height){
					endwin();
					printf("specifications for doors provided in text file fall out of room dimensions\n");
					exit(0);
				}
				move(x+room->doors[i].position +1,y);
				printw("+");
				break;

		}
	}

	//place all other items
	for (i=0;i< room->numOther ; i++)
	{
		move(x + room-> other[i].xlocal +1, y + room-> other[i].ylocal +1);
		printw("%c", room -> other[i].item);

		if(room-> other[i].xlocal +1 > room-> height){
			endwin();
			printf("specifications for items provided in text file fall out of room dimensions");
			exit(0);
		}
		if(room-> other[i].ylocal +1 > room-> width){
			endwin();
			printf("specifications for items provided in text file fall out of room dimensions\n");
			exit(0);
		}
	
	}


	return 0;
}


