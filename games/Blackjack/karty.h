typedef enum {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king} FIGURY;
typedef enum {czarny = 0, czerwony} KOLOR;
typedef enum {kier, karo, trefl, pik} KSZTALT;

typedef struct
{
    int id;
    int exist;
    KOLOR kolor;
    KSZTALT kszt;
    union
    {
        int figura_one;
        char figura_two;
    };
    int wartosc;
}KARTA;

typedef struct
{
    KARTA talia[52];
    int size_of_deck;
} DECK;

extern DECK main_deck;
extern DECK player;
extern DECK computer;
void inicjalizacja();
void show_deck(DECK tal);
void shuffle(KARTA deck[], int);
void swap_cards(KARTA one, KARTA two);
int in_use(int id, KARTA talia[], int);
DECK give(int n, DECK main, DECK new_talia);
DECK delete_from_deck(DECK, int n);
int blackjack();
void show_cards(DECK, int);


