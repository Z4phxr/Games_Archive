#ifndef GAME_LIB_H
#define GAME_LIB_H

#include <vector>

enum direction {down = 1, leftt, up, rightt};


class point
{
public:
    int x, y;
    char c;
};

char** create_board(int wys, int szer);
void hideCursor();
void gotoxy(int x, int y);
void show(char** board, int wys, int szer);
void draw(std::vector<point>, char** board);
void draw(point po, char** board);
void delete_point(point po, char** board, char** board_template);
void move_point(point* po, int dir, char **board, char** board_template, int wys, int szer);
int is_branch(point Aya, point last, char** board, int wys, int szer);
bool is_right_free(point Aya, direction dir, char** board, int wys, int szer);
direction change_dire(direction dire);
bool is_stuck(point Aya, direction dire, char** board, int wys, int szer);

#endif
