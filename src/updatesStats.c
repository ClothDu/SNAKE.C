#include <pdcurses.h>
#include <time.h>
#include "snake.h"
#include "updatesStats.h"
#include "libs.h"
#include "libs2.h"
#include "board.h"

void appleAdd(int l, int c, char **board)
{
    bool exist = false;

    for (int i = 0; i < l; i++)
    {
        for (int t = 0; t < c; t++)
        {
            if (board[i][t] == 'o')
            {
                exist = true;
                break;
            }
        }
        if (exist)
        {
            break;
        }
    }

    if (!exist)
    {
        int lr, cr;
        do
        {
            lr = rand() % l;
            cr = rand() % c;
        } while (board[lr][cr] != ' ');

        board[lr][cr] = 'o';
    }
}


int colidAThing(int l, int c, char **board, Head *snake)
{
    if (!snake)
    {
        return 0;
    }
    if (board[snake->x][snake->y] != ' ' && board[snake->x][snake->y] != '0' && board[snake->x][snake->y] != 'o')
    {
        return 1;
    }
    return 0;
}

int buttonPressed()
{
    return getch();
}

void updateDirection(int ch, Head *snake)
{
    if (!snake)
    {
        return;
    }
    switch (ch)
    {
    case KEY_UP:
        if (snake->way != 2)
            snake->way = 1;
        break;
    case KEY_DOWN:
        if (snake->way != 1)
            snake->way = 2;
        break;
    case KEY_RIGHT:
        if (snake->way != 4)
            snake->way = 3;
        break;
    case KEY_LEFT:
        if (snake->way != 3)
            snake->way = 4;
        break;
    }
}

void updateBodyFollow(Head *snake)
{
    if (!snake || !snake->body)
    {
        return;
    }
    int prevX = snake->x;
    int prevY = snake->y;

    No *current = snake->body;
    while (current)
    {
        int tempX = current->x;
        int tempY = current->y;

        current->x = prevX;
        current->y = prevY;

        prevX = tempX;
        prevY = tempY;

        current = current->next;
    }
}

void updatePositioxy(Head *snake)
{
    if (!snake)
    {
        return;
    }
    switch (snake->way)
    {
    case 1:
        snake->x--;
        break;
    case 2:
        snake->x++;
        break;
    case 3:
        snake->y++;
        break;
    case 4:
        snake->y--;
        break;
    }
}

void verifyEat(char **board, Head *start)
{
    if (board[start->x][start->y] == 'o')
    {
        printw("%c", start->snakehead);
        addSegment(start);
    }
}