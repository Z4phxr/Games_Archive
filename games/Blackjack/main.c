#include <stdio.h>
#include <stdlib.h>
#include "karty.h"
#include <time.h>

int main()
{
    int money = 100;
    srand(time(NULL));
    int ans = 0;
    while(ans!=5)
    {
            printf("\t\t\t\t\t\tAccount balance: %d\n", money);
            printf("\t1 - blackjack\n\t5 - exit\n");
        scanf("%d", &ans);
        if(ans==1)
        {
            int stawka = 0;
            printf("How much money: ");
            scanf("%d", &stawka);
            
            if(stawka > money)
            {
                printf("You don't have enough money!\n");
                continue;
            }
            
            money -= stawka;
            int wynik = blackjack();
            
            if(wynik == 1)
            {
                money += stawka * 2;
            }
            else if(wynik == 2)
            {
                money += stawka;
            }
        }


    }

}
