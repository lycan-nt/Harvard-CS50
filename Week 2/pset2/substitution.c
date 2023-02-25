#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(int key, string argv[])
{

    if (key != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {


        string charKey = argv[1];
        int validator;

           for (validator = 0; charKey[validator] != '\0'; validator++)
           {

               if ( ( (charKey[validator]  >= 'a') && (charKey[validator]  <= 'z') ) || ( (charKey[validator] >= 'A') && (charKey[validator] <= 'Z') ) )
               {

                   if ( validator >= 26 )
                   {
                        printf("Please enter only 26 characters \n");

                   }

               }
               else
               {
                   printf("Please enter only letters: \n");

               }

           }

        if (validator == 26)
        {

        bool valid = false;
        string validInternal;

        for ( int v = 0; charKey[v] != '\0'; v++)
        {
         if ( ( (charKey[v]  >= 'a') && (charKey[v]  <= 'z') ) || ( (charKey[v] >= 'A') && (charKey[v] <= 'Z') ) )
        {

        }
        else
        {
            validInternal = "Error";
        }
        }

        if (validInternal == NULL)
        {
            do
            {

                for(int i = 0;  charKey[i] != '\0'; i++)
                {
                    char stringKey = charKey[i];

                    int valueValidator = 0;

                    for(int j = 0; charKey[j] != '\0'; j++)
                    {

                        if (charKey[j] == stringKey)
                        {
                            valueValidator++;

                            if (valueValidator > 1)
                            {
                                validInternal = "Error!";
                            }

                        }
                    }

                }

                if (validInternal == NULL)
                {
                    validInternal = "Comcluded!";
                    valid = true;
                }

            }while(validInternal == NULL);

        if (valid == true)
        {
            //Alfabeto: ABCDEFGHIJKLMNOPQRSTUVWXYZ
            string text = get_string("plaintext: ");

            for (int ck = 0; text[ck] != '\0'; ck++)
            {
                //Verificar se os index são iguais
                if (text[ck] == charKey[ck])
                {

                }
                else
                {

                    int counter;
                    char initialLetter;

                    if ( (charKey[ck]  >= 'a') && (charKey[ck]  <= 'z') )
                    {
                         initialLetter = 'a';

                        for (counter = 0; initialLetter != charKey[ck]; counter++)
                        {
                            initialLetter++;
                        }

                        if ( (text[ck]  >= 'a') && (text[ck]  <= 'z') )
                        {
                            text[ck] = 'a';
                            text[ck] = text[ck] + counter;
                        }
                        else if( (text[ck]  >= 'A') && (text[ck]  <= 'Z') )
                        {
                            text[ck] = 'A';
                            text[ck] = text[ck] + counter;
                        }

                    }
                    else if ( (charKey[ck]  >= 'A') && (charKey[ck]  <= 'Z') )
                    {

                       initialLetter = 'A';

                       for (counter = 0; initialLetter != charKey[ck]; counter++)
                        {
                            initialLetter++;
                        }

                        if ( (text[ck]  >= 'a') && (text[ck]  <= 'z') )
                        {
                            text[ck] = 'a';
                            text[ck] = text[ck] + counter;
                        }
                        else if( (text[ck]  >= 'A') && (text[ck]  <= 'Z') )
                        {
                            text[ck] = 'A';
                            text[ck] = text[ck] + counter;
                        }

                    }
                }
            }

            printf("ciphertext: %s\n", text);
        }
        else
        {
            printf("Each letter can only be entered once \n");
        }

    }
    }
    else if(validator < 26)
    {
            printf("Please enter 26 characters!\n");
    }

    }

}



