// https://www.linuxjournal.com/content/getting-started-ncurses#main-content

     1  /* triangle.c */
     2
     3  #include <curses.h>
     4  #include <stdlib.h>
     5
     6  #include "getrandom_int.h"
     7
     8  #define ITERMAX 10000
     9
    10  int main(void)
    11  {
    12      long iter;
    13      int yi, xi;
    14      int y[3], x[3];
    15      int index;
    16      int maxlines, maxcols;
    17
    18      /* initialize curses */
    19
    20      initscr();
    21      cbreak();
    22      noecho();
    23
    24      clear();
    25
    26      /* initialize triangle */
    27
    28      maxlines = LINES - 1;
    29      maxcols = COLS - 1;
    30
    31      y[0] = 0;
    32      x[0] = 0;
    33
    34      y[1] = maxlines;
    35      x[1] = maxcols / 2;
    36
    37      y[2] = 0;
    38      x[2] = maxcols;
    39
    40      mvaddch(y[0], x[0], '0');
    41      mvaddch(y[1], x[1], '1');
    42      mvaddch(y[2], x[2], '2');
    43
    44      /* initialize yi,xi with random values */
    45
    46      yi = getrandom_int() % maxlines;
    47      xi = getrandom_int() % maxcols;
    48
    49      mvaddch(yi, xi, '.');
    50
    51      /* iterate the triangle */
    52
    53      for (iter = 0; iter < ITERMAX; iter++) {
    54          index = getrandom_int() % 3;
    55
    56          yi = (yi + y[index]) / 2;
    57          xi = (xi + x[index]) / 2;
    58
    59          mvaddch(yi, xi, '*');
    60          refresh();
    61      }
    62
    63      /* done */
    64
    65      mvaddstr(maxlines, 0, "Press any key to quit");
    66
    67      refresh();
    68
    69      getch();
    70      endwin();
    71
    72      exit(0);
    73  }

