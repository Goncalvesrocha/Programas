/*
    Autor:Ryan Rocha
    Data: 17/07/2025
    Descri��o :Implementando o algoritmo de ordena��o insertion sort

*/

//Sess�o de importa��o
#include <stdio.h>
#include <stdlib.h>

//Sess�o de prototipa��o
void insertionSort(int *, int);


int main()
{
    int *vet, elem;

    printf("Digite a quantidade de elementos do vetor: \n");
    scanf("%d", &elem);


    vet = (int*) malloc(elem * sizeof(int)); //Alocando espa�o de mem�ria suficiente na vari�vel

    //Mem�ria alocada corretamente
    if(vet != NULL){
        insertionSort(vet, elem);
    }
    //Erro na aloca��o da mem�ria
    else{
        printf("Erro na alocacao da memoria");
        return 1;
    }

    return 0;

} //fim da main


//Fun��o que implementa o algoritmo
void insertionSort(int * vet, int elem){

    int i, j;
    int trocas = 0;
    int comp = 0;

    for(i = 0; i < elem; i++)
    {
        vet[i] = rand() % 1000; //Gerando n�meros aleat�rios entre 0 e 1000 para cada �ndice do vetor
    }

    //Vetor DESORGANIZADO
    for(i = 0; i < elem; i++){
         printf("%d|", vet[i]);
    }
        printf("\n");

    //Insertion Sort
    for(i = 0; i < elem - 1; i++)
    {
        j = i;

        while (vet[j] > vet[j + 1] && j >= 0)
        {
            comp++;

            int aux; //vari�vel local que permite a troca dos vetores

            aux = vet[j];
            vet[j] = vet[j + 1];
            vet[j + 1] = aux;
            trocas++;
            j--;
        }
        if (j >= 0)
            comp++; // conta a compara��o que quebrou o while
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

