/*
   Ex10
   Autor: Ryan Gonçalves Rocha
   Data de criação: 10/02/2024
   Esse programa calcula o fatorial de um número digitado pelo usuário usando recursão
*/

#include <stdio.h>

int fatorial(int);


int main(){

    int num;
    printf("digite um numero: ");
    scanf("%d", &num);

    if(n < 0)
       return -1;

    int resultado = fatorial(num);
    printf("o fatorial do numero escolhido eh: %d", resultado);

return 0;
}


int fatorial(int n){

    if (n == 0)
        return 1;

    else
        return n * fatorial(n - 1);

}

