#ifndef FUNC_H
#define FUNC_H
#include <vector>
#define SZER 90
#define WYS 10
#define LINIA WYS-2

class point
{
public:
    int x, y;
    char c;
};

class obstacle
{
public:
    int type;
    int x, y;
    std::vector<point> points;
};

class din
{
public:
    int x, y;
    std::vector<point> points;
};

extern din dino;
extern std::vector<obstacle> obstacles;
extern char board[WYS][SZER];
extern bool in_hit;
enum direc {none, up, down};
extern direc dir;
extern bool touchup;
extern int total_obs;




void show();
void create_board();
void delete_point(point);
void create_dino();
void draw(std::vector<point> points);
void Input();
void jump_check();
void gotoxy(int x, int y);
void hideCursor();
void crawl();
void create_obs(int type);
void draw_obs();
void move_obs();
bool collision();

#endif
