#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"structs.h"
#include<time.h>
#include"structs.h"
#include"buildLevel.h"
#include"checkChar.h"
#include"fileparse.h"
#include"heroloc.h"
#include"navigate.h"
#include"roomLoc.h"



int play(int * heroLoc,int numRooms, struct Rooms ** room)
{
	//variable declarations
	int currentRoom;
	int * roomLocation;
	int x;
	int goldPoints;
	int y;
	int xoffset;
	int yoffset;
	char input;


	//place curser on hero
	currentRoom = heroLoc[2];
	roomLocation = roomLoc(currentRoom);
	x = roomLocation[0];
	y = roomLocation[1];
	free(roomLocation);
	xoffset = heroLoc[0]+1;
	yoffset = heroLoc[1]+1;
	x = x+xoffset;
	y = y+yoffset;
	mvaddch(x,y,'@');
	goldPoints=0;

	//game loop
	while (input!='q')
	{
		time_t t;
		//declare variables used in loop
		char charCheck;
//		int newRoomPosition;
		//reset offset variables
		xoffset = 0;
		yoffset = 0;
		//user input
		input = getch();
		switch(input){
			case ('w'):
				xoffset-=1;
				break;
			case('a'):
				yoffset-=1;
				break;
			case('d'):
				yoffset+=1;
				break;
			case('s'):
				xoffset+=1;
			default:
				break;
		}
		//check charecter in front of it and respond accordingly
		if (input!='q'){
		charCheck = mvinch(x+xoffset,y+yoffset);

		switch(charCheck)
		{
                	case('<'):
                        	input = 'q';
	                        break;
        	        case('>'):
                	        input = 'q';
                        	break;
	                case('*'):
				srand((unsigned) time(&t));
        	                goldPoints = goldPoints + rand() % 50;
                                mvaddch(x,y,'.');
                                x = x+xoffset;
                                y = y+yoffset;
                                mvaddch(x,y,'@');
				break;
	                case('8'):
				srand((unsigned) time(&t));
        	                goldPoints = goldPoints + 50 + rand() % 200;
                       		mvaddch(x,y,'.');
                       		x = x+xoffset;
                       		y = y+yoffset;
                       		mvaddch(x,y,'@');
                	        break;
	                case('|'):
				move(x,y);
                	       break;
	                case('-'):
				move(x,y);
                	        break;
	                case('A'):
				move(x,y);
                	        break;
	                case('T'):
				move(x,y);
                	       break;
	                case('B'):
        	                move(x,y);
                	        break;
	                case('S'):
        	                move(x,y);
				break;
	                case('Z'):
        	                move(x,y);
                	        break;
	                case('+'):
		                mvaddch(x,y,'.');

        	                if(currentRoom == numRooms-1){
					currentRoom = 0;
				}
				else{
					currentRoom++;
				}
				roomLocation = roomLoc(currentRoom);
				x = roomLocation[0];
				y = roomLocation[1];
				free(roomLocation);
				switch (room[currentRoom]->doors[0].wall){
		                        case 'n':
                	               		yoffset = room[currentRoom]->doors[0].position+1;
						xoffset = 1;
                                		break;
		                        case 'e': 
                		                yoffset= room[currentRoom]->width;
                                		xoffset = room[currentRoom]->doors[0].position +1;
                                		break;
                        		case 's':
						xoffset = room[currentRoom]-> height;
                                		yoffset = room[currentRoom]->doors[0].position+1;
                                		break;
                        		case 'w':
                                		xoffset = room[currentRoom]->doors[0].position+1;
						yoffset = 1;
						break;
                                        x = x+xoffset;
                                        y = y+yoffset;
                                        mvaddch(x,y,'@');
					break;
				}
				default:
                        		mvaddch(x,y,'.');
                        		x = x+xoffset;
                        		y = y+yoffset;
                        		mvaddch(x,y,'@');
					break;
		}
		}

	}
	clear();
	move(0,0);
	printw("Your gold count is %d\n",goldPoints);
	move(1,0);
	printw("press enter to close window\n");
	getch();
	endwin();
	return 0;
}
