#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[4] = { "Felipe", "Marcella", "Yuno", "Floop" };

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "Marcella") == 0)
        {
            printf("Foud\n");
            return 0;
        }
    }

    printf("Not foud\n");
    return 1;
}