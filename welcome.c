#include"greedysnake.h"

void welcome() {
	char *greedy[14] = {
		"   ################      ##############         ################     ##################     ################      ##              ## ",
		"  ##                    ##            ##       ##                    ##                     ##             ##      ##            ##  ",
		" ##                    ##              ##     ##                     ##                     ##              ##      ##          ##   ",
		" ##                    ##              ##     ##                     ##                     ##              ##       ##        ##    ",
		" ##                    ##              ##     ##                     ##                     ##              ##        ##      ##     ",
		" ##                    ##             ##      ##                     ##                     ##              ##         ##    ##      ",
		" ##                    ################       ##################     ##################     ##              ##          ##  ##       ",
		" ##                    ##                     ##                     ##                     ##              ##           ####        ",
		" ################      ####                   ##                     ##                     ##              ##            ##         ",
		" ##             ##     ## ##                  ##                     ##                     ##              ##            ##         ",
		" ##              ##    ##  ##                 ##                     ##                     ##              ##            ##         ",
		" ##              ##    ##   ##                ##                     ##                     ##              ##            ##         ",
		"  ##             ##    ##    ##                ##                    ##                      ##             ##            ##         ",
		"   ################    ##     ###########       ################     ##################       ################            ##         "
	};
	char *snake[14] = {
		"   #####################    ########            ###               #               ##      ###############    ####################### ",
		"  ##                        ##### ###           ###              ###              ##     ##                  ##                      ",
		" ##                         ### ### ##          ###             ## ##             ##    ##                   ##                      ",
		" ##                         ###  ## ###         ###            ##   ##            ##   ##                    ##                      ",
		" ##                         ###   ### ##        ###           ##     ##           ##  ##                     ##                      ",
		" ##                         ###    ## ###       ###          ##       ##          ## ##                      ##                      ",
		" #######################    ###     ### ##      ###         ##         ##         ####                       ####################### ",
		"                      ##    ###      ## ###     ###        ##           ##        ####                       ##                      ",
		"                      ##    ###       ### ##    ###       ##             ##       ## ##                      ##                      ",
		"                      ##    ###        ## ###   ###      ##               ##      ##  ##                     ##                      ",
		"                      ##    ###         ### ##  ###     #####################     ##   ##                    ##                      ",
		"                      ##    ###          ## ### ###    #######################    ##    ##                   ##                      ",
		"                     ##     ###           ### #####    ##                   ##    ##     ##                  ##                      ",
		" #####################      ###            ########    ##                   ##    ##      ###############    ####################### "
	};

	// Create a welcome window which exactly the same size as stdscr.
	WINDOW *wel;
	if ((wel = newwin(0, 0, 0, 0)) == NULL) {
		die("Unable to allocate window memory\n");
	}

	int row, col;
	getmaxyx(wel, row, col);
	char *message = "You font size is too big. You need to adjust the font size of you terminal so you can see the whole effects!\nNow hit any key to terminate the program and then press CTRL_- to adjust the font size of your terminal!\n";
	if (row < 30 || col < 135) {
		int i;
		for (i = 0; i < strlen(message); ++i) {
			addch(message[i]);
			napms(15);
			refresh();
		}
		getch();
		endwin();
		exit(1);
	}

	/* first test for color ability of the terminal */
	if (!has_colors()) {
		die("Terminal cannot do colors.");
	}
	/* next attempt to initialize curses colors */
	if (start_color() != OK) {
		die("Unable to start colors.");
	}

	int len = strlen(greedy[0]);

	/* Center the wel_msg */
	char *wel_msg = "Welcome to Greedy Snake!";
	int wel_msg_len = strlen(wel_msg);
	int indent = len - wel_msg_len;
	mvwaddstr(wel, 32, indent/2, wel_msg);
	wrefresh(wel);

	/* 0 -> black, 1 -> red, 2 -> green, 3 -> yellow,
	 * 4 -> blue, 5 -> magenta, 6 -> cyan, 7 -> white. */
	int i, j, color_pair;
	for (i = 0; i < 14; ++i) {
		color_pair = i;
		init_pair(color_pair, i % COLORS, i % COLORS);
		attrset(COLOR_PAIR(color_pair));
		for (j = 0; j < len; ++j) {
			mvwaddch(wel, i, j, greedy[i][j]);
			wrefresh(wel);
			napms(2);
			mvwaddch(wel, i+16, len-1-j, snake[i][len-1-j]);
			wrefresh(wel);
		}
	}
	sleep(3);
	getch();
}
