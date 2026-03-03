#include <iostream>
#include <vector>
#include <windows.h>
#include "game_lib.h"
#define WYS 14
#define SZER 48

using namespace std;

int main()
{
    hideCursor();
    char** board = create_board(WYS, SZER);
    char** tempb = create_board(WYS, SZER);

    FILE* plik;
    if((plik = fopen("games/MazeSolver/lab.txt", "r"))==NULL)
    {
        if((plik = fopen("lab.txt", "r"))==NULL)
        {
            std::cout << "file not found";
            exit(1);
        }
    }

    char temp;
    int j = 0;
    while((temp=fgetc(plik))!=EOF)
    {
        if(temp!='\n')
        {
            board[0][j] = temp;
            tempb[0][j] = temp;
            j++;
        }
    }
    point solver = {4, 0, 'o'};
    draw(solver, board);
    show(board, WYS, SZER);
    point last_solver = solver;
    direction dire = down;


    while(!(solver.x == SZER-1 || solver.y == WYS-1))
    {
        Sleep(1);
        if(is_branch(solver, last_solver, board, WYS, SZER)==0 && is_stuck(solver, dire, board, WYS, SZER))
        {
            dire = change_dire(dire);
            dire = change_dire(dire);
        }

        if(is_branch(solver, last_solver, board, WYS, SZER)>1 && is_right_free(solver, dire, board, WYS, SZER))
        {
            dire = change_dire(dire);
        }
        if(is_branch(solver, last_solver, board, WYS, SZER)==1 && !is_right_free(solver, dire, board, WYS, SZER) && is_stuck(solver, dire, board, WYS, SZER))
        {
            dire = change_dire(dire);
            dire = change_dire(dire);
            dire = change_dire(dire);
        }
        if(is_branch(solver, last_solver, board, WYS, SZER)==1 && is_right_free(solver, dire, board, WYS, SZER) && is_stuck(solver, dire, board, WYS, SZER))
        {
            dire = change_dire(dire);
        }
        if(!is_stuck(solver, dire, board, WYS, SZER))
        {
            last_solver = solver;
            move_point(&solver, dire, board, tempb, WYS, SZER);
        }
        show(board, WYS, SZER);
        if(solver.y == 0)
        {
            std::cout << "\nPATH NOT FOUND";
            break;
        }
    }
    std::cout << "\nDONE";
}
