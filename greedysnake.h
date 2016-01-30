#ifndef _GREEDYSNAKE_H
#define _GREEDYSNAKE_H

#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<curses.h>

#define LEV 4
#define N 100 /* the longest of the greedy snake */

struct food {
	int row;
	int col;
	int flag; /* whether food should appear or not */
};

struct snake {
	int row[N];
	int col[N];
	int node;
	int direction;
	int life;
};

void welcome(WINDOW *wel, int row, int col);
void die(char *msg);
void choice(WINDOW *level);

#endif
