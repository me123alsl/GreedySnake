#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<curses.h>

#define LEV 3 				/* three level choices */
#define MAX_LENGTH 100  	/* the longest of the greedy snake */
#define SNAKE_BODY '#'
#define SNAKE_HEAD '@'
#define FOOD '*'

#define TOP_ROW 5 			/* top_row */
#define BUT_ROW LINES - 1
#define LEFT_EDGE 0
#define RIGHT_EDGE COLS - 1

// the direction of the snake
enum direction { UP, DOWN, LEFT, RIGHT };

// the body node of the snake
typedef struct {
	enum direction curdirection;
	enum direction backdirection;
	int row;
	int col;
} snakeNode;

typedef snakeNode* psnakeNode;

// the head node of the snake
typedef struct {
	int row;
	int col;
	enum direction headdirection;
	int length;
	psnakeNode pbody;
} snakeHead;

typedef snakeHead* psnakeHead;

// the position struct
typedef struct {
	int row;
	int col;
} position;

typedef position* pPosition;

// Initial the snake using the head node
psnakeNode InitSnake(psnakeHead head);

void Grow(psnakeHead head);  //Snake grows

//control the moving of the snake using keyboard
void ControlSnake(int key,psnakeHead head);    //Control the snake using keyboard

// if the snake is enough long ??
// the array that contains  the snake is limited to MAX_LENGTH
int IsEnoughLong(psnakeHead head);      //the snake is enough long

// Display the snake in the screen 
void DisplaySnake(psnakeHead head);   //Show the snake on  the stdscr

// Find the new position of the body node in the next step
void FindBodyNewPosition(psnakeNode p);

// Find the new position of the head node in the next step
void FindHeadNewPosition(psnakeHead p);

// Find all nodes of the snake using the fun FindNewBodyPosition() and FindHeadNewPosition
void MoveSnake(psnakeHead head);   //move the snake in the next step

// Fill the place of the snake with ' '
void ClearSnake(psnakeHead head);    //Clear the snake

// Judge if the food position is the same as the body of the snake
// use it in the function DisplayFood() to show the food
int IsInSnake(psnakeHead head,int row,int col);

position DisplayFood(psnakeHead head);    //display the food

// if the game is failed?
//the head hits the wall or hits its body
int IsFail(psnakeHead head);

// The Welcome Greedy screen
void Welcome(WINDOW *wel, int row, int col);

// If there's errors, exit the program
void Die(char *msg);

// Level choices below welcome greedy snake
int Choice(WINDOW *level);

#endif
