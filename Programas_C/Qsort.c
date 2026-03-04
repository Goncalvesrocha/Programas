/* Ex12
   Autor: Ryan Gonçalves Rocha
   Data de criação: 24/07/2025
   Ele gera números aleatórios e ordena eles usando a função qsort().
*/

#include <stdio.h>
#include <stdlib.h>

void inserindo(int *, int);
void exibindo(int *, int);
int comparaCrescente(const void*, const void*)

int comparaCrescente(const void* a, const void* b){
    if(*(int*) a == *(int*)b)
       return 0;
    else
        if(*(int*)a < *(int*)b)
            return -1;
        else
            return 1;
}

int main(){

    int* a;
    printf("Tamanho do vetor: ");
    int n;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);

    inserindo(a, n);
    //exibindo(a, n); printf("\n"); // Checando valor desordenado
    qsort(a, n, sizeof(int), comparaCrescente); // Precisa de uma outra função
    exibindo(a, n);//Valor ordenado

return 0;
}

void inserindo(int *a, int n){
    for(int i = 0; i < n; i++)
        a[i] = rand() % 567;
}

void exibindo(int *a, int n){
    for(int i = 0; i < n; i++)
        printf("%d|", a[i]);
}
