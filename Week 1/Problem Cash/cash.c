#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {

float dolar = 0;

do{

 dolar = get_float("Change owed: ");

} while(dolar <= 0);

int centes = round(dolar * 100);

int cont = 0;

do {
 
    for(int i = centes; i >= 25; i -= 25 ){

         if(centes >= 25) {
         centes -= 25;
         cont += 1;
        }

}

    for(int i = centes; i >= 10; i -= 10 ){

         if(centes >= 10) {
         centes -= 10;
         cont += 1;
        }

}

    for(int i = centes; i >= 5; i -= 5 ){

         if(centes >= 5) {
         centes -= 5;
         cont += 1;
        }

}

    for(int i = centes; i >= 1; i -= 1 ){

         if(centes >= 1) {
         centes -= 1;
         cont += 1;
        }

}

} while(centes > 0);

printf("%d\n", cont);
    
}
