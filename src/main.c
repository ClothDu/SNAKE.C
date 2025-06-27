#include <pdcurses.h>
#include <time.h>
#include "snake.h"
#include "libs.h"
#include "libs2.h"
#include "board.h"
#include "printboard.h"
#include "updatesStats.h"
#include "BoardLargeMenu.h"

int main()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    srand(time(NULL));

    Head *Snake = NULL;
    bool Menu = 1, Game = 1, Inloop = true;
    int l, c;
    char **board = NULL;

    while (Inloop)
    {
        nodelay(stdscr, FALSE);
        while (Menu)
        {
            BoardDefineMenu(&l, &c);
            clear();
            defineLarge(l, c, &board);
            defineStandartBoard(l, c, board);
            snakeInitial(l, c, &Snake);
            putSnakeOnBoard(l, c, board, Snake);
            break;
        }

        clock_t lastUpdate = clock();

        while (Game)
        {
            nodelay(stdscr, TRUE);
            keypad(stdscr, TRUE);
            int tecla = buttonPressed();

            if (tecla != ERR)
                updateDirection(tecla, Snake);

            clock_t now = clock();
            double delta = (double)(now - lastUpdate) / CLOCKS_PER_SEC;

            if (delta >= 0.15)
            {
                updateBodyFollow(Snake);
                updatePositioxy(Snake);
                if (colidAThing(l, c, board, Snake))
                {
                    break;
                }
                verifyEat(board, Snake);
                appleAdd(l, c, board);
                lastUpdate = now;
            }
            clear();
            
            clearAndReprintABoard(l, c, board);
            putSnakeOnBoard(l, c, board, Snake);
            printingBoard(l, c, board);

            refresh();
            napms(30);
        }
    }

    endwin();
    return 0;
}
