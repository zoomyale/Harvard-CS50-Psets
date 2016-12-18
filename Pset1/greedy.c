#include <stdio.h>
#include <cs50.h>
#include <math.h>

int coin(int coins, int cents);

int main(void)
{
    float change;
    do
    {
        printf("O hai! How much change is owed?\n");
        change = get_float();
    } while (change < 0);
    
    int cents = (int)roundf(change * 100);
    
    int quaters= coin(25,cents);
    cents -= quaters * 25;
    int dimes = coin(10,cents);
    cents -= dimes * 10;
    int nickels = coin(5,cents);
    cents -= nickels * 5;
    int pennies = coin(1,cents);
    
    printf("%i\n", quaters + dimes + nickels + pennies);
}

int coin(int coins, int cents)
{
    int rel = 0;
    for (int i = 1; coins * i <= cents; i ++)
    {
        rel += 1;
    }
    return rel;
}