#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[4];

    people[0].name = "Felipe";
    people[0].number = "8899-7744";

    people[1].name = "Marcella";
    people[1].number = "2255-6644";

    people[2].name = "Yuno";
    people[2].number = "4512-3698";

    people[3].name = "Floop";
    people[3].number = "5566-9999";

   for (int i = 0; i < 4; i++)
   {
       if (strcmp(people[i].name, "Felipe") == 0)
       {
           printf("%s\n", people[i].number);

           return 0;
       }
   }

   printf("Not foud\n");

   return 1;
}