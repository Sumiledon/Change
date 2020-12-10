#include <stdio.h>
#include <math.h>
#include <string.h>

int quarters = 0;
int dimes = 0;
int nickels = 0;
int pennies = 0;

char quarter[9] = "quarters";
char dime[6] = "dimes";
char nickel[8] = "nickels";
char penny[8] = "pennies";

void coin_count(int cents);
void plural_check(void);

int main(void)
{
    float change;

    printf("Please input your change in decimal form, without dollar sign: ");
    scanf("%f", &change);

    int cents = round(change * 100);

    coin_count(cents);
    plural_check();

    int coins = (quarters + dimes + nickels + pennies);

    printf("You will recieve a total of %i coins.\n", coins);
    printf("%i %s, %i %s, %i %s, and %i %s\n", quarters, quarter, dimes, dime, nickels, nickel, pennies, penny);
}



// Tabulates most efficient coin count from the total dollar amount provided.

void coin_count(int cents)
{
    if (cents / 25 >= 1)
    {
        quarters = (cents / 25);

    }

    cents = (cents % 25);

    if (cents / 10 >= 1)
    {
        dimes = (cents / 10);
    }

    cents = (cents % 10);

    if (cents / 5 >= 1)
    {
        nickels = (cents / 5);
    }

    cents = (cents % 5);

    if (cents / 1 >= 1)
    {
        pennies = (cents / 1);
    }

    cents = (cents % 1);
}



// Checks whether or not the amount of each coin requires singular or plural verbage.

void plural_check(void)
{
    if (quarters == 1)
    {
        strncpy(quarter, "quarter", 8);
    }

    if (nickels == 1)
    {
        strncpy(nickel, "nickel", 7);
    }

    if (dimes == 1)
    {
        strncpy(dime, "dime", 5);
    }

    if (pennies == 1)
    {
        strncpy(penny, "penny", 6);
    }

}