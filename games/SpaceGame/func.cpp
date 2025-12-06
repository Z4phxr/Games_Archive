#include <vector>
#include <conio.h>
#include <windows.h>
#include "func.h"
#include <iostream>

char board[WYS][SZER];
std::vector<point> shots;
std::vector<point> enemies;
class ship steve;
int dir;
int active_shots;
bool end_flag;
int score;

void gotoxy(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void create_board()
{
    for(int i = 0 ; i<WYS; i++)
    {
        for(int j = 0; j<SZER; j++)
        {
            if(i%2)
            {
                board[i][j] = ' ';
            }
            else
            {
                board[i][j] = '.';
            }
        }
    }
}

void show()
{
    gotoxy(0, 0);
    for(int j = 0; j<SZER+2; j++)
        {
            std::cout << '#';
        }
    std::cout << "\n#";
    for(int i = 0 ; i<WYS; i++)
    {
        for(int j = 0; j<SZER; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << "#\n#";
    }
    for(int j = 0; j<SZER+1; j++)
        {
            std::cout << '#';
        }
}

void delete_point(point po)
{
    if(po.y%2)
    {
        board[po.y][po.x] = ' ';
    }
    else
        board[po.y][po.x] = '.';
}

void create_main_ship()
{
    int y = WYS/2;
    steve.x = 3;
    steve.y = y;
    steve.points = {{3, y-1, '>'}, {3, y, '<'}, {4, y, '>'}, {3, y+1, '>'}};
}

void draw_element(std::vector<point> obj)
{
    for(point po : obj)
    {
        board[po.y][po.x] = po.c;
    }
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = false;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'w':
            {
                if(steve.y>1)
                {
                    for(point& po : steve.points)
                    {
                        delete_point(po);
                        po.y--;
                    }
                    steve.y--;
                    dir = 1;
                }
                break;
            }
        case 's':
            {
                if(steve.y<WYS-2)
                {
                    for(point& po : steve.points)
                    {
                        delete_point(po);
                        po.y++;
                    }
                    steve.y++;
                    dir = 2;
                }
                break;
            }
        case 'k':
            {
                create_shot();
                active_shots++;
            }
        }
    }
}

void create_shot()
{
    point temp;
    temp.x = 5;
    temp.y = steve.y;
    temp.c = 'O';
    shots.push_back(temp);
}

void move_shots()
{
    for(auto it = shots.begin(); it!=shots.end(); it++)
    {
        if(it->x<SZER-1)
        {
            delete_point(*it);
            it->x++;
        }
        else
        {
            delete_point(*it);
            it = shots.erase(it);
            active_shots--;
        }
    }
}

void create_enemy()
{
    int y = rand()%(WYS-2)+1;
    point temp;
    temp.c = '<';
    temp.y = y;
    temp.x = SZER-1;
    enemies.push_back(temp);
}

void move_enemies()
{
    for(auto it = enemies.begin(); it != enemies.end(); )
    {
        if(it->x <= 3)
        {
            end_flag = true;
            ++it;
        }
        else
        {
            delete_point(*it);
            it->x--;
            ++it;
        }
    }
}

void hit_check()
{
    for(auto it1 = enemies.begin(); it1 != enemies.end(); )
    {
        bool enemy_erased = false;
        for(auto it2 = shots.begin(); it2 != shots.end(); )
        {
            if(it1->x == it2->x && it1->y == it2->y)
            {
                delete_point(*it1);
                it1 = enemies.erase(it1);
                it2 = shots.erase(it2);
                score++;
                enemy_erased = true;
                break;
            }
            else
            {
                ++it2;
            }
        }
        if(!enemy_erased)
        {
            ++it1;
        }
    }
}
