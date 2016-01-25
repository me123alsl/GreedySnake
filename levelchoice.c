#include<curses.h>
#include"greedysnake.h"
/*
void drawlevel(WINDOW *level_win, int lev_item) {
	char *level_choice[LEV] = {
		"Level 1",
		"Level 2",
		"Level 3"
	};
	wclear(level_win);
	int level_num;
	for (level_num = 0; level_num < LEV; ++level_num) {
		if (level_num == lev_item) attron(A_REVERSE);
		mvwaddstr(level_win, 3+(level_num*2), 20, level_choice[level_num]);
		attroff(A_REVERSE);
	}
	wrefresh(level_win);
}
*/
int choice() {
	WINDOW *level;
	if ((level = newwin(0, 0, 0, 0)) == NULL) {
		addstr("Unable to allocate window memory\n");
		endwin();
		exit(1);
	}

	int row, col;
	getmaxyx(level, row, col);
	char *msg = "Please use UP DOWN arrow keys to select a level and then hit <Enter> key to begin";
	int msg_len = strlen(msg);
	int center = (col - msg_len) / 2;
	// mvwaddstr(level, 3, center, msg);
	mvwprintw(level, row/2, center, "%s\n", msg);
	wrefresh(level);
	getch();

	/*
	int key, lev_item = 0;
	keypad(level, TRUE);
	noecho();
	do {
		key = getch();
		switch (key) {
			case KEY_DOWN:
				++lev_item;
				if (lev_item > LEV-1) lev_item = 0;
				break;
			case KEY_UP:
				--lev_item;
				if (lev_item < 0) lev_item = LEV-1;
				break;
			default:
				break;
		}
		drawlevel(level, lev_item);
	} while (key != '\n');
	echo();
	*/

	napms(100000);
	getch();
	return 1;
}

int main()
{
	initscr();

	choice();

	endwin();
	return 0;
}
