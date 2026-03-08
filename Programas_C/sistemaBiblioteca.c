/*
    Ex 15
    Autor: Ryan Gonçalves Rocha
    Data: 06/03/2026
    Esse programa simula um sistema de biblioteca

*/

//Constantes
#define TEMPOMAX 10

const char* statusLeitor [] = {
    "NORMAL",
    "PENDENTE"
};

const char* estadoLivro[] ={
    "ATIVO",
    "INATIVO",
    "EMPRESTIMO"
};

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Variáveis globais
int quantidade; // quantidade de espaços de Livro alocados em livros
int quantidade2; // quantidade de espaços de Leitor alocados em leitores

//Estruturas
struct Livro{

    int codigo;
    int ramal;
    char nome[50];
    char categoria[25];
    char data[11];
    char estado [11];
};
struct Leitor{

    int id;
    char nome[50];
    char senha[9];
    char cpf[15];
    char statusLeitor[9];
};
struct Emprestimo{

    int codigo;
    char dataEmprestimo[11];
    char dataDevolucao[11];
    struct Livro livro;
    struct Leitor leitor;

};

//Prototipação das funções de Livro
int cadastrarLivro(struct Livro**);
int pesquisarLivro(int, struct Livro*, int);
void listarLivros(struct Livro*, int);
void buscarLivro(int, struct Livro*, int);
void mostrarLivro(int, struct Livro*);
int excluirLivro(int, struct Livro*);
void menuLivros(struct Livro*);

//Prototipação das funções de Leitor
int cadastrarLeitor(struct Leitor**);
int pesquisarLeitor(int, struct Leitor*, int);
void listarLeitores(struct Leitor*, int);
void buscarLeitor(int, struct Leitor*, int);
void mostrarLeitor(int, struct Leitor*);
int excluirLeitor(int, struct Leitor*);
void menuLeitores(struct Leitor*);

//Prototipação das funções de Empréstimo
int cadastrarEmprestimo(struct Emprestimo**);
int pesquisarEmprestimo(int, struct Emprestimo*, int);
void listarEmprestimos(struct Emprestimo*, int);
void buscarEmprestimo(int, struct Emprestimo*, int);
void mostrarEmprestimo(int, struct Emprestimo*);
int excluirEmprestimo(int, struct Emprestimo*);
void menuEmprestimos(struct Emprestimo*);





//Main
int main(){

    struct Livro* livros = NULL;
    struct Livro* leitores = NULL;

    int opcao = 0;
    printf("1 - Livros [OK] \n");
    printf("2 - Leitores [OK] \n");
    printf("3 - Emprestimo [!] \n");
    scanf("%d", &opcao);

    switch(opcao){

        case 1:
            menuLivros(livros);
            break;

        case 2:
            menuLeitores(leitores);
            break;
/*
        case 3:

            break;
*/
        default:
            printf("Nenhuma opcao valida escolhida");
            break;

    }

return 0;

}//Fim da Main






//LIVROS
void menuLivros(struct Livro* livros){

    int opcao;
    printf("          MENU: LIVROS\n");
    printf("====================================\n");
    printf("1 - Cadastrar Novo Livro\n");
    printf("2 - Buscar Livro\n");
    printf("3 - Lista Livros\n");
    printf("4 - Excluir Livro\n");
    printf("5 - Voltar\n");
    printf("====================================\n\n\n");

    scanf("%d", &opcao);
    switch(opcao){

        case 1:
            printf("====================================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: CADASTRO\n");
            int cadastro = cadastrarLivro(&livros);
            if(cadastro == 0)
                printf("\n ✔ Cadastro realizado com sucesso!");
            else
                printf("\n ❌ Nao foi possivel realizar o cadastro.");
            printf("\n====================================\n\n\n");
            menuLivros(livros);
            break;

        case 2:
            printf("====================================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: BUSCA\n");
            printf("Digite o ramal do livro: ");
            int ramalBu;
            scanf("%d", &ramalBu);
            buscarLivro(ramalBu, livros, quantidade);
            printf("\n====================================\n\n\n");
            menuLivros(livros);
            break;

        case 3:
            printf("====================================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: LISTAR\n");
            listarLivros(livros, quantidade);
            printf("\n====================================\n\n\n");
            menuLivros(livros);
            break;

        case 4:
            printf("====================================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: EXCLUIR\n");
            printf("Digite o ramal do livro: ");
            int ramalEx; scanf("%d", &ramalEx);
            int excluir = excluirLivro(ramalEx, livros);
            if(excluir == 0)
                printf("\n ✔ Livro excluido com sucesso!");
            else
                printf("\n ❌ Livro nao existe!\n Verifique o ramal.");
            printf("\n====================================\n\n\n");
            menuLivros(livros);
            break;

        case 5:
            main();
            break;

        default:
            menuLivros(livros);
            break;
    }

    free(livros);
    livros = NULL;
}

int cadastrarLivro(struct Livro** livros){

    struct Livro livro;
    int est;

    printf("Codigo do Livro: ");
    scanf("%d", &livro.codigo);
    while ((getchar()) != '\n'); // Limpa buffer do Enter

    printf("Numero do ramal: ");
    scanf("%d", &livro.ramal);
    while ((getchar()) != '\n'); // Limpa buffer do Enter

    printf("Nome do livro: ");
    scanf(" %49[^\n]", livro.nome); // Lê até o Enter
    while ((getchar()) != '\n'); // Limpa buffer do Enter
    printf("\n");

    printf("Categoria do livro: ");
    scanf(" %24[^\n]", livro.categoria);
    while ((getchar()) != '\n');
    printf("\n");

    printf("Data do cadastro: ");
    scanf(" %10[^\n]", livro.data);
    while ((getchar()) != '\n');
    printf("\n");

    printf("Estado do livro (0)ATIVO/(1)INATIVO: ");
    scanf("%d", &est);
    while ((getchar()) != '\n');
    strcpy(livro.estado, estadoLivro[est]);

    if(*livros == NULL){
        *livros = calloc(10, sizeof(struct Livro));
        if(*livros == NULL){
            printf("Erro: nao foi possivel alocar memoria!\n");
            exit(1);
        }
    }

    (*livros)[quantidade] = livro;
    quantidade++;
    return 0;
}

int pesquisarLivro(int ramal, struct Livro* livros, int quantidade){
    if(livros == NULL || quantidade <= 0){
        printf("Vetor vazio ou quantidade invalida!\n");
        return -1;
    }

    for(int i = 0; i < quantidade; i++){
        if(livros[i].ramal == ramal){
            printf("Encontrou no indice %d\n", i);
            return i;
        }
    }

    return -1;
}

void buscarLivro(int ramal, struct Livro* livros, int quantidade){
    printf("a");
    int indice = pesquisarLivro(ramal, livros, quantidade);

    if (indice == -1){
        printf("⚠️ ESSE LIVRO NAO EXISTE ⚠️\n");
    }
    else
        mostrarLivro(indice, livros);

}

void mostrarLivro(int indice, struct Livro* livros){
     printf("\n\nCodigo do Livro: %d \nNumero do ramal: %d \nNome do livro: %s \nData do cadastro: %s \nCategoria do livro: %s \nEstado do livro: %s \n\n",
            livros[indice].codigo, livros[indice].ramal, livros[indice].nome, livros[indice].data, livros[indice].categoria, livros[indice].estado);

}

void listarLivros(struct Livro* livros, int quantidade){
    for(int i = 0; i < quantidade; i++){
        if(livros[i].ramal > 0){
            mostrarLivro(i, livros);
        }
    }
   Sleep(5000);
}

int excluirLivro(int ramal, struct Livro* livros){

    int i = pesquisarLivro(ramal, livros, quantidade);

    if(i != -1){

        livros[i].codigo = 0;
        livros[i].ramal = 0;
        strcpy(livros[i].nome,  " ");
        strcpy(livros[i].data,  " ");
        strcpy(livros[i].categoria, " ");
        strcpy(livros[i].estado, " ");

        return 0;
   }

    return 1;
}







//LEITORES
void menuLeitores(struct Leitor* leitores){

    int opcao;
    printf("          MENU: LEITORES\n");
    printf("====================================\n");
    printf("1 - Cadastrar Novo Leitor\n");
    printf("2 - Buscar Leitor\n");
    printf("3 - Lista Leitores\n");
    printf("4 - Excluir Leitor\n");
    printf("5 - Voltar\n");
    printf("====================================\n\n\n");

    scanf("%d", &opcao);
    switch(opcao){

        case 1:
            printf("====================================\n");
            printf("          MENU: LEITORES\n");
            printf("          SESSAO: CADASTRO\n");
            int cadastro = cadastrarLeitor(&leitores);
            if(cadastro == 0)
                printf("\n ✔ Cadastro realizado com sucesso!");
            else
                printf("\n ❌ Nao foi possivel realizar o cadastro.");
            printf("\n====================================\n\n\n");
            menuLeitores(leitores);
            break;

        case 2:
            printf("====================================\n");
            printf("          MENU: LEITOR\n");
            printf("          SESSAO: BUSCA\n");
            printf("Digite a identidade do leitor: ");
            int id;
            scanf("%d", &id);
            buscarLeitor(id, leitores, quantidade2);
            printf("\n====================================\n\n\n");
            menuLeitores(leitores);
            break;

        case 3:
            printf("====================================\n");
            printf("          MENU: LEITORES\n");
            printf("          SESSAO: LISTAR\n");
            listarLeitores(leitores, quantidade2);
            printf("\n====================================\n\n\n");
            menuLeitores(leitores);
            break;

        case 4:
            printf("====================================\n");
            printf("          MENU: LEITORES\n");
            printf("          SESSAO: EXCLUIR\n");
            printf("Digite a identidade do leitor: ");
            int idEx; scanf("%d", &idEx);
            int excluir = excluirLeitor(idEx, leitores);
            if(excluir == 0)
                printf("\n ✔ Leitor excluido com sucesso!");
            else
                printf("\n ❌ Leitor nao existe!\n Verifique o código.");
            printf("\n====================================\n\n\n");
            menuLeitores(leitores);
            break;

        case 5:
            main();
            break;

        default:
            menuLeitores(leitores);
            break;
    }

    free(leitores);
    leitores = NULL;
}

int cadastrarLeitor(struct Leitor** leitores){

    struct Leitor leitor;
    int status;

    printf("Identidade do Leitor: ");
    scanf("%d", &leitor.id);
    while ((getchar()) != '\n');

    printf("Cpf do Leitor: ");
    scanf(" %14[^\n]", &leitor.cpf);
    while ((getchar()) != '\n');

    printf("Nome do Leitor: ");
    scanf(" %49[^\n]", leitor.nome);
    while ((getchar()) != '\n');
    printf("\n");

    printf("Senha do Leitor: ");
    scanf(" %8[^\n]", leitor.senha);
    while ((getchar()) != '\n');
    printf("\n");

    printf("Status do Leitor: (0)NORMAL / (1)PENDENTE : ");
    scanf("%d", &status);
    while ((getchar()) != '\n');
    strcpy(leitor.statusLeitor, statusLeitor[status]);

    if(*leitores == NULL){
        *leitores = calloc(10, sizeof(struct Leitor));
        if(*leitores == NULL){
            printf("Erro: nao foi possivel alocar memoria!\n");
            exit(1);
        }
    }

    (*leitores)[quantidade2] = leitor;
    quantidade2++;
    return 0;
}

int pesquisarLeitor(int codigo, struct Leitor* leitores, int quantidade2){
    if(leitores == NULL || quantidade2 <= 0){
        printf("Vetor vazio ou quantidade invalida!\n");
        return -1;
    }

    for(int i = 0; i < quantidade2; i++){
        if(leitores[i].id == codigo){
            printf("Encontrou no indice %d\n", i);
            return i;
        }
    }

    return -1;
}

void buscarLeitor(int codigo, struct Leitor* leitores, int quantidade2){
    printf("a");
    int indice = pesquisarLeitor(codigo, leitores, quantidade2);

    if (indice == -1){
        printf("⚠️ LEITOR NAO CADASTRADO NO SISTEMA ⚠️\n");
    }
    else
        mostrarLeitor(indice, leitores);

}

void mostrarLeitor(int indice, struct Leitor* leitores){
     printf("\n\nCodigo do Leitor: %d \nCpf do Leitor: %s \nNome do Leitor: %s \nStatus do Leitor: %s \n\n",
            leitores[indice].id, leitores[indice].cpf, leitores[indice].nome, leitores[indice].statusLeitor);

}

void listarLeitores(struct Leitor* leitores, int quantidade2){
    for(int i = 0; i < quantidade2; i++){
        if(leitores[i].id > 0){
            mostrarLeitor(i, leitores);
        }
    }
   Sleep(5000);
}

int excluirLeitor(int codigo, struct Leitor* leitores){

    int i = pesquisarLeitor(codigo, leitores, quantidade2);

    if(i != -1){

        leitores[i].id = 0;
        strcpy(leitores[i].cpf,  " ");
        strcpy(leitores[i].nome,  " ");
        strcpy(leitores[i].senha, " ");
        strcpy(leitores[i].statusLeitor, " ");

        return 0;
   }

    return 1;
}
