#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    printf("Valor de CENTES: %i\n", cents);

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int dolar = 0;
    do
    {
        dolar = get_int("Change owed: ");
    }
    while (dolar <= 0);
    return dolar;
}

int calculate_quarters(int cents)
{
    int countQuarters = 0;
    for (int i = cents; i >= 25; i -= 25)
    {
        if (cents >= 25)
        {
            countQuarters += 1;
        }
    }
    return countQuarters;
}

int calculate_dimes(int cents)
{
    int countDimes = 0;
    for (int i = cents; i >= 10; i -= 10)
    {
        if (cents >= 10)
        {
            countDimes += 1;
        }
    }
    return countDimes;
}

int calculate_nickels(int cents)
{
    int countNickels = 0;
    for (int i = cents; i >= 5; i -= 5)
    {
        if (cents >= 5)
        {
            countNickels += 1;
        }
    }
    return countNickels;
}

int calculate_pennies(int cents)
{
    int countPennies = 0;
    for (int i = cents; i >= 1; i -= 1)
    {
        if (cents >= 1)
        {
            countPennies += 1;
        }
    }
    return countPennies;
}
