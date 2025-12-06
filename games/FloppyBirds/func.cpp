#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include "func.h"

char board[WYS][SZER];
std::vector<obsticle> obsticles;
std::vector<point> bird;
bool flag;
int direction;

void create_board()
{
    for(int i = 0; i < WYS; i++)
    {
        for(int j = 0; j < SZER; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void gotoxy(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void show()
{
    gotoxy(0, 0);
    for(int i = 0; i < WYS; i++)
    {
        for(int j = 0; j < SZER; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}

void create_bird()
{

    for(int i = WYS/2; i<WYS/2+2; i++)
    {
        for(int j = 5; j<8; j++)
        {
            point temp;
            temp.x = j;
            temp.y = i;
            temp.c = 'O';
            bird.push_back(temp);
        }
    }
}

void create_obs()
{
    obsticle temp;
    temp.xe = SZER-1;
    temp.xs = SZER - 5;
    temp.ym = rand()%WYS;
    int radius = rand()%3+4;
    temp.yd = temp.ym + radius;
    temp.yu = temp.ym - radius;
    for(int i = 0; i<temp.yu && i < WYS; i++)
    {
        for(int j = temp.xs; j<= temp.xe && j < SZER; j++)
        {
            point temp_p;
            temp_p.x = j;
            temp_p.y = i;
            temp_p.c = '+';
            temp.points_of_obsticles.push_back(temp_p);
        }
    }
    for(int i = temp.yd; i<WYS; i++)
    {
        for(int j = temp.xs; j<=temp.xe; j++)
        {
            point temp_p;
            temp_p.x = j;
            temp_p.y = i;
            temp_p.c = '+';
            temp.points_of_obsticles.push_back(temp_p);
        }
    }
    obsticles.push_back(temp);
}



void draw_obsticles()
{
    for(obsticle obs : obsticles)
    {
        for(point po : obs.points_of_obsticles)
        {
            board[po.y][po.x] = po.c;
        }
    }
}


void move_obsticles()
{
    for(obsticle& obs : obsticles)
    {
        for(point& po : obs.points_of_obsticles)
        {
            delete_point(po);
            po.x--;
        }
        obs.xe--;
        obs.xs--;
    }
}
void hide_cursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}




void delete_point(point po)
{
    board[po.y][po.x] = ' ';
}

void draw_board()
{
    draw_obsticles();
    draw_bird();
    show();
}

void is_end_game()
{
    for(const obsticle& obs : obsticles)
    {
        for(const point& po : obs.points_of_obsticles)
        {
            for(const point& birb : bird)
            {
                if(po.x == birb.x && po.y == birb.y)
                {
                    flag = true;
                    return;
                }
            }
        }
    }
}




void input()
{
    if (_kbhit())
    {
        char ch = _getch();

        switch (ch)
        {
            case 'w':
                {
            direction = 1;
                for (point& po : bird)
                {

                    delete_point(po);
                    if (po.y > 0)
                    {
                        po.y--;
                    }
                }
                break;
                }

            case 's':
                {
                direction = 2;
                for (point& po : bird)
                {
                    delete_point(po);
                    if (po.y < WYS - 1)
                    {
                        po.y++;
                    }
                }
                break;}

        }
    }
}

void draw_bird()
{
    if(board[bird[2].y][bird[2].x]=='+')
    {
        flag = 1;
    }
    for(point po : bird)
    {
        board[po.y][po.x] = 'O';
    }

}


void delete_obstacle()
{

    for(auto it = obsticles.begin(); it != obsticles.end(); )
    {
        if (it->xe <= 0)
        {
            it = obsticles.erase(it);
        }
        else
        {
            ++it;
        }
    }
}


