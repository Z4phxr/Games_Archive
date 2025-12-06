#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "func.h"
#include <vector>

int main();

int main()
{
    end_flag = 0;
    score = 0;
    srand(time(NULL));
    hideCursor();
    create_board();
    create_main_ship();
    int i = 0;
    int m = 0;

        show();
        gotoxy(37, 10);
        std::cout << "PRESS P TO PLAY!";
        gotoxy(30, 11);
        std::cout << "'w' - up 's' - down 'k' - shot";
        bool gamestart = false;
        while(!gamestart)
        {
            if(_kbhit)
            {
                if(_getch()=='p')
                {
                    gamestart = true;
                }
            }
        }

    while(!end_flag)
    {
        move_shots();
        gotoxy(0,0);
        Input();
        hit_check();
        draw_element(steve.points);
        draw_element(shots);
        if(m==20)
        {
            if(enemies.size()<5)
            {
                create_enemy();
            }
            m = 0;
        }

        if(i==2)
        {
            move_enemies();
            i=0;
        }

        draw_element(enemies);
        hit_check();
        show();
        Sleep(50);
        std::cout << "\nPOINTS: " << score;
        i++;
        m++;
    }


    return 0;
}
