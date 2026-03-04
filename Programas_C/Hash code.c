/*
   Ex13
   Autor: Ryan Gonçalves Rocha
   Data de criação: 18/09/2025
   Esse programa verifica se existe algum par de números inteiros positivos (x, y) que seja igual ao número digitado.

*/

#include <stdio.h>

int Hash(int, int);
int invHash(int);

//Função Main
int main()
{
    int num;

    printf("Digite um numero: \n");
    scanf("%d", &num);

    if(invHash(num) == -1){
        printf("NO");
        return 0;
    }
    else
       printf("YES");

    return 0;
}

//Função Inverter o Hash
int invHash(int z)
{
    for(int i = 1; i < z; i++){

        for(int y = 1; y < z; y++){

            if(z == Hash(i, y)){
               return i;
            }
        }
    }
    return -1;
}


//Função Hash
int Hash(int x, int y)
{
    return (x*x) + 2 *(x*y) + x + 1;

}
