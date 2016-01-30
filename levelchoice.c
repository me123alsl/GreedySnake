#include"greedysnake.h"

void drawlevel(WINDOW *level_win, int lev_item) {
	char *choices[LEV] = {
		"Level 1",
		"Level 2",
		"q for quit",
		"? for help"
	};
	wclear(level_win);
	switch (lev_item) {
		case 0:
			wattron(level_win, A_REVERSE);
			mvwaddstr(level_win, 1, 25, choices[0]);
			wattroff(level_win, A_REVERSE);
			mvwaddstr(level_win, 3, 25, choices[1]);
			mvwaddstr(level_win, 1, 90, choices[2]);
			mvwaddstr(level_win, 3, 90, choices[3]);
			break;
		case 1:
			wattron(level_win, A_REVERSE);
			mvwaddstr(level_win, 3, 25, choices[1]);
			wattroff(level_win, A_REVERSE);
			mvwaddstr(level_win, 1, 25, choices[0]);
			mvwaddstr(level_win, 1, 90, choices[2]);
			mvwaddstr(level_win, 3, 90, choices[3]);
			break;
		case 2:
			wattron(level_win, A_REVERSE);
			mvwaddstr(level_win, 1, 90, choices[2]);
			wattroff(level_win, A_REVERSE);
			mvwaddstr(level_win, 1, 25, choices[0]);
			mvwaddstr(level_win, 3, 25, choices[1]);
			mvwaddstr(level_win, 3, 90, choices[3]);
			break;
		case 3:
			wattron(level_win, A_REVERSE);
			mvwaddstr(level_win, 3, 90, choices[3]);
			wattroff(level_win, A_REVERSE);
			mvwaddstr(level_win, 1, 25, choices[0]);
			mvwaddstr(level_win, 3, 25, choices[1]);
			mvwaddstr(level_win, 1, 90, choices[2]);
			break;
	}
}

/*
void draw_borders(WINDOW *screen) {
	int x, y, i;
	getmaxyx(screen, y, x);

	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y-1, 0, "+");
	mvwprintw(screen, 0, x-1, "+");
	mvwprintw(screen, y-1, x-1, "+");

	for (i = 1; i < y-1; ++i) {
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x-1, "|");
	}

	for (i = 1; i < x-1; ++i) {
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y-1, i, "-");
	}
}
*/

void choice(WINDOW *level) {
	int key, lev_item = 0;
	drawlevel(level, lev_item);
	keypad(level, TRUE);
	curs_set(FALSE);
	noecho();
	do {
		key = wgetch(level);
		switch (key) {
			case KEY_DOWN:
				++lev_item;
				if (lev_item > LEV-1) lev_item = 0;
				break;
			case KEY_UP:
				--lev_item;
				if (lev_item < 0) lev_item = LEV-1;
				break;
			case KEY_LEFT:
				lev_item -= 2;
				if (lev_item < 0) lev_item += 4;
				break;
			case KEY_RIGHT:
				lev_item += 2;
				if (lev_item > LEV-1) lev_item -= 4;
				break;
		}
		drawlevel(level, lev_item);
		wrefresh(level);
	} while (key != '\n');
	echo();
	wgetch(level);
}
