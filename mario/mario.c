#include <cs50.h>
#include <stdio.h>

//ATUALMENTE TENTANDO ALTERAR A LOGICA DE ESPACOS


int main(void)
{
    int height = 0;

    do
    {
        height = get_int("Please enter the height between 1 and 8: ");
        if ((height < 1) || (height > 8))
        {
            printf("The entered and invalid value \n");

        }

    }
    while ((height < 1) || (height > 8));

    int loop = height;

    for (int i = 1; i <= loop; i++)
    {
        int space = 8 - i;
        height = height - 1;

        for (int j = 0; j < height; j++)
        {
            printf(" ");
        }
        int hash = 8 - space;
        for (int h = 0; h < hash; h++)
        {
            printf("#");

        }
        printf("  ");
        for (int h2 = 0; h2 < hash; h2++)
        {

            printf("#");
        }
        printf("\n");
    }

}