#include <pdcurses.h>
#include "libs.h"
#include "libs2.h"
#include "printboard.h"

void printingBoard(int l, int c, char **board)
{
    for (size_t i = 0; i < l; i++)
    {
        for (size_t t = 0; t < c; t++)
        {
            if (board[i][t] == '_' || board[i][t] == '-')
            {
                printw("%c ", board[i][t]);
            }
            else if (board[i][t] == ' ')
            {
                printw("%c ", board[i][t]);
            }
            else if (board[i][t] == 'x')
            {
                attron(COLOR_PAIR(2));
                printw("%c ", board[i][t]);
                attroff(COLOR_PAIR(2));
            }
            else if (board[i][t] == '0')
            {
                attron(COLOR_PAIR(2));
                printw("%c ", board[i][t]);
                attroff(COLOR_PAIR(2));
            }
            else if (board[i][t] == 'o')
            {
                attron(COLOR_PAIR(1));
                printw("%c ", board[i][t]);
                attroff(COLOR_PAIR(1));
            }
            else
            {
                printw("%c", board[i][t]);
            }
        }
        printw("\n");
    }
}
