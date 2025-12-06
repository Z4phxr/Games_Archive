#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <ctime>
#include "func.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));
    create_board();
    create_obs();
    create_bird();
    flag = false;
    int score = 0;
    hide_cursor();

    while (!flag) {
        input();
        move_obsticles();
        draw_board();
        is_end_game();
        Sleep(50);
        score++;
    }
    std::cout << "\nGame Over! Your score: " << score << std::endl;
    return 0;
}
