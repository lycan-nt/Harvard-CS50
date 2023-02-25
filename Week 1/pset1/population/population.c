#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int populationStart;
    int populationEnd;
    int years = 0;
    do
    {
        populationStart = get_int("Whats nunber population initial: ");

        if (populationStart < 9)
        {
            printf("The initial population cannot be less than 9. \n");
        }
    }
    while (populationStart < 9);

    // TODO: Prompt for end size
    do
    {
        populationEnd = get_int("Whats nunber population final: ");

        if (populationEnd < populationStart)
        {
            printf("The final population cannot be less than initial population. \n");
        }
    }
    while (populationEnd < populationStart);

    // TODO: Calculate number of years until we reach threshold
    do
    {
        if (populationStart == populationEnd)
        {
            break;
        }

        populationStart += (populationStart / 3) - (populationStart / 4);
        years++;

    }
    while (populationStart < populationEnd);


    // TODO: Print number of years
    printf("Years: %i\n", years);
}
