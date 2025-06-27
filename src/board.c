#include "libs.h"
#include "board.h"

void defineLarge(int l, int c, char ***board)
{
    *board = malloc(l * sizeof(char*));
    if (*board == NULL)
    {
        printf("Erro ao alocar linhas.\n");
        exit(1);
    }
    for (size_t i = 0; i < l; i++)
    {
        (*board)[i] = malloc(c * sizeof(char));
        if ((*board)[i] == NULL)
        {
            exit(1);
        }
    }
}

void defineStandartBoard(int l, int c, char **board)
{
    for (size_t i = 0; i < l; i++)
    {
        for (size_t t = 0; t < c; t++)
        {
            if (i == 0)
                board[i][t] = '_';
            else if (i == l - 1)
                board[i][t] = '-';
            else if (t == 0 || t == c - 1)
                board[i][t] = '|';
            else
                board[i][t] = ' ';
        }
    }
}

void clearAndReprintABoard(int l, int c, char **board)
{
    for (size_t i = 0; i < l; i++)
    {
        for (size_t t = 0; t < c; t++)
        {
            if (i == 0)
                board[i][t] = '_';
            else if (i == l - 1)
                board[i][t] = '-';
            else if (t == 0 || t == c - 1)
                board[i][t] = '|';
            else if (board[i][t] == 'o')
                board[i][t] = 'o';
            else
                board[i][t] = ' ';
        }
    }
}