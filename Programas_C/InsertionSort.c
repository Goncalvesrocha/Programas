/*
    Autor:Ryan Rocha
    Data: 17/07/2025
    Descrição :Implementando o algoritmo de ordenação insertion sort

*/

//Sessão de importação
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Sessão de prototipação
void insertionSort(int *, int);


int main()
{
    int *vet, elem;

    printf("Digite a quantidade de elementos do vetor: \n");
    scanf("%d", &elem);


    vet = (int*) malloc(elem * sizeof(int)); //Alocando espaço de memória suficiente na variável

    //Memória alocada corretamente
    if(vet != NULL){
        insertionSort(vet, elem);
    }
    //Erro na alocação da memória
    else{
        printf("Erro na alocacao da memoria");
        return 1;
    }

    free(vet);
    
    return 0;

} //fim da main


//Função que implementa o algoritmo
void insertionSort(int * vet, int elem){

    int i, j;
    int trocas = 0;
    int comp = 0;

    srand(time(NULL));

    for(i = 0; i < elem; i++)
    {
        vet[i] = rand() % 1000; //Gerando números aleatórios entre 0 e 1000 para cada índice do vetor
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

            int aux; //variável local que permite a troca dos vetores

            aux = vet[j];
            vet[j] = vet[j + 1];
            vet[j + 1] = aux;
            trocas++;
            j--;
        }
        if (j >= 0)
            comp++; // conta a comparação que quebrou o while
    }

      //Vetor ORGANIZADO
    for(i = 0; i < elem; i++){
         printf("%d|", vet[i]);
    }

    printf("\n");

    printf("Total de comparacoes: %d\n", comp);
    printf("Total de trocas: %d\n", trocas);


} //fim do algoritmo

