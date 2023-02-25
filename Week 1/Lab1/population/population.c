#include <cs50.h>
#include <stdio.h>

int getPopulationStart();
int getPopulationEnd(int populationStart);
int calculateYears(int populationStart, int populationEnd);

int main(void)
{
    // TODO: Prompt for start size
    int populationStart = getPopulationStart();
    int populationEnd = getPopulationEnd(populationStart);
    int years = calculateYears(populationStart, populationEnd);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

// TODO: Prompt for start size
int getPopulationStart()
{
    int populationStart;
    do
    {
        populationStart = get_int("Whats nunber population initial: ");

        if (populationStart < 9)
        {
            printf("The initial population cannot be less than 9. \n");
        }
    }
    while (populationStart < 9);
    return populationStart;
}

// TODO: Prompt for end size
int getPopulationEnd(int populationStart)
{
    int populationEnd;
    do
    {
        populationEnd = get_int("Whats nunber population final: ");

        if (populationEnd < populationStart)
        {
            printf("The final population cannot be less than initial population. \n");
        }
    }
    while (populationEnd < populationStart);
    return populationEnd;
}

// TODO: Calculate number of years until we reach threshold
int calculateYears(int populationStart, int populationEnd)
{
    int years = 0;
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
    return years;
}
