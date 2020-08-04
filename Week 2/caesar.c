#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

//Atualmente tentando resolver o erro que da ao checar

int main(int key, string argv[])
{
    if (key != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {

        int valNumber = atoi(argv[1]);

        if (valNumber <= 0)
        {
            printf("Please Use: ./caesar key where you enter a number > 0 \n");
        }
        else
        {
            printf("This one is the number in int: %i\n", valNumber);



            string text;

            do
            {
                text = get_string("Please enter the text to be encrypted: ");
            }
            while (text == NULL);


            for (int i = 0; text[i] != '\0'; i++)
            {
                if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
                {
                    do
                    {

                        if (valNumber > 26)
                        {
                            valNumber = valNumber - 26;
                        }


                    }
                    while (valNumber > 26);

                    for (int n = 1; n <= valNumber; n++)
                    {
                        if (text[i] < 'z')
                        {
                            text[i] = text[i] + 1;
                        }

                        if (text[i] == 'z')
                        {
                            text[i] = 'a';
                            n += 1;
                        }
                        if ((text[i] == 'Z')  || (text[i] == '['))
                        {

                            text[i] = 'A';
                            n += 1;
                        }

                    }

                }


            }

            printf("ciphertext: %s\n", text);
        }

    }

}
