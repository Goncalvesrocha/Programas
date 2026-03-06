/*
    Ex 15
    Autor: Ryan Gonçalves Rocha
    Data: 06/03/2026
    Esse programa simula um sistema de biblioteca

*/

//Constantes
#define TEMPOMAX 10

const char* status [] = {
    "NORMAL",
    "PENDENTE"
};

const char* estado[] ={
    "ATIVO",
    "INATIVO",
    "EMPRESTIMO"
};


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>


//Estruturas
struct Livro{

    int codigo;
    int ramal;
    char* nome;
    char* categoria;
    char data[10];
    char* estado;
};

struct Leitor{

    int id;
    char* nome;
    char* senha;
    char cpf[14];
    char* statusLeitor;
};


struct Emprestimo{

    int codigo;
    char dataEmprestimo[10];
    char dataDevolucao[10];
    struct Livro livro;
    struct Leitor leitor;

};


//Prototipação
int cadastrarLivro(struct Livro**);
int pesquisarLivro(int, struct Livro**);
void buscarLivro(int, struct Livro**);
void mostrarLivro(int, struct Livro**);
int excluirLivro(int, struct Livro**);
void menuLivros(struct Livro**);


//Main
int main(){

    struct Livro *livros;
    int opcao = 0;

    printf("1 - Livros ✔");
    printf("2 - Leitores ❌");
    printf("3 - Emprestimo ❌");
    scanf("%d", opcao);

    switch(opcao){

        case 1:
            menuLivros(livros);
            break;
/*
        case 2:

            break;

        case 3:

            break;
*/
        default:
            printf("SEXO, virj\n So tem o 1 ne genio");
            break;

    }

return 0;
}



//Livros
void menuLivros(struct Livro **livros){

    int opcao;
    printf("          MENU: LIVROS\n");
    printf("==========================\n");
    printf("1 - Cadastrar Novo Livro\n");
    printf("2 - Buscar Livro\n");
    printf("3 - Excluir Livro\n");
    printf("4 - Voltar\n");
    printf("==========================\n\n\n");

    scanf("%d", &opcao);
    switch(opcao){

        case 1:
            printf("==========================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: CADASTRO\n");
            int cadastro = cadastrarLivro(livros);
            if(cadastro == 0)
                printf("\n ✔ Cadastro realizado com sucesso!");
            else
                printf("\n ❌ Nao foi possivel realizar o cadastro.");
            printf("\n==========================\n\n\n");
            menuLivros(livros);
            break;

        case 2:
            printf("==========================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: BUSCA\n");
            printf("Digite o ramal do livro: ");
            int ramalBu; scanf("%d", &ramalBu);
            buscarLivro(ramalBu, livros);
            printf("\n==========================\n\n\n");
            menuLivros(livros);
            break;

        case 3:
            printf("==========================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: EXCLUIR\n");
            printf("Digite o ramal do livro: ");
            int ramalEx; scanf("%d", &ramalEx);
            int excluir = excluirLivro(ramalEx, livros);
            if(excluir == 0)
                printf("\n ✔ Livro excluido com sucesso!");
            else
                printf("\n ❌ Livro nao existe!\n Verifique o ramal.");
            printf("\n==========================\n\n\n");
            menuLivros(livros);
            break;

        case 4:
            main();
            break;

    }

}

int cadastrarLivro(struct Livro** livros){

    struct Livro livro;

    printf("Codigo do Livro: ");
    scanf("%d", &livro.codigo);

    printf("Numero do ramal: ");
    scanf("%d", &livro.ramal);

    printf("\nNome do livro: ");
    scanf("%s", livro.nome);

    printf("\nCategoria do livro: ");
    scanf("%s", livro.categoria);

    printf("\nData do cadastro: ");
    scanf("%s", livro.data);

    printf("\nEstado do livro (0)ATIVO/(1)INATIVO: ");
    int est; scanf("%d", &est);
    strcpy(livro.estado, estado[est]);

    if(livros == NULL){
        livros[0] = &livro;
        return 0;
    }
    int tamanho = (sizeof(livros)/sizeof(struct Livro)) + 1;
    int *temp = realloc(livros, tamanho * sizeof(livros));
    if(temp != NULL)
        livros = temp;
    else
        return 1;

    livros[tamanho] = &livro;

    return 0;
}

int pesquisarLivro(int ramal, struct Livro** livros){
    for(int i = 0; i < sizeof(livros); i++){
        if(livros[i]->ramal == ramal)
            return i;
    }
    return -1;
}

void buscarLivro(int ramal, struct Livro** livros){
    if (pesquisarLivro(ramal, livros) == -1){
        printf("⚠️ ESSE LIVRO NAO EXISTE ⚠️");
    }
    mostrarLivro(pesquisarLivro(ramal, livros), livros);
}

void mostrarLivro(int indice, struct Livro **livros){
     printf("\n\nCodigo do Livro: %d \nNumero do ramal: %d \nNome do livro: %s \nData do cadastro: %s \nCategoria do livro: %s \nEstado do livro: %s \n\n",
            livros[indice]->codigo, livros[indice]->ramal, livros[indice]->nome, livros[indice]->data, livros[indice]->categoria, livros[indice]->estado);

}

int excluirLivro(int ramal, struct Livro** livros){
    int i = pesquisaLivro(ramal, livros);
    if(i != -1){
        livros[i] = NULL;
        int tamanho = sizeof(livros - 1);
        int *temp = realloc(livros, tamanho * sizeof(livros));
        if(temp != NULL){
            livros = temp;
            return 0;
        }
    }
    return 1;
}
//Fim de livros




