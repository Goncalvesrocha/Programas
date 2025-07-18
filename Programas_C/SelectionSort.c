/*
    Autor:Ryan Rocha
    Data: 17/07/2025
    Descri��o :Implementando o algoritmo de ordena��o selection sort.

*/

//Sess�o de importa��o
#include <stdio.h>
#include <stdlib.h>

//Sess�o de prototipa��o
void selectionSort(int *, int);


int main()
{
    int vet, elem;

    printf("Digite a quantidade de elementos do vetor: \n");
    scanf("%d", &elem);


    vet = (int*) malloc(elem * sizeof(int)); //Alocando espa�o de mem�ria suficiente na vari�vel

    //Mem�ria alocada corretamente
    if(vet != NULL){
        selectionSort(vet, elem);
    }
    //Erro na aloca��o da mem�ria
    else{
        printf("Erro na alocacao da memoria");
        return 1;
    }

    return 0;

} //fim da main



//Fun��o que implementa o algoritmo que ordena os n�meros
void selectionSort(int * vet, int elem){

    int i = 0, j = 0, h = 0;
    int aux = 0, comp = 0; trocas = 0;

    for(i = 0; i < elem; i++)
    {
        vet[i] = rand() % 1000; //Gerando n�meros aleat�rios entre 0 e 1000 para cada �ndice do vetor
    }

    //Vetor DESORGANIZADO
    for(i = 0; i < elem; i++){
         printf("%d|", vet[i]);
    }
        printf("\n");

    //Selection Sort
    for(i = 0; i < elem - 1; i++)
    {
        j = i; // j come�a com 0 depois 1, 2, 3...
        h = 1;

       while(j + h < elem){

            comp++;
            if(vet[j] > vet[j + h]) //j + h pr�ximo �ndice do vetor a ser comparado com o atual menor �ndice
            {
                j = j + h;
            }
            else
                h++;
       }
        if(i != j){ //apenas faz troca entre �ndices diferentes

            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
            trocas++;
        }

    }
      //Vetor ORGANIZADO
    for(i = 0; i < elem; i++){
         printf("%d|", vet[i]);
    }

    printf("\n");

    printf("Total de comparacoes: %d\n", comp);
    printf("Total de trocas: %d\n", trocas);

    free(vet);


} //fim do algoritmo


















