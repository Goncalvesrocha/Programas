/* Ex08
   Autor: Ryan Gonçalves Rocha
   Data de criação: 06/03/2025
   O programa gere um vetor e o organiza em ordem alfabética
*/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>


int main(){

    char string[20], aux;
    int a, j;

    srand(time(NULL));

    printf("VETOR SEM ORDEM ALFABÉTICA:\n");
    for(a = 0; a < 20; a++){
        string[a] = 97 + (char)(rand()%26);
        printf("%c|", string[a]);
    }

    for(j = 19; j > 0; j--){

      for(a = 0; a < j; a++){

        if((int)string[a] > (int)string[a+1]){
            aux = string[a+1];
            string[a+1] = string[a];
            string[a] = aux;
        }
    }

}

    printf("\n\nVETOR COM ORDEM ALFABÉTICA:\n");
    for(a = 0; a < 20; a++){
        printf("%c|", string[a]);
    }

}

