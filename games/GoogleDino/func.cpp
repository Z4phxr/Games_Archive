#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "func.h"

char board[WYS][SZER];
din dino;
bool in_hit;
direc dir;
bool touchup;
std::vector<obstacle> obstacles;
int total_obs;


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

void create_board()
{
    total_obs = 0;
    for(int i = 0; i<WYS; i++)
    {
        if(i == WYS-2)
        {
            for(int j = 0; j<SZER; j++)
            {
                board[i][j] = '.';
            }
        }
        else
        {
            for(int j = 0; j<SZER; j++)
            {
                board[i][j] = ' ';
            }
        }

    }
}


void show()
{
    gotoxy(0, 0);
    for(int j = 0; j<SZER+2; j++)
    {
        std::cout << 'X';
    }
    std::cout << "\n";
    for(int i = 0; i<WYS; i++)
    {
        std::cout << 'X';
        for(int j = 0; j<SZER; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << 'X';
        std::cout << "\n";
    }
        for(int j = 0; j<SZER+2; j++)
    {
        std::cout << 'X';
    }

}

void create_dino()
{
    dino.y = WYS-3;
    dino.x = 8;
    dino.points = {{dino.x, dino.y, 'O'}, {dino.x, dino.y+1, 'O'}};
}

void draw(std::vector<point> points)
{
    for(point po : points)
    {
        board[po.y][po.x] = po.c;
    }
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'w':
            {
                dir = up;
                in_hit = true;
                break;
            }

        case 's':
            {
                dir = down;
                in_hit = true;
                break;
            }
        }
    }
}

void delete_point(point po)
{
    if(po.y == WYS-2)
    {
        board[po.y][po.x] = '.';
    }
    else
        board[po.y][po.x] = ' ';
}

void jump_check()
{
    if(touchup && dino.y == WYS-3)
    {
        touchup = false;
        in_hit = false;
        dir = none;
        return;
    }
    if(dino.y == WYS-7)
    {
        touchup = true;
    }
    if(!touchup)
    {
        delete_point(dino.points[1]);
        dino.y--;
        for(point& po : dino.points)
        {
            po.y--;
        }
        draw(dino.points);
        return;
    }
    else
    {
        delete_point(dino.points[0]);
        dino.y++;
        for(point& po : dino.points)
        {
            po.y++;
        }
        draw(dino.points);
    }
}

void crawl()
{
    delete_point(dino.points[0]);
    dino.points = {{dino.x-1, dino.y+1, 'O'}, {dino.x, dino.y+1, 'O'}};
    draw(dino.points);
}

void create_obs(int type)
{
    total_obs++;
    obstacle temp;
    temp.y = LINIA;
    temp.x = SZER-2;
    temp.type = type;
    switch(type)
    {
    case 0:
        {
            temp.points = {{temp.x, temp.y, '^'}};
            break;
        }
    case 1:
        {
            temp.points = {{temp.x, temp.y, '^'}, {temp.x, temp.y-1, '^'}};
            break;
        }
    case 2:
        {
            temp.points = {{temp.x, temp.y-1, '~'}};
            break;
        }
    }
    obstacles.push_back(temp);
}

void draw_obs()
{
    for(obstacle obs : obstacles)
    {
        draw(obs.points);
    }
}


void move_obs()
{
    for(obstacle& obs : obstacles)
    {
        obs.x--;
        for(point& po : obs.points)
        {
            delete_point(po);
            po.x--;
        }
    }
    for(auto it = obstacles.begin(); it!= obstacles.end();)
    {
        if(it->x == 0)
        {
            it = obstacles.erase(it);
        }
        else it++;
    }
}


bool collision()
{
    if(obstacles.size()<1)
        return false;
    for(point po : obstacles[0].points)
    {
        for(point po2 : dino.points)
        {
            if(po.x == po2.x && po.y == po2.y)
                return true;
        }
    }
    return false;
}


