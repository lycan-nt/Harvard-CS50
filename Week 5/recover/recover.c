#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
void recover(FILE *inputFile);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use: ./revocer Image_Name\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (inputFile == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    recover(inputFile);
    return 0;
}

void recover(FILE *inputFile)
{
    unsigned char buffer[512];
    int countImage = 0;
    FILE *outputFile = NULL;
    char *fileName = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, inputFile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
        && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(fileName, "%03i.jpg", countImage);
            if (countImage > 0)
            {
                fclose(outputFile);
            }
            outputFile = fopen(fileName, "w");
            countImage++;
        }
        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outputFile);
        }
    }
    free(fileName);
    fclose(outputFile);
    fclose(inputFile);
}