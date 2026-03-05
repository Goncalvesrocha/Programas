/*
    Ex14
    Autor: Ryan Gonçalves Rocha
    Data:22/02/2025
    Esse programa procura um número dentro de um vetor ordenado usando busca binária.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int vetor[1000];
    int pivot = 0;
    int numero = 0;
    int inicio = 0, fim = 0;
    int tamanho = sizeof(vetor)/sizeof(int);
    int cont = 0;

    for(int i = 0; i < tamanho; i++){
        vetor[i] = i;
    }
    for(int i = 0 ; i < tamanho; i++)
        printf("vetor[%d] = %d \n", i, vetor[i]);

    inicio = 0;
    fim = tamanho - 1;
    pivot = fim/2;

    printf("DIGITE UM NUMERO DENTRO DO VETOR:");
    scanf("%d", &numero);

    while(vetor[pivot] != numero){

        if(vetor[pivot] > numero)
            fim = pivot - 1;

        else if(vetor[pivot] < numero)
                inicio = pivot + 1;

        pivot = (fim + inicio) / 2;
        cont++;
    }
    printf("\n\nNUMERO:%d, ENCONTRADO NA POSICAO: vetor[%d]\n", numero, pivot);
    printf("Quantidade de iteracoes no while: %d", cont);

    return 0;
}
