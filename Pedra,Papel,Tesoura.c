#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int usuario();
int computador();
void vencedor(int comp, int user);

int main(){

srand(time(NULL));

puts("1. Pedra");
puts("2. Papel");
puts("3. Tesoura");

int user = usuario();
int comp = computador();

  if(user == 1)
      puts("O USER escolheu: Pedra");
  else if(user == 2)
      puts("O USER escolheu: Papel");
  else
      puts("O USER escolheu: Tesoura");


  if(comp == 1)
     puts("O COMPUTER escolheu: Pedra");
   else if(comp == 2)
     puts("O COMPUTER escolheu: Papel");
   else
     puts("O COMPUTER escolheu: Tesoura");

     vencedor(comp, user);

     return 0;
}

int usuario(){

int escolha;

printf("\nEscolha uma opcao: ");
scanf("%d", &escolha);

if(escolha > 0 && escolha < 4)
   return escolha;

 else{
   printf("\n\nOpcao invalida. Programa sera cancelado\n");
   exit(0);
 }

}


int computador(){

return  1 + rand() % 3;;

}


void vencedor(int comp, int user){

if(comp == user)
    puts("**O Jogo empatou**");


else if((comp == 1 && user == 3) || (comp == 2 && user == 1) || (comp == 3 && user == 2))
    puts("**Voce venceu!**");

else
    puts("**Voce perdeu**");

}
