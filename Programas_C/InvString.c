/* Ex11
   Autor: Ryan Gonçalves Rocha
   Data de criação: 27/07/2025
   Esse programa inverte a string "Casa"
*/


#include <stdio.h>
#include <string.h>

int main(){
    char str[5];

    strcpy(str, "Casa");
    printf("Valor da string: %s\n", str);

    int i = 0; // índice do lado esquerdo da string
    int y = strlen(str)-1; // índice do lado direito da string
    int metade = strlen(str)/2; // metade da string

    char aux;
    while(i < metade)
    {
        aux = str[i];
        str[i] = str[y];
        str[y] = aux;

        i++;
        y--;
    }
    printf("Valor da string: ");
    for(int indice = 0; indice < 4; indice++)
    {
        printf("%c", str[indice]);
    }
    puts("\n");

return 0;
}
