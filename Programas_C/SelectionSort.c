/*
    Autor:Ryan Rocha
    Data: 17/07/2025
    Descrição :Implementando o algoritmo de ordenação selection sort.

*/

//Sessão de importação
#include <stdio.h>
#include <stdlib.h>

//Sessão de prototipação
void selectionSort(int *, int);


int main()
{
    int vet, elem;

    printf("Digite a quantidade de elementos do vetor: \n");
    scanf("%d", &elem);


    vet = (int*) malloc(elem * sizeof(int)); //Alocando espaço de memória suficiente na variável

    //Memória alocada corretamente
    if(vet != NULL){
        selectionSort(vet, elem);
    }
    //Erro na alocação da memória
    else{
        printf("Erro na alocacao da memoria");
        return 1;
    }

    return 0;

} //fim da main



//Função que implementa o algoritmo que ordena os números
void selectionSort(int * vet, int elem){

    int i = 0, j = 0, h = 0;
    int aux = 0, comp = 0; trocas = 0;

    for(i = 0; i < elem; i++)
    {
        vet[i] = rand() % 1000; //Gerando números aleatórios entre 0 e 1000 para cada índice do vetor
    }

    //Vetor DESORGANIZADO
    for(i = 0; i < elem; i++){
         printf("%d|", vet[i]);
    }
        printf("\n");

    //Selection Sort
    for(i = 0; i < elem - 1; i++)
    {
        j = i; // j começa com 0 depois 1, 2, 3...
        h = 1;

       while(j + h < elem){

            comp++;
            if(vet[j] > vet[j + h]) //j + h próximo índice do vetor a ser comparado com o atual menor índice
            {
                j = j + h;
            }
            else
                h++;
       }
        if(i != j){ //apenas faz troca entre índices diferentes

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


















