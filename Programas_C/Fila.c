#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int inserir_fila(int* filaG);
void exibir_fila(int* filaG);
int retirar_fila(int* filaG);
int is_empty(int* filaG);
int is_full(int* filaG);


int xG, iG = 0; // A letra G vem de Variável Global


int is_full(int* filaG){

   int i = 0;
   int cont = 0;

  while(i < 4){

     if (filaG[i] == NULL){
         iG = i; // Guarda o índice que está vazio
         return 1; //Não está cheio
     }
         i++;
  }

}


int is_empty(int* filaG){

 int i = 0;
 int cont = 0;

  while(i < 4){

     if (filaG[i] != NULL){
         iG = i; //Guarda o índice que tem um valor
         return 1; //Não está vázio
     }
        i++;
  }
}




int inserir_fila(int* filaG) {

   if(is_full(filaG) == 1){

      printf("A Fila NÃO Está CHEIA\n*Inserindo na fila* :");
      scanf("%d", &xG);
      filaG[iG] = xG; // O indíce que está vázio recebe um novo valor

      exibir_fila(filaG);

   }
   else
      printf("A Fila Está CHEIA\nNÃO é possível inserir!\n\n");
      return 1;

  return 0;
}


int retirar_fila(int* filaG){

    if(is_empty(filaG) == 1){

        printf("\nA Fila NÃO Está Vázia\nRetirando...\n");
        filaG[iG] = NULL;

        int o = 0;
        while(o < 4){

              if(filaG[o] == 0){

                 for(int i = o + 1; i < 4; i++){

                     if(filaG[i] != 0){
                        filaG[o] = filaG[i];
                        filaG[i] = 0;
                        break;
            }
       }
   }
   o++;
}
        exibir_fila(filaG);

    }
    else
       printf("\nNão Há Nenhum Número Na Fila\n\n");
       return 1;

  return 0;
}

void exibir_fila(int* filaG){

    int  i = 0;

    do{
        if(filaG[i] != NULL)
            printf("%d|", filaG[i]);

           i++;
    }
    while(i < 4);
    puts("");
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int filaG[4] = {};
    int yG, iG;

    inserir_fila(filaG);
    inserir_fila(filaG);
    inserir_fila(filaG);
    inserir_fila(filaG);

    retirar_fila(filaG);
    retirar_fila(filaG);
    inserir_fila(filaG);
    inserir_fila(filaG);

    inserir_fila(filaG);
    inserir_fila(filaG);
    retirar_fila(filaG);
    retirar_fila(filaG);

    inserir_fila(filaG);
    retirar_fila(filaG);
    retirar_fila(filaG);

    inserir_fila(filaG);
    inserir_fila(filaG);
    inserir_fila(filaG);

    return 0;
}

