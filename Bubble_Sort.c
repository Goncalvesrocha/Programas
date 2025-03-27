#include<stdio.h>
#include<time.h>
#include<locale.h>

void Bubble_Sort(int);


void Bubble_Sort(int x){

  int i, j, aux, comp = 0, trocas = 0;
  int vet[x];

  srand(time(0));

  for(i = 0; i < x; i++) {
        vet[i] = rand() % 1000; // a função rand() gera números aleatórios para o vetor
   }

   puts("");  // espaçamento para melhorar a leitura na tela
   puts("");  // espaçamento para melhorar a leitura na tela


  //ALGORIMO DO BUBBLE SORT
  for(i = x - 1 ; i > 0; i--){
         for(j = 0; j < i; j++){
             comp = comp + 1; // conta a quantidade de comparações feitas até ordenar
            if (vet[j] > vet[j + 1]){

                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                trocas = trocas + 1;// conta a quantidade de trocas feitas

             }

         }

  }
    for(i = 0; i < x; i++){
        printf("%d ", vet[i]);

        }
             puts("");
             puts("");

  printf("Quantidade de trocas: %d\nQuantidade de comparações: %d\n\n", trocas, comp);

}




int main(){

  setlocale(LC_ALL, "Portuguese");

  int elem;

  printf("Olá, a seguir será apresentado o algoritmo do Bubble Sort\nPor favor, digite um número: ");
  scanf("%d", &elem);

  if (elem <= 0) {
        printf("Número inválido.\n");
        return 1;
    }

  Bubble_Sort(elem);



  return 0;

}

