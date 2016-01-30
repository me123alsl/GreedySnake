#ifndef _GREEDYSNAKE_H
#define _GREEDYSNAKE_H

#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<curses.h>

#define LEV 4

void welcome(WINDOW *wel, int row, int col);
void die(char *msg);
void choice(WINDOW *level);

#endif
