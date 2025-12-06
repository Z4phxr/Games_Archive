#include "karty.h"
#include <stdio.h>
#include <stdlib.h>
extern DECK main_deck;
extern DECK player;
extern DECK computer;


void inicjalizacja()
{
    int fig[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    for(int i = 0; i<52; i++)
    {
        main_deck.talia[i].id = i+1;
        if(i<26)
        {
            main_deck.talia[i].kolor = czarny;
            if(i<13)
            {
                main_deck.talia[i].kszt = trefl;
            }
            else
            {
                main_deck.talia[i].kszt = pik;
            }
        }
        else
        {
            main_deck.talia[i].kolor = czerwony;
            if(i<39)
            {
                main_deck.talia[i].kszt = karo;
            }
            else
            {
                main_deck.talia[i].kszt = kier;
            }
        }
        if(i%13<10 && i%13!=0)
        {
            main_deck.talia[i].figura_one = (i%13)+1;
        }
        else if(i%13==10)
        {
            main_deck.talia[i].figura_two = 'J';
        }
        else if(i%13==11)
        {
            main_deck.talia[i].figura_two = 'Q';
        }
        else if(i%13==12)
        {
            main_deck.talia[i].figura_two = 'K';
        }
        else if(i%13==0)
        {
            main_deck.talia[i].figura_two = 'A';
        }

        main_deck.talia[i].exist = 1;
        if(main_deck.talia[i].id%13<11 && main_deck.talia[i].id%13>0)
        {
            main_deck.talia[i].wartosc = i%13+1;
        }
        else
        {
            main_deck.talia[i].wartosc = 10;
        }
    }
    main_deck.size_of_deck = 52;
}

void show_deck(DECK tal)
{
    for(int i = 0; i<tal.size_of_deck; i++)
    {
        if(tal.talia[i].exist!=0)
        {
            printf("id: %2d ", tal.talia[i].id);
            if(i%13<10 && i%13!=0)
            {
                printf("figura: %2d ", tal.talia[i].figura_one);
            }
            else
            {
                printf("figura:  %c ", tal.talia[i].figura_two);
            }
            printf("wartosc: %2d ", tal.talia[i].wartosc);
            printf("exist: %d\n", tal.talia[i].exist);
        }
    }
}

void shuffle(KARTA talia[], int size)
{
    for(int i = size-1; i>0; i--)
    {
        int random_index = rand()%(i+1);
        KARTA temp = talia[i];
        talia[i] = talia[random_index];
        talia[random_index] = temp;
    }

}

int in_use(int id, KARTA talia[], int size)
{
    for(int i = 0; i<size; i++)
    {
        if(talia[i].id==id)
        {
            return 1;
        }
    }
    return 0;
}


DECK delete_from_deck(DECK deckk, int n)
{
    KARTA* temp = &deckk.talia[0];
    while(temp->exist==0)
    {
        temp++;
    }
    for(int i = 0; i<n;i++)
    {
        temp[i].exist = 0;
    }
    return deckk;
}


DECK give(int n, DECK main, DECK new_talia)
{
    int c = new_talia.size_of_deck;
    int i = 0;
    int x = n +c;
    while (c < x && i<52)
    {
        if (main.talia[i].exist)
        {
            new_talia.talia[c] = main.talia[i];
            new_talia.size_of_deck++;
            c++;
        }
        i++;
    }
    main_deck = delete_from_deck(main_deck, n);
    return new_talia;
}



