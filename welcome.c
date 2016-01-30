#include"greedysnake.h"

void welcome(WINDOW *wel, int row, int col) {
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
	char *message = "You font size is too big. You need to adjust the font size of you terminal so you can see the whole effects!\nNow hit any key to terminate the program and then press CTRL_- to adjust the font size of your terminal!\n";
	if (row < 28 || col < 135) {
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

	/* Center the wel_msg
	char *wel_msg = "Welcome to Greedy Snake!";
	int wel_msg_len = strlen(wel_msg);
	int indent = len - wel_msg_len;
	mvwaddstr(wel, 32, indent/2, wel_msg);
	wrefresh(wel);
	*/

	/* 0 -> black, 1 -> red, 2 -> green, 3 -> yellow,
	 * 4 -> blue, 5 -> magenta, 6 -> cyan, 7 -> white. */
	int i, j, color_pair;
	for (i = 0; i < 14; ++i) {
		for (j = 0; j < len; ++j) {
			color_pair = i;
			if ((i+j)%COLORS == COLOR_BLACK) init_pair(color_pair, (i+j+1)%COLORS, COLOR_BLACK);
			else init_pair(color_pair, (i+j) % COLORS, COLOR_BLACK);
			wattron(wel, COLOR_PAIR(color_pair));
			mvwaddch(wel, i, j, greedy[i][j]);
			wrefresh(wel);
			napms(1);
			mvwaddch(wel, i+14, len-1-j, snake[i][len-1-j]);
			wrefresh(wel);
			wattroff(wel, COLOR_PAIR(color_pair));
		}
	}
}
