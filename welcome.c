#include<curses.h>
#include<stdlib.h>
#include<string.h>

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
		addstr("Unable to allocate window memory\n");
		endwin();
		exit(1);
	}
	int row, col;
	getmaxyx(wel, row, col);
	char *message = "You font size is too big. You need to adjust the font size of you terminal so you can see the whole effects!\nNow hit any key to terminate the program and then press CTRL_- to adjust the font size of your terminal!\n";
	if (row < 30 || col < 135) {
		int i;
		for (i = 0; i < strlen(message); ++i) {
			addch(message[i]);
			napms(30);
			refresh();
		}
		getch();
		endwin();
		exit(1);
	}

	int len = strlen(greedy[0]);

	// Center the wel_msg
	char *wel_msg = "Welcome to Greedy Snake!";
	int wel_msg_len = strlen(wel_msg);
	int indent = len - wel_msg_len;
	mvwaddstr(wel, 32, indent/2, wel_msg);
	wrefresh(wel);
	int i, j;
	for (i = 0; i < 14; ++i) {
		for (j = 0; j < len; ++j) {
			mvwaddch(wel, i, j, greedy[i][j]);
			napms(1);
			mvwaddch(wel, i+16, len-1-j, snake[i][len-1-j]);
			wrefresh(wel);
		}
	}

	getch();
}

int main()
{
	initscr();
	welcome();
	endwin();
	return 0;
}
