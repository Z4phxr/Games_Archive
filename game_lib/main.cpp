#include <iostream>
#include "game_lib.h"
#include <windows.h>
#define WYS 20
#define SZER 50
#define SPEED 5

using namespace std;

int main()
{
    char **board = create_board(WYS, SZER);
    char **board_temp = create_board(WYS, SZER);



    point enemy = {0, 0, 'X'};
    point Stefanie;
    Stefanie.x = 10;
    Stefanie.y = 10;
    Stefanie.c = 'S';
    hideCursor();
    int follow_speed = SPEED;

    while(1)
    {
        gotoxy(0, 0);
        move_point(&Stefanie, Input(), board, board_temp, WYS, SZER);
        if(!follow_speed)
        {
            follow(&enemy, Stefanie, board, board_temp, WYS, SZER);
            follow_speed = SPEED;
        }

        draw(enemy, board);
        draw(Stefanie, board);
        show(board, WYS, SZER);
        Sleep(50);
        follow_speed--;
        std::cout << "\nSTEFANIE: " << Stefanie.x << " " << Stefanie.y << "\nenemy: " << enemy.x << " " << enemy.y;
    }




    show(board, WYS, SZER);
}
