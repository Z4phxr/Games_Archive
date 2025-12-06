#ifndef GAME_LIB_H
#define GAME_LIB_H

#include <vector>

enum direction {
    none  = 0,
    up    = 1 << 0,
    down  = 1 << 1,
    left  = 1 << 2,
    right = 1 << 3
};


class point
{
public:
    int x, y;
    char c;
};

class obstacle
{
public:

    int x, y;
    char c;
    std::vector<point> points;
    int type;
};


char** create_board(int, int);
void hideCursor();
void gotoxy(int x, int y);
void show(char** board, int wys, int szer);
void draw(std::vector<point>, char** board);
void draw(point po, char** board);
bool collision_point(point po1, point po2);
bool collision_obj(std::vector<point> points1, std::vector<point> points2);
void delete_point(point po, char** board, char** board_template);
void move_point(point* po, int dir, char **board, char** board_template, int wys, int szer);
void move_obj(obstacle* ob, int dir, char **board, char** board_template, int wys, int szer);
int Input();
void follow(point* po, point goal, char **board, char** board_temp, int wys, int szer);




#endif
