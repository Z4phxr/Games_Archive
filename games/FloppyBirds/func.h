#include <vector>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define SZER 80
#define WYS 35

class point
{
public:
    int x, y;
    char c;

};

class obsticle
{
public:
    int xs, xe, yu, yd, ym;
    std::vector<point> points_of_obsticles;
};

extern std::vector<point> bird;
extern std::vector<obsticle> obsticles;


extern char board[WYS][SZER];
extern bool flag;
extern int direction;


void create_board();
void show();
void gotoxy(int x, int y);
void create_bird();
void create_obs();
void draw_obsticles();
void move_obsticles();
void check();
void draw_board();
void hide_cursor();
void is_end_game();
void delete_point(point);
void move_bird(int);
void input();
void draw_bird();
void delete_obstacle();

#endif

