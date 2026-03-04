/* Ex09
   Autor: Ryan Gonçalves Rocha
   Data de criação: 20/05/2025
   Esse programa inverte todos os bits de cada caractere da string e imprime o resultado
*/

#include <stdio.h>

/*
    Operadores bit a bit:

    Os operadores bit a bit podem ser usados em rotinas de criptografia.

    Com algumas manipulações em bits o arquivo se tornará ilegível.

    Um dos métodos mais simples é usar o "complemento de um: '~' " para
    inverter cada bit em um byte, exemplo:

            Se Byte Original = 0 0 1 0 1 1 0 0
                Então, ~ Byte Original = 1 1 0 1 0 0 1 1

                Enquanto para decodificar
                 ~(~ Byte Original) = 0 0 1 0 1 1 0 0
*/

char encode(char ch);

int main(){

    char str[] = {"Hello World!"};

    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", encode(str[i]));
    }

return 0;
}


char encode(char ch){

    return (~ch);
}






