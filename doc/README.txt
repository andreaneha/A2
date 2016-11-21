ASSIGNMENT 2
CIS 2500
ANDREA FERNANDES
0808213

COMPILATION
To compile:
gcc src/checkchar.c src/fileparse.c src/main.c src/buildLevel.c src/roomLoc.c src/navigate.c src/locatehero.c -Wall -std=c99 -lncurses -I include

To execute: 
./runme <levelfile>
- inputs must be .txt files!
	example using included files:
	./a.out assets/level.txt

USAGE
To play a simple game of rouge. User can navigate around the room pick up items, and teleport to another room though a door. 

TESTING
- enter no text files, or enter too many files
- enter invalid files
- put invalid data in text files
- specify for more that 4 doors
- specify an element that is outside of a room

KNOWN LIMITATIONS
- can not handle text with files incorrect or missing room dimensions 
- top right corner '-' charecter changes to a '.' when teleporting into that room
- can not handle file paths that do not exist - causes a segmentation fault
- does not check size of window. if the terminal window is too small, the display will be strange

REFERENCES
Standard C documentation:
http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf

random number generator:
http://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
(only the seeding was copied, this was two lines)

ncurses library documentation:
http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
