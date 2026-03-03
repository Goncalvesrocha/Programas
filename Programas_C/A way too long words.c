#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(){

   char str[100];
   scanf("%s", str);

    int cont = strlen(str);
    if(cont > 10){
       printf("%c%d%c", str[0], cont-2, str[cont-1]);
    }
    else if(isdigit(str[0]) == false)
        for(int i = 0; i <= 10; i++){
            if(str[i] == '\0')
               break;
            printf("%c", str[i]);
        }

return 0;
}
