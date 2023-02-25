#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[6] = {2, 4, 6, 8, 10, 50};

    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == 50)
        {
            printf("Yes, here is 50\n");
        }
    }

    printf("Not Foud\n");
}