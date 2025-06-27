#ifndef UPDATESTATS_H
#define UPDATESTATS_H
#include "snake.h"

void appleAdd(int l, int c, char **board);
int colidAThing(int l, int c, char **board, Head *snake);
int buttonPressed();
void updateDirection(int ch, Head *snake);
void updatePositioxy(Head *snake);
void updateBodyFollow(Head *snake);
void verifyEat(char **board, Head *start);

#endif
