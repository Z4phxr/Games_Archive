#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include<time.h>
#define N 15
#define M 15


enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
int menu_toggle = 0;


class position
{
    public:
    int x;
    int y;
    char c;
};
class position head;
class position fruit;

using namespace std;

char table[N][M];
bool flag_end = false;
int points;

std::vector<position> tail;

bool zderzenie()
{
    if(head.x<0 || head.x >=N || head.y <0 || head.y >= N)
    {
        return true;
    }
    else if(table[head.x][head.y] == 'o')
    {
        return true;
    }

    return false;
}

void show_table()
{
    std::cout << endl;
    for(int i = 0; i<N+2; i++)
        {
            std::cout << '#';
        }
    std::cout << endl;
        for(int i = 0; i<N; i++)
        {
            std::cout << '#';
            for(char space : table[i])
            {
                std::cout << space;
            }

            std::cout << '#' <<endl;
        }
        for(int i = 0; i<N+2; i++)
        {
            std::cout << '#';
        }
}

void delete_from(class position pos)
{
    table[pos.x][pos.y] = ' ';
}

void put(class position pos)
{
    table[pos.x][pos.y] = pos.c;
}

void gotoxy(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            exit(0);
        }
    }
}


bool is_in(class position pos)
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(table[i][j]==pos.c)
            {
                return true;
            }
        }
    }
    return false;
}

void fruit_put()
{
    if(!is_in(fruit))
    {
    do
    {
        fruit.x = rand()%15;
        fruit.y = rand()%15;
    }
    while(table[fruit.x][fruit.y]!=' ');
    put(fruit);
    }


}

void tail_update()
{

    tail.insert(tail.begin(), head);
    position temp = tail[tail.size()-1];
    delete_from(temp);
    tail.pop_back();
    for(position pos : tail)
    {
        table[pos.x][pos.y] = 'o';
    }

}

void move_head()
{
    class position prev = head;
    prev.c = 'o';
    delete_from(head);
    tail_update();
    switch(dir)
    {
        case LEFT:
            head.y = head.y - 1;
            break;
        case RIGHT:
            head.y = head.y + 1;
            break;
        case UP:
            head.x--;
            break;
        case DOWN:
            head.x++;
            break;
        default:
            break;
    }
    if(zderzenie())
    {
        flag_end = true;
    }
    else
    if(table[head.x][head.y]=='F')
    {
        points++;
        position temp;
        temp = prev;
        tail.push_back(temp);


    }
    put(head);


}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = false;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


void menu()
{
    gotoxy(0, 1);
    switch(menu_toggle)
    {
    case 0:
        {
            std::cout << "> Easy        (w/s to select, x to confirm)\n";
            std::cout << "Medium     \n";
            std::cout << "Hard     \n";
            break;
        }
    case 1:
        {
            std::cout << "Easy        \n";
            std::cout << "> Medium     (w/s to select, x to confirm)\n";
            std::cout << "Hard     \n";
            break;
        }
    case 2:
        {
            std::cout << "Easy        \n";
            std::cout << "Medium     \n";
            std::cout << "> Hard       (w/s to select, x to confirm)\n";
            break;
        }
    }

}

int main()
{
    hideCursor();
    srand(time(NULL));
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            table[i][j] = ' ';
        }
    }

    head.x = 0;
    head.y = 0;
    head.c = 'O';
    fruit.c = 'F';
    points = 0;
    put(head);
    char tryb;
    system("cls");
    std::cout << "SELECT GAME MODE\n";
    while(tryb!= 'x')
    {
        menu();
        if (_kbhit())
        {

            char c = _getch();
            if(c=='w' && menu_toggle>0)
                menu_toggle--;
            else if(c=='s' && menu_toggle < 2)
                menu_toggle++;
            else if(c=='x')
                tryb = 'x';
        }
    }

    while(!flag_end)
    {
        gotoxy(0, 4);
        fruit_put();
        show_table();
        input();
        move_head();
        switch(menu_toggle)
        {
        case 0:
            {
                Sleep(200);
                break;
            }
        case 1:
            {
                Sleep(150);
                break;
            }
        case 2:
            {
                Sleep(100);
                break;
            }
        }
        std::cout << endl << endl <<"------------------";
        std::cout << endl << "| YOUR POINTS: " << points << " |";
        std::cout << endl <<"------------------";
    }
    std::cout << endl << "YOU LOST!" << endl;
    while(1)
    {
        char x;
        std::cin >> x;
    }
    return 0;
}

