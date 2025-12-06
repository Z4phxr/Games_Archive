#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#define WYS 35
#define SZER 90

class point
{
public:
    int x, y;
    char c;
};

class ship
{
public:
    int x, y;
    std::vector<point> points;
};

class enemy
{
public:
    int x, y, hp, speed;
    std::vector<point> points;
};

extern char board[WYS][SZER];
extern class ship steve;
extern std::vector<point> enemies;
extern std::vector<point> shots;
extern int dir;
extern int active_shots;
extern bool end_flag;
extern int score;

void create_board();
void show();
void create_main_ship();
void draw_element(std::vector<point>);
void gotoxy(int x, int y);
void hideCursor();
void Input();
void delete_point(point po);
void create_shot();
void move_shots();
void move_enemies();
void create_enemy();
void hit_check();

#endif
