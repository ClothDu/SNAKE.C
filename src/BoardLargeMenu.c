#include <pdcurses.h>
#include "libs.h"
#include "BoardLargeMenu.h"

void BoardDefineMenu(int *l, int *c)
{
    bool inLoop = true;
    nodelay(stdscr, FALSE);
    echo();
    while (inLoop)
    {
        clear();
        mvprintw(1, 1, "high of board: ");
        scanw("%d", l);
        mvprintw(1, 1, "large of board: ");
        scanw("%d", c);
        if (*l < 11 || *c < 11)
        {
            printw("too small board\n");
        }
        else if (*l > 100 || *c > 100)
        {
            printw("too large board\n");
        }
        else if (*l <= 0 || *c <= 0)
        {
            printw("invalid large\n");
        }
        else
        {
            break;
        }
        mvprintw(6, 1, "Press any key to return to a number selection\n");
        getch();
    }
    noecho();
    nodelay(stdscr, TRUE);
}