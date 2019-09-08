//https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/

#include <ncurses.h>

int main(void){
        initscr();                      /* Start curses mode              */
        printw("Hello World !!!");      /* Print Hello World              */
        refresh();                      /* Print it on to the real screen */
        getch();                        /* Wait for user input */
        endwin();                       /* End curses mode                */
        return 0;
}

