#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int checkEntry(int key, string argv[]);
string getTextEncrypted();
void textEncrypted(string text, int valNumber);

int main(int key, string argv[])
{
    if (checkEntry(key, argv) > 0)
    {
        return 1;
    }
    int valNumber = atoi(argv[1]);
    printf("This one is the number in int: %i\n", valNumber);
    string text = getTextEncrypted();
    textEncrypted(text, valNumber);
    printf("ciphertext: %s\n", text);
    return 0;
}

int checkEntry(int key, string argv[])
{
    if (key != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int valNumber = atoi(argv[1]);
    if (valNumber <= 0)
    {
        printf("Please Use: ./caesar key where you enter a number > 0 \n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Please Use: ./caesar key where you enter a number > 0 \n");
            return 1;
        }
    }
    return 0;
}

string getTextEncrypted()
{
    string text;
    do
    {
        text = get_string("Please enter the text to be encrypted: ");
    }
    while (text == NULL);
    return text;
}

void textEncrypted(string text, int valNumber)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
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
}