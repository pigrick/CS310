#include <curses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP_MARGIN 4
#define BOT_MARGIN 2
#define SIDE_MARGIN 6
#define INSTR_LINES 2
#define MAXITEMS LINES - INSTR_LINES - TOP_MARGIN - BOT_MARGIN
#define LABEL_WIDTH 5
#define BELL() printf("\007")
#define MIN(a,b) ((a) > (b) ? b : a)
#define MAX(a,b) ((a) < (b) ? b : a)

typedef char *String;
static int y_0, x_0;

int menu_select(int dim, String items[], String title){
	int choice, old_choice = 1;
	char c;
	WINDOW *menu_scr;
	WINDOW *setup_menu(int, String items[], String);

	int display_choice(WINDOW *scr, int choice, int old_choice){
		if(dim > MAXITEMS){
			fprintf(stderr, "too many items on menu\n");
			exit(1);
		}
		menu_scr = setup_menu(dim, items, title);
		for (;;){
			choice = retrieve_choice(dim, old_choice);
			if(choice < 0) return (old_choice);
			if(choice != old_choice){
				display_choice(menu_scr, choice, old_choice);
				old_choice = choice;
			}
		}
	}
}

int max_length(int dim, String items[]) {
	int max = 0;
	int i;
	int len;
	for (i = 0; i < dim; i++) {
		String *s = items[i];
		for (len =0; s[len] != '\0'; len++);
		if (len > max) {
			max = len;
		}
	}
	return max;
}


WINDOW *setup_menu(int dim, String items[], String title){
	int tlen, maxlen, i, tx, mid_x, menu_lines, menu_cols;
	WINDOW *menu_scr;
	tlen = strlen(title);
	maxlen = max_length(dim, items) + LABEL_WIDTH;
	menu_cols = MAX(tlen, maxlen) + 2*SIDE_MARGIN;
	if(menu_cols > COLS){
		fprintf(stderr, "menu items too long.\n");
		exit(1);
	}
	menu_lines = dim + TOP_MARGIN + BOT_MARGIN;
	menu_scr = subwin(stdscr, menu_lines, menu_cols, 0, 0);
	box(menu_scr,'*','*');
	mid_x = menu_cols/2;
	tx = mid_x - (tlen/2);
	wstandout(menu_scr);
	mvwaddstr(menu_scr, 2, tx, title);
	wstandend(menu_scr);
	y_0 = 3;
	x_0 = MIN(mid_x - maxlen/2, tx);
	for( i = 1; i<=dim; i++){
		labeling(menu_scr, i, y_0+i, x_0, i == 1);
		mvwaddstr(menu_scr, y_0+i, x_0+LABEL_WIDTH, items[i+1]);
	}
	mvaddstr(LINES-INSTR_LINES, 0, "TYPE A DIGIT, +, - OR <SPACE BAR> TO REACH AN ITEM,");
	mvaddstr(LINES-INSTR_LINES+1, 0, "<RETURN> TO FINALIZE CHOICE.");
	refresh();
	return(menu_scr);
}

labeling(WINDOW *scr, int no, int y, int x, int standout_flag){
	char label[LABEL_WIDTH];
	if(standout_flag) wstandout(scr);
	sprintf(label, "(%d)\0", no);
	mvwaddstr(scr,y ,x, label);
	if(standout_flag) wstandend(scr);
}

int retrieve_choice(int total_items, int old_choice){
	char c;
	int choice;
	while(c = getchar()){
		if (c == '\n') return (-1);
		if (c == ' ' || c == '+' ){
			choice = old_choice + 1;
			if(choice > total_items) choice = 1;
			return (choice);
		}
		if( c == '-'){
			choice = old_choice - 1;
			if (choice == 0) choice = total_items;
			return (choice);
		}
		choice = c - '0';
		if(choice > total_items || choice > 9){
			BELL();
		} else {
			return (choice);
		}
	}
}

void display_choice(WINDOW *scr, int choice, int old_choice){
	labeling(scr, old_choice, y_0 + old_choice, x_0, 0);
	labeling(scr, choice, y_0 + choice, x_0, 1);
	refresh();
}

void init(){
	fflush(stdin);
	fflush(stdout);
	noecho();
	crmode();
}

void cleanup();

void normal_end(){
	mvcur(0, COLS-1, LINES-1, 0);
	cleanup();
	endwin();
	putchar('\n');
}

void cleanup(){
	clear();
	refresh();
	fflush(stdin);
	fflush(stdout);
}

void abnormal_end(){
	normal_end();
	exit(1);
}

int main(int argc, String argv[]){
	int choice;
	initscr();
	init();
	signal(SIGINT, abnormal_end);
	choice = menu_select(argc - 2, argv+2, argv[1]);
	normal_end();
	printf("(%d) selected\n", choice);
	return(0);
}


