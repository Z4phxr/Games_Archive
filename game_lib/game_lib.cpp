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
    for(int j = 0; j<szer+2; j++)
    {
        std::cout << 'X';
    }
    std::cout << "\n";
    for(int i = 0; i<wys; i++)
    {
        std::cout << 'X';
        for(int j = 0; j<szer; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << 'X';
        std::cout << "\n";
    }
        for(int j = 0; j<szer+2; j++)
    {
        std::cout << 'X';
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


bool collision_point(point po1, point po2)
{
    if(po1.x == po2.x && po1.y == po2.y)
        return true;
    return false;
}

bool collision_obj(std::vector<point> points1, std::vector<point> points2)
{
    for(point po1 : points1)
    {
        for(point po2 : points2)
            if(collision_point(po1, po2))
                return true;
    }
    return false;
}

void delete_point(point po, char** board, char** board_template)
{
    board[po.y][po.x] = board_template[po.y][po.x];
}



void move_point(point* po, int dir, char **board, char** board_template, int wys, int szer)
{
    if(dir)
    {
        delete_point(*po, board, board_template);
        if (dir & up    && po->y > 0)        po->y--;
        if (dir & down  && po->y < wys - 1)  po->y++;
        if (dir & left  && po->x > 0)        po->x--;
        if (dir & right && po->x < szer - 1) po->x++;
        draw(*po, board);

    }
}


void move_obj(obstacle* ob, int dir, char **board, char** board_template, int wys, int szer)
{

    for(point& po : ob->points)
    {
        move_point(&po, dir, board, board_template, wys, szer);
        draw(po, board);
    }

}

int Input()
{
    int direction = none;
    while (_kbhit())
        switch (_getch())
        {
            case 'w':
                direction |= up;
                break;
            case 's':
                direction |= down;
                break;
            case 'a':
                direction |= left;
                break;
            case 'd':
                direction |= right;
                break;
        }
    return direction;

}



void follow(point* po, point goal, char **board, char** board_temp, int wys, int szer)
{
    if(goal.x < po->x)
        move_point(po, left, board, board_temp, wys, szer);
    if(goal.x>po->x)
        move_point(po, right, board, board_temp, wys, szer);
    if(goal.y < po->y)
        move_point(po, up, board, board_temp, wys, szer);
    if(goal.y> po->y)
        move_point(po, down, board, board_temp, wys, szer);
    else
        return;
}
