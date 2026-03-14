//Sessão de Importação
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constante para estado do livro
const char* estadoLivro[] = {
    "ATIVO",
    "INATIVO",
    "EMPRESTIMO"
};

//Variável Global
int itens = 4;
char conteudo[200];

//Estrutura de Livro
typedef struct Livro {
        int codigo;
        char nome[50];
        char categoria[25];
        char data[11];
        char estado[11];

}Livro;

//Sessão de Prototipação
int criarArquivo(FILE*);
int escreverArquivo(FILE*);
char* lerArquivo(FILE*);
int excluirArquivo(FILE*);

int main()
{
    FILE *f;
    int escolha;

    if(criarArquivo(f) == 1){
           printf("\n1 - Erro na Criacao do Arquivo. Programa Finalizando...\n");
           return 1;
        }
        printf("\n1 - Arquivo Pronto!\n\n");
       
    printf("ESCOLHA:\n\n(1)Escrever No Arquivo \n(2)Ler Arquivo \n(3)Excluir do Arquivo\n\n>");
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            if(escreverArquivo(f) == 1){
                    printf("\n1 - Erro na Escrita do Arquivo. Programa Finalizando...\n");
                    return 1;
                }
                printf("\n1 - Escreveu no Arquivo!\n");
            break;
        case 2:
             if(lerArquivo(f) == NULL){
                    printf("\n2 - Erro na Leitura do Arquivo. Programa Finalizando...\n");
                    return 1;
                }
                printf("\n2 - Leu o Arquivo!\n");
             break;
        case 3:
             if(excluirArquivo(f) == 1){
                    printf("\n3 - Erro na Exclusao do Arquivo. Programa Finalizando...\n");
                    return 1;
                }
                printf("\n3 - Excluiu o Arquivo!\n");
            break;
        default:
                printf("\nNenhuma opcao valida foi selecionada!");
            break;
    }
       
    return 0;
}


int criarArquivo(FILE* f)
{
    if(f == NULL){
        f = fopen("Livros.txt", "w"); //Criando arquivo se nao existir
            if(f == NULL){
                return 1;
            }
    }
    return 0;
}


int escreverArquivo(FILE *f)
{  
        f = fopen("Livros.txt", "a"); //Modo de escrita
                           
        if(f == NULL){
             printf("Erro, Escrita impossivel. Resultado: NULL");
             return 1;
        }
       
        Livro escLivro;
        int estado;
       
        printf("Codigo do Livro: ");
        scanf("%d", &escLivro.codigo);
        while ((getchar()) != '\n'); // Limpa buffer do Enter

        printf("Nome do livro: ");
        scanf(" %49[^\n]", escLivro.nome); // Lê até o Enter
        while ((getchar()) != '\n'); // Limpa buffer do Enter

        printf("Categoria do livro: ");
        scanf(" %24[^\n]", escLivro.categoria);
        while ((getchar()) != '\n');

        printf("Data do cadastro: ");
        scanf(" %10[^\n]", escLivro.data);
        while ((getchar()) != '\n');

        printf("Estado do livro: (0)ATIVO/(1)INATIVO/(2)EMPRESTIMO: ");
        scanf("%d", &estado);
        while ((getchar()) != '\n');
        strcpy(escLivro.estado, estadoLivro[estado]);
       
        fprintf(f, "%d ", escLivro.codigo);
        fprintf(f, "%s ", escLivro.nome);
        fprintf(f, "%s ", escLivro.categoria);
        fprintf(f, "%s ", escLivro.data);
        fprintf(f, "%s\n", escLivro.estado);
       
        return 0;  
               
}

char* lerArquivo(FILE* f)
{
        f = fopen("Livros.txt", "r"); //Modo de leitura
        if(f == NULL){
             printf("\nErro, impossivel fazer Leitura. Resultado: NULL");
             exit(1);
        }
       
        int i = 0;
       
        while(i < 10){   //10 linhas no maximo; 10 cadastros de livros no maximo          
            fgets(conteudo, 70, f);
            printf("%s \n", conteudo);
            conteudo[0] = '\0';
            i++;
        }
        
        return conteudo;
}

int excluirArquivo(FILE *f)
{
      remove("Livros.txt");
      if(f != NULL)
           return 1;
      fclose(f);                
      return 0;    
}