// https://www.linuxjournal.com/content/programming-color-ncurses

/*

Color Essentials

Before you can use colors, your program needs to know if it can rely on the terminal to display the colors correctly. On
modern systems, this always should be true. But in the classic days of computing, some terminals were monochromatic, such as
the venerable VT52 and VT100 terminals, usually providing white-on-black or green-on-black text.

To query the terminal capability for colors, use the has_colors() function. This will return a true value if the terminal
can display color, and a false value if not. It is usually used to start an if block, like this:


if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
}


Having determined that the terminal can display color, you then can set up curses to use colors with the start_color()
function. Now you're ready to define the colors your program will use.

In curses, you define colors in pairs: a foreground color on a background color. This allows curses to set both color
attributes at once, which often is what you want to do. To establish a color pair, use init_pair() to define a foreground
and background color, and associate it to an index number. The general syntax is:


init_pair(index, foreground, background);


Consoles support only eight basic colors: black, red, green, yellow, blue, magenta, cyan and white. These colors are defined
for you with the following names:

  • COLOR_BLACK
  • COLOR_RED
  • COLOR_GREEN
  • COLOR_YELLOW
  • COLOR_BLUE
  • COLOR_MAGENTA
  • COLOR_CYAN
  • COLOR_WHITE


To make my color pairs easy to remember, my program defines a few symbolic constants:


#define GRASS_PAIR     1
#define EMPTY_PAIR     1
#define WATER_PAIR     2
#define MOUNTAIN_PAIR  3
#define PLAYER_PAIR    4


With these constants, my color definitions become:


start_color();
init_pair(GRASS_PAIR, COLOR_YELLOW, COLOR_GREEN);
init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
init_pair(MOUNTAIN_PAIR, COLOR_BLACK, COLOR_WHITE);
init_pair(PLAYER_PAIR, COLOR_RED, COLOR_MAGENTA);

*/








int is_move_okay(int y, int x)
{
    int testch;

    /* return true if the space is okay to move into */

    testch = mvinch(y, x);
    return (((testch & A_CHARTEXT) == GRASS)
            || ((testch & A_CHARTEXT) == EMPTY));
}




/* quest.c */

#include <curses.h>
#include <stdlib.h>

#define GRASS     ' '
#define EMPTY     '.'
#define WATER     '~'
#define MOUNTAIN  '^'
#define PLAYER    '*'

#define GRASS_PAIR     1
#define EMPTY_PAIR     1
#define WATER_PAIR     2
#define MOUNTAIN_PAIR  3
#define PLAYER_PAIR    4

int is_move_okay(int y, int x);
void draw_map(void);





int main(void)
{
    int y, x;
    int ch;

    /* initialize curses */

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();

    /* initialize colors */

    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }

    start_color();
    init_pair(GRASS_PAIR, COLOR_YELLOW, COLOR_GREEN);
    init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
    init_pair(MOUNTAIN_PAIR, COLOR_BLACK, COLOR_WHITE);
    init_pair(PLAYER_PAIR, COLOR_RED, COLOR_MAGENTA);

    clear();

    /* initialize the quest map */

    draw_map();

    /* start player at lower-left */

    y = LINES - 1;
    x = 0;

    do {

        /* by default, you get a blinking cursor - use it to
           indicate player * */

        attron(COLOR_PAIR(PLAYER_PAIR));
        mvaddch(y, x, PLAYER);
        attroff(COLOR_PAIR(PLAYER_PAIR));
        move(y, x);
        refresh();

        ch = getch();

        /* test inputted key and determine direction */

        switch (ch) {
        case KEY_UP:
        case 'w':
        case 'W':
            if ((y > 0) && is_move_okay(y - 1, x)) {
                attron(COLOR_PAIR(EMPTY_PAIR));
                mvaddch(y, x, EMPTY);
                attroff(COLOR_PAIR(EMPTY_PAIR));
                y = y - 1;
            }
            break;
        case KEY_DOWN:
        case 's':
        case 'S':
            if ((y < LINES - 1) && is_move_okay(y + 1, x)) {
                attron(COLOR_PAIR(EMPTY_PAIR));
                mvaddch(y, x, EMPTY);
                attroff(COLOR_PAIR(EMPTY_PAIR));
                y = y + 1;
            }
            break;
        case KEY_LEFT:
        case 'a':
        case 'A':
            if ((x > 0) && is_move_okay(y, x - 1)) {
                attron(COLOR_PAIR(EMPTY_PAIR));
                mvaddch(y, x, EMPTY);
                attroff(COLOR_PAIR(EMPTY_PAIR));
                x = x - 1;
            }
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            if ((x < COLS - 1) && is_move_okay(y, x + 1)) {
                attron(COLOR_PAIR(EMPTY_PAIR));
                mvaddch(y, x, EMPTY);
                attroff(COLOR_PAIR(EMPTY_PAIR));
                x = x + 1;
            }
            break;
        }
    }
    while ((ch != 'q') && (ch != 'Q'));

    endwin();

    exit(0);
}








int is_move_okay(int y, int x)
{
    int testch;

    /* return true if the space is okay to move into */

    testch = mvinch(y, x);
    return (((testch & A_CHARTEXT) == GRASS)
            || ((testch & A_CHARTEXT) == EMPTY));
}




void draw_map(void)
{
    int y, x;

    /* draw the quest map */

    /* background */

    attron(COLOR_PAIR(GRASS_PAIR));
    for (y = 0; y < LINES; y++) {
        mvhline(y, 0, GRASS, COLS);
    }
    attroff(COLOR_PAIR(GRASS_PAIR));

    /* mountains, and mountain path */

    attron(COLOR_PAIR(MOUNTAIN_PAIR));
    for (x = COLS / 2; x < COLS * 3 / 4; x++) {
        mvvline(0, x, MOUNTAIN, LINES);
    }
    attroff(COLOR_PAIR(MOUNTAIN_PAIR));

    attron(COLOR_PAIR(GRASS_PAIR));
    mvhline(LINES / 4, 0, GRASS, COLS);
    attroff(COLOR_PAIR(GRASS_PAIR));

    /* lake */

    attron(COLOR_PAIR(WATER_PAIR));
    for (y = 1; y < LINES / 2; y++) {
        mvhline(y, 1, WATER, COLS / 3);
    }
    attroff(COLOR_PAIR(WATER_PAIR));
}





