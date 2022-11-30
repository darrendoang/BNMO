#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tictactoe.h"


char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int check = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                check--;
            }
        }
    }
    return check;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void playerMove()
{
    int x, y;
    do
    {
        printf("Masukan row(1-3): ");
        char *inputrow;
        inputrow = READINPUT();
        x = StrToInt_input(inputrow, str_len(inputrow));
        x--;
        printf("Masukan column(1-3): ");
        char *inputcolumn;
        inputcolumn = READINPUT();
        y = StrToInt_input(inputcolumn, str_len(inputcolumn));
        y--;
        if (board[x][y] != ' ')
        {
            printf("Masukan Tidak Valid\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()
{
    // random angka
    srand(time(0));
    int x, y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

char checkWinner()
{
    //row check 
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //column check
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // diagonal check
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

void printWinner(char winner )
{
    if (winner == PLAYER)
    {
        int score = 100;
        printf("Anda Menang!\n");
        printf("Score : %i\n" , score);
    }
    else if (winner == COMPUTER)
    {
        int score = 0;
        printf("Anda Kalah! Computer Menang!\n");
        printf("Score : %i\n" , score);
    }
    else
    {
        printf("Permainan Seri!\n");
    }
}

int tictactoe()
{
    printf("TICTACTOE\n");

    char winner = ' ';
    winner = ' ';
    resetBoard();
    while (winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }
    printBoard();
    printWinner(winner);
    
    printf("Terima Kasih telah bermain TICTACTOE!\n");
    if (winner == PLAYER)
    {
        return 100;
    }
    else if (winner == COMPUTER)
    {
        return 0;
    }
    else
    {
        return 50;
    }
}

