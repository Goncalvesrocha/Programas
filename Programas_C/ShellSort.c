/*
    Autor:Ryan Rocha
    Data: 20/07/2025
    Descrição :Implementando o algoritmo de ordenação shell sort

*/

//Sessão de importação
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Sessão de prototipação
void Shell_Sort(int*, int, int);


int main()
{
    int *vet;
    int elem;

    // COMANDO PARA PERMITIR USAR A FUNÇÃO RAND()
    srand(time(NULL));

    // USUÁRIO DECIDE QUANTOS ELEMENTOS COLOCAR NO VETOR
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &elem);
    int gap = elem / 2;

    // Alocação dinâmica de memória para o vetor
    vet = (int *)malloc(elem * sizeof(int));
    if (vet == NULL)// Verificação de erro de alocação
    {
        printf("Erro ao alocar na memória!\n");
        return 1;
    }
    Shell_Sort(vet, elem, gap);

    return 0;
}//fim da main


//Algoritmo do Shell sort
void Shell_Sort(int * vet, int elem, int gap) {

    // DECLARANDO VARIÁVEIS
    int chave;
    int i = 0;
    int aux = 0;
    int aux2;


    // VETOR DESORDENADO
    printf("A ORDEM INICIAL DO VETOR: \n");
    for (aux = 0; aux < elem; aux++) {
        vet[aux] = rand() % 100000;
        //printf("%d|", vet[aux]);
    }

    // ALGORITMO EM AÇÃO (Baseado em uma variação do Shell Sort)
    while (gap > 0) {

        while (i + gap < elem) { // Verifica se está dentro dos limites do vetor

            if (vet[i] > vet[i + gap]) { // Se o valor atual for maior que o próximo
                aux = vet[i + gap]; // Realiza a troca
                vet[i + gap] = vet[i];
                vet[i] = aux;

                chave = i; // Guarda o valor de i

                // Realiza o movimento para frente (Insertion Sort)
                while (chave-gap >= 0 && vet[i] < vet[chave - gap]) {
                    aux = vet[chave - gap]; // Realizando troca
                    vet[chave - gap] = vet[chave];
                    vet[chave] = aux;

                    chave = chave - gap; // Decrementa o valor de i
                }

            }
            i++; // Incrementa i
        }
        gap = gap / 2; // Reduz o intervalo (gap)
        i = 0; // Restaura i para 0 para reiniciar o processo com o novo gap
    }

    // PRINTANDO NA TELA DO USUÁRIO
    printf("\nVETOR ORDENADO: \n");
    for (aux = 0; aux < elem; aux++) {
        printf("%d|", vet[aux]);
    }

}//fim do algoritmo
