#include"snake.h"

void Drawlevel(WINDOW *level_win, int lev_item) {
	char *choices[LEV] = {
		"Level 1",
		"Level 2",
		"Level 3"
	};

	wclear(level_win);
	switch (lev_item) {
		case 0:
			wattron(level_win, A_REVERSE);
			mvwaddstr(level_win, 2, 23, choices[0]);
			wattroff(level_win, A_REVERSE);
			mvwaddstr(level_win, 2, 62, choices[1]);
			mvwaddstr(level_win, 2, 100, choices[2]);
			break;
		case 1:
			wattron(level_win, A_REVERSE);
			mvwaddstr(level_win, 2, 62, choices[1]);
			wattroff(level_win, A_REVERSE);
			mvwaddstr(level_win, 2, 23, choices[0]);
			mvwaddstr(level_win, 2, 100, choices[2]);
			break;
		case 2:
			wattron(level_win, A_REVERSE);
			mvwaddstr(level_win, 2, 100, choices[2]);
			wattroff(level_win, A_REVERSE);
			mvwaddstr(level_win, 2, 23, choices[0]);
			mvwaddstr(level_win, 2, 62, choices[1]);
			break;
	}
}

int Choice(WINDOW *level) {
	int key, lev_item = 0;
	Drawlevel(level, lev_item);
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
				lev_item -= 1;
				if (lev_item < 0) lev_item += 3;
				break;
			case KEY_RIGHT:
				lev_item += 1;
				if (lev_item > LEV-1) lev_item -= 3;
				break;
		}
		Drawlevel(level, lev_item);
		wrefresh(level);
	} while (key != '\n');
	echo();
	if (lev_item == 0) return 80;
	else if (lev_item == 1) return 50;
	else return 20;
}
