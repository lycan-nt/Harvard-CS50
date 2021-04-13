#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

//Here l e = a letters o w = words and s = a sentences where the n after each e = a numbers
int ln = 0;
int wn = 1;
int sn = 0;
float Grade = 0;

int main(void)
{

    string text = get_string("Please enter the text: ");

    for (int i = 0; text[i] != '\0'; i++)
    {

        //Counting letters
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            ln += 1;
        }

        //Counting words
        if (ln > 0 && text[i] == ' ')
        {
            wn += 1;
        }

        //Counting phrases
        if (wn > 0 && (text[i] == '!'  ||  text[i] == '?'  ||  text[i] == '.'))
        {
            sn += 1;
        }

    }

    if (ln <= 0)
    {
        wn = 0;
    }

    //Calc Media
    float L = ((float)ln / (float) wn) * 100;

    float S = ((float) sn / (float) wn) * 100;


    Grade = 0.0588 * L - 0.296 * S - 15.8;

    if (Grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (Grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", Grade);
    }

}