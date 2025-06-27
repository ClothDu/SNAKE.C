#include "libs.h"
#include "snake.h"
#include "board.h"

void snakeInitial(int l, int c, Head **start)
{
    Head *head = malloc(sizeof(Head));
    No *body = malloc(sizeof(No));

    if (head == NULL || body == NULL)
    {
        printf("Erro de alocação na cobra.\n");
        exit(1);
    }

    head->x = l / 2;
    head->y = c / 2;
    head->way = 3;
    head->body = body;
    head->snakehead = '0';

    body->x = head->x;
    body->y = head->y - 1;
    body->next = NULL;

    *start = head;
}

void putSnakeOnBoard(int l, int c, char **board, Head *snake)
{

    if (snake->x >= 0 && snake->x < l && snake->y >= 0 && snake->y < c)
    {
        board[snake->x][snake->y] = '0';
    }

    No *current = snake->body;
    while (current != NULL)
    {
        if (current->x >= 0 && current->x < l && current->y >= 0 && current->y < c)
        {
            board[current->x][current->y] = 'x';
        }
        current = current->next;
    }
}

void addSegment(Head *start)
{
    No *previw = NULL;
    No *last = start->body;

    // Vai até o último segmento
    while (last->next != NULL)
    {
        previw = last;
        last = last->next;
    }

    No *new = malloc(sizeof(No));
    if (!new)
    {
        return;
    }
    if (previw)
    {
        if (last->x < previw->x)
        {
            new->x = last->x + 1;
            new->y = last->y;
        }
        else if (last->x > previw->x)
        {
            new->x = last->x - 1;
            new->y = last->y;
        }
        else if (last->y < previw->y)
        {
            new->x = last->x;
            new->y = last->y + 1;
        }
        else if (last->y > previw->y)
        {
            new->x = last->x;
            new->y = last->y - 1;
        }
        else
        {
            new->x = last->x;
            new->y = last->y;
        }
    }
    else
    {
        new->x = start->x;
        new->y = start->y;
    }

    new->next = NULL;
    last->next = new;
}
