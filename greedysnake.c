#include"greedysnake.h"

int main()
{
	int parent_x, parent_y;

	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, parent_y, parent_x);
	WINDOW *welwin = newwin(28, parent_x, 0, 0);
	WINDOW *lelwin = newwin(29, parent_x, 29, 0);
	if (!welwin || !lelwin) {
		die("Unable to allocate window memory\n");
	}
	welcome(welwin, 29, parent_x);
	choice(lelwin);
	endwin();
	return 0;
}
