#ifndef SNAKE_H
#define SNAKE_H

typedef struct no {
    int x, y;
    struct no *next;
} No;

typedef struct head {
    int x, y;
    int way;
    char snakehead;
    No *body;
} Head;

void snakeInitial(int l, int c, Head **start);
void putSnakeOnBoard(int l, int c, char **board, Head *snake);
void addSegment(Head *start);


#endif