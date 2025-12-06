#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "func.h"

using namespace std;

int main()
{
    hideCursor();
    create_board();
    create_dino();
    draw(dino.points);
    show();
    int clock = 0;
    int obs_clock = 0;
    int dino_move_clock = 0;

    while(!collision())
    {
        gotoxy(0, 0);
        if(obs_clock == 0)
        {
            create_obs(rand()%3);
            obs_clock = rand()%30+20;
        }
        if(dir==none)
        {
            Input();
        }
        if(dino_move_clock = 2)
        {
            if(dir == up)
            jump_check();
            else if(dir == down)
            {
           if(clock==0)
           {
               crawl();
           }
           clock++;
           if(clock == 10)
           {
               delete_point(dino.points[0]);
               create_dino();
               draw(dino.points);
               clock = 0;
               dir = none;
           }
        }
        dino_move_clock = 0;
        }

       move_obs();
        draw_obs();
        Sleep(100-(total_obs/10));
        show();
        obs_clock--;
        dino_move_clock++;

    }
    return 0;
}
