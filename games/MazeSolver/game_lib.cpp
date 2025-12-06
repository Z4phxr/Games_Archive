#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "game_lib.h"

void gotoxy(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = false;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


char** create_board(int wys, int szer)
{
    char **tab = (char**) malloc(wys*sizeof(char*));
    tab[0] = (char*) malloc(wys*szer*sizeof(char));
    for(int i = 0; i<wys; i++)
    {
        tab[i] = tab[0] + i*szer;
    }

    for(int i = 0; i<wys; i++)
    {
            for(int j = 0; j<szer; j++)
            {
                tab[i][j] = ' ';
            }
    }
    return tab;
}

void show(char** board, int wys, int szer)
{
    gotoxy(0, 0);
    for(int i = 0; i<wys; i++)
    {

        for(int j = 0; j<szer; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}

void draw(std::vector<point> points, char** board)
{
    for(point po : points)
    {
        board[po.y][po.x] = po.c;
    }
}

void draw(point po, char** board)
{
    board[po.y][po.x] = po.c;
}



void delete_point(point po, char** board, char** board_template)
{
    board[po.y][po.x] = board_template[po.y][po.x];
}

void move_point(point* po, int dir, char **board, char** board_template, int wys, int szer)
{
    delete_point(*po, board, board_template);
    switch(dir)
    {
    case up:
        {
            po->y--;
            break;
        }
    case down:
        {
            po->y++;
            break;
        }
    case leftt:
        {
            po->x--;
            break;
        }
    case rightt:
        {
            po->x++;
            break;
        }

    }
        draw(*po, board);
}



int is_branch(point Aya, point last, char** board, int wys, int szer)
{
    int c = 0;
    if(Aya.y<wys-1)
    {
        if(board[Aya.y+1][Aya.x] == ' ' && !(last.x == Aya.x && last.y == Aya.y+1))
        {
            c++;
        }
    }
    if(Aya.y>0)
    {
        if(board[Aya.y-1][Aya.x] == ' ' && !(last.x == Aya.x && last.y == Aya.y-1))
        {
            c++;
        }
    }
    if(Aya.x<szer-1)
    {
        if(board[Aya.y][Aya.x+1] == ' ' && !(last.x == Aya.x+1 && last.y == Aya.y))
        {
            c++;
        }
    }

    if(Aya.x>0)
    {
        if(board[Aya.y][Aya.x-1] == ' ' && !(last.x == Aya.x-1 && last.y == Aya.y))
        {
            c++;
        }
    }
    return c;
}

bool is_right_free(point Aya, direction dir, char** board, int wys, int szer)
{
    switch(dir)
    {
    case down:
        {
            if(Aya.x-1>0 && board[Aya.y][Aya.x-1]==' ')
            {
                return true;
            }
            return false;
        }
    case leftt:
        {
            if(Aya.y-1>0 && board[Aya.y-1][Aya.x]==' ')
            {
                return true;
            }
            return false;
        }
    case up:
        {
            if(Aya.x+1<szer-1 && board[Aya.y][Aya.x+1]==' ')
            {
                return true;
            }
            return false;
        }
    case rightt:
        {
            if(Aya.y+1<wys && board[Aya.y+1][Aya.x]==' ')
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

direction change_dire(direction dire)
{
    direction dire1;
    switch(dire)
            {
            case down:
                {
                    dire1 = leftt;
                    break;
                }
            case leftt:
                {
                    dire1 = up;
                    break;
                }
            case up:
                {
                    dire1 = rightt;
                    break;
                }
            case rightt:
                {
                    dire1 = down;
                    break;
                }
            }
            return dire1;
}

bool is_stuck(point Aya, direction dire, char** board, int wys, int szer)
{
    switch(dire)
            {
            case down:
                {
                    if(Aya.y+1<=wys && board[Aya.y+1][Aya.x]!=' ')
                        return true;
                    else
                        return false;
                }
            case leftt:
                {
                    if(Aya.x-1>=0 && board[Aya.y][Aya.x-1]!=' ')
                        return true;
                    else
                        return false;
                }
            case up:
                {
                    if(Aya.y-1>=0 && board[Aya.y-1][Aya.x]!=' ')
                        return true;
                    else
                        return false;
                }
            case rightt:
                {
                    if(Aya.x+1<=szer-1 && board[Aya.y][Aya.x+1]!=' ')
                        return true;
                    else
                        return false;
                }
            }
    return false;
}
