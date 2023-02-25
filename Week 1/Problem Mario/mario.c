#include <cs50.h>
#include <stdio.h>

int getSizePyramids();
void mountPyramids(int sizePyramids);

int main(void)
{
    int sizePyramids = getSizePyramids();
    mountPyramids(sizePyramids);
}

int getSizePyramids()
{
    int sizePyramids = 0;
    do
    {
        sizePyramids = get_int("Please enter the height between 1 and 8: ");
        if ((sizePyramids < 1) || (sizePyramids > 8))
        {
            printf("The entered and invalid value \n");
        }
    }
    while ((sizePyramids < 1) || (sizePyramids > 8));
    return sizePyramids;
}

void mountLeftPyramids(int i, int sizePyramids, int space);
void mountRightPyramids(int i, int space);

void mountPyramids(int sizePyramids)
{
    int loop = sizePyramids;
    for (int i = 1; i <= loop; i++)
    {
        int space = 8 - i;
        sizePyramids = sizePyramids - 1;
        mountLeftPyramids(i, sizePyramids, space);
        printf("  ");
        mountRightPyramids(i, space);
    }
}

void mountLeftPyramids(int i, int sizePyramids, int space)
{
    for (int j = 0; j < sizePyramids; j++)
    {
        printf(" ");
    }
    int hash = 8 - space;
    for (int h = 0; h < hash; h++)
    {
        printf("#");
    }
}

void mountRightPyramids(int i, int space)
{
    int hash = 8 - space;
    for (int h2 = 0; h2 < hash; h2++)
    {
        printf("#");
    }
    printf("\n");
}