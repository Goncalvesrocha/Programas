#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int inserir_fila(int* filaG);
void exibir_fila(int* filaG);
int retirar_fila(int* filaG);
int is_empty(int* filaG);
int is_full(int* filaG);

int xG, iG = 0;

int is_full(int* filaG){

   int i = 0;

   while(i < 4){
      if (filaG[i] == 0){ 
         iG = i;
         return 1; 
      }
      i++;
   }

   return 0; 
}

int is_empty(int* filaG){

   int i = 0;

   while(i < 4){
      if (filaG[i] != 0){ 
         iG = i;
         return 1; 
      }
      i++;
   }

   return 0; 
}

int inserir_fila(int* filaG) {

   if(is_full(filaG) == 1){

      printf("A Fila NÃO Está CHEIA\n*Inserindo na fila* :");
      scanf("%d", &xG);
      filaG[iG] = xG;

      exibir_fila(filaG);

   } else {
      printf("A Fila Está CHEIA\nNÃO é possível inserir!\n\n");
      return 1; 
   }

   return 0;
}

int retirar_fila(int* filaG){

   if(is_empty(filaG) == 1){

      printf("\nA Fila NÃO Está Vazia\nRetirando...\n");
      filaG[iG] = 0; 

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

   } else {
      printf("\nNão Há Nenhum Número Na Fila\n\n");
      return 1; 
   }

   return 0;
}

void exibir_fila(int* filaG){

   int i = 0;

   do{
      if(filaG[i] != 0) 
         printf("%d|", filaG[i]);

      i++;
   }
   while(i < 4);

   puts("");
}

int main(){

   setlocale(LC_ALL, "Portuguese");

   int filaG[4] = {0}; 
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
