#include<curses.h>
#include<stdlib.h>
#include"greedysnake.h"

int main()
{
	initscr();
	welcome();
	endwin();
	return 0;
}

void die(char *msg) {
	endwin();
	puts(msg);
	exit(1);
}
