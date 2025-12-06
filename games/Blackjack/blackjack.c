#include "karty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bar(DECK player);
void ramka(char *tekst);
int suma(DECK player);

DECK main_deck;
DECK player;
DECK computer;

int blackjack()
 {
    inicjalizacja();
    shuffle(main_deck.talia, 52);
    player.size_of_deck = 0;
    computer.size_of_deck = 0;

    player = give(2, main_deck, player);
    computer = give(2, main_deck, computer);

    ramka((char*)"Dealer's cards");
    show_cards(computer, 1);

    ramka((char*)"Your cards:");
    show_cards(player, 0);
    bar(player);

    char answer[6];
    while(1)
    {
        printf("Type 'hit' or 'stand': ");
        scanf("%s", answer);
        
        if(!strcmp(answer, "hit"))
        {
            player = give(1, main_deck, player);
            show_cards(player, 0);
            bar(player);
            
            if(suma(player) > 21)
            {
                printf("\nYou lost! You went over 21.\n");
                return 0;
            }
        }
        else if(!strcmp(answer, "stand"))
        {
            ramka((char*)"Dealer's cards:");
            while(suma(computer) < 17)
            {
                computer = give(1, main_deck, computer);
            }
            show_cards(computer, 0);
            bar(computer);
            
            int player_sum = suma(player);
            int computer_sum = suma(computer);
            
            printf("\nYour sum: %d\n", player_sum);
            printf("Dealer's sum: %d\n", computer_sum);
            
            if(computer_sum > 21)
            {
                printf("You won! Dealer went over 21.\n");
                return 1;
            }
            else if(player_sum > computer_sum)
            {
                printf("You won!\n");
                return 1;
            }
            else if(player_sum < computer_sum)
            {
                printf("You lost!\n");
                return 0;
            }
            else
            {
                printf("It's a tie!\n");
                return 2;
            }
        }
    }
 }

 void show_cards(DECK tal, int x)
 {
     int n;
     if(x)
     {
         n = 1;
     }
     else
     {
         n = tal.size_of_deck;
     }


     for(int i = 0; i<n; i++)
     {
         printf(" _______  ");
     }
     printf("\n");
     for(int i = 0; i<n; i++)
     {
         printf("|       | ");
     }
     printf("\n");
     for(int i = 0; i<n; i++)
     {
         printf("|       | ");
     }
     printf("\n");
     for(int i = 0; i<n; i++)
     {
         if(tal.talia[i].id%13<11 && tal.talia[i].id%13>1)
         {
             printf("|  %2d   | ", tal.talia[i].figura_one);
         }
         else
            printf("|   %c   | ", tal.talia[i].figura_two);

     }
     printf("\n");
     for(int i = 0; i<n; i++)
     {
         printf("|       | ");
     }
     printf("\n");
     for(int i = 0; i<n; i++)
     {
         printf("|       | ");
     }
     printf("\n");
     for(int i = 0; i<n; i++)
     {
         printf(" _______  ");
     }
    printf("\n\n");

 }

 int suma(DECK tal)
 {
     int sum = 0;
     for(int i = 0 ; i<tal.size_of_deck; i++)
     {
         if(tal.talia[i].wartosc>1)
         {
             sum += tal.talia[i].wartosc;
         }
     }
     for(int i = 0; i<tal.size_of_deck; i++)
     {
         if(tal.talia[i].wartosc<2)
         {
             if(sum+10<22)
             {
                 sum +=11;
             }
             else
             {
                 sum+= 1;
             }

         }
     }
     return sum;
 }

void bar(DECK player)
 {
    printf("\n-----------------------------------------\n");
    printf("|\tcurrent sum of cards: %2d\t|", suma(player));
    printf("\n-----------------------------------------\n");
 }

 void ramka(char *tekst)
 {
    printf("\n");
    for(int i = 0; i<16+strlen(tekst); i++)
    {
        printf("-");
    }
    printf("\n|");
    for(int i = 0; i<7; i++)
    {
        printf(" ");
    }
    printf("%s", tekst);
    for(int i = 0; i<7; i++)
    {
        printf(" ");
    }
    printf("|\n");
    for(int i = 0; i<16+strlen(tekst); i++)
    {
        printf("-");
    }
    printf("\n");

 }



