/*
    Ex 15
    Autor: Ryan Gonçalves Rocha
    Data: 09/03/2026
    Descrição:  Este programa é um Sistema de gerenciamento de biblioteca desenvolvido em C.
                O programa permite cadastro, busca, listagem e exclusão de livros, leitores e empréstimos,
                além de controle de datas de empréstimo e devolução utilizando a biblioteca time.h.

*/

//Constantes
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
#include <time.h>
#include <string.h>


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
    int codigoLeitor;
    int ramalLivro;
    time_t dataEmprestimo;
    time_t dataDevolucao;
    time_t dataDevolvida;

};

//Variáveis globais
int quantidade = 0; // quantidade de espaços de Livro alocados em livros
int quantidade2 = 0; // quantidade de espaços de Leitor alocados em leitores
int quantidade3 = 0; // quantidade de espaços de Emprestimo alocados em emprestimos

//Estruturas globais
struct Livro* livros = NULL;
struct Leitor* leitores = NULL;
struct Emprestimo* emprestimos = NULL;


//Prototipação das funções de Livro
int cadastrarLivro();
int pesquisarLivro(int);
void listarLivros();
void buscarLivro(int);
void mostrarLivro(int);
int excluirLivro(int);
void menuLivros();

//Prototipação das funções de Leitor
int cadastrarLeitor();
int pesquisarLeitor(int);
void listarLeitores();
void buscarLeitor(int);
void mostrarLeitor(int);
int excluirLeitor(int);
void menuLeitores();

//Prototipação das funções de Empréstimo
int cadastrarEmprestimo();
int pesquisarEmprestimo(int);
void listarEmprestimos();
void buscarEmprestimo(int);
void mostrarEmprestimo(int);
int excluirEmprestimo(int);
void menuEmprestimos();
void imprimirData(time_t t);
void devolucao(int);

//Prototipação do Menu principal
void integrarMenus();




//Main
int main(){

    integrarMenus();

    free(leitores);
    leitores = NULL;
    free(livros);
    livros = NULL;
    free(emprestimos);
    emprestimos = NULL;

return 0;

}//Fim da Main



void integrarMenus(){

    int opcao = 0;
    printf("1 - Livros [OK] \n");
    printf("2 - Leitores [OK] \n");
    printf("3 - Emprestimo [OK] \n");
    printf("4 - Devolucao [!]\n");
    scanf("%d", &opcao);

    switch(opcao){

        case 1:
            menuLivros();
            break;

        case 2:
            menuLeitores();
            break;

        case 3:
            menuEmprestimos();
            break;

        default:
            printf("Nenhuma opcao valida escolhida");
            break;

    }

return 0;

}//Fim da Main



//LIVROS
void menuLivros(){

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
            int cadastro = cadastrarLivro();
            if(cadastro == 0)
                printf("\n ✔ Cadastro realizado com sucesso!");
            else
                printf("\n ❌ Nao foi possivel realizar o cadastro.");
            printf("\n====================================\n\n\n");
            menuLivros();
            break;

        case 2:
            printf("====================================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: BUSCA\n");
            printf("Digite o ramal do livro: ");
            int ramalBu;
            scanf("%d", &ramalBu);
            buscarLivro(ramalBu);
            printf("\n====================================\n\n\n");
            menuLivros();
            break;

        case 3:
            printf("====================================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: LISTAR\n");
            listarLivros();
            printf("\n====================================\n\n\n");
            menuLivros();
            break;

        case 4:
            printf("====================================\n");
            printf("          MENU: LIVROS\n");
            printf("          SESSAO: EXCLUIR\n");
            printf("Digite o ramal do livro: ");
            int ramalEx; scanf("%d", &ramalEx);
            int excluir = excluirLivro(ramalEx);
            if(excluir == 0)
                printf("\n ✔ Livro excluido com sucesso!");
            else
                printf("\n ❌ Livro nao existe!\n Verifique o ramal.");
            printf("\n====================================\n\n\n");
            menuLivros();
            break;

        case 5:
            integrarMenus();
            break;

        default:
            menuLivros();
            break;
    }
}

int cadastrarLivro(){

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

    if(livros == NULL){
        livros = calloc(10, sizeof(struct Livro));
        if(livros == NULL){
            printf("Erro: nao foi possivel alocar memoria!\n");
            exit(1);
        }
    }

    livros[quantidade] = livro;
    quantidade++;
    return 0;
}

int pesquisarLivro(int ramal){
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

void buscarLivro(int ramal){
    printf("a");
    int indice = pesquisarLivro(ramal);

    if (indice == -1){
        printf("⚠️ ESSE LIVRO NAO EXISTE ⚠️\n");
    }
    else
        mostrarLivro(indice);

}

void mostrarLivro(int indice){
     printf("\n\nCodigo do Livro: %d \nNumero do ramal: %d \nNome do livro: %s \nData do cadastro: %s \nCategoria do livro: %s \nEstado do livro: %s \n\n",
            livros[indice].codigo, livros[indice].ramal, livros[indice].nome, livros[indice].data, livros[indice].categoria, livros[indice].estado);

}

void listarLivros(){
    for(int i = 0; i < quantidade; i++){
        if(livros[i].ramal > 0){
            mostrarLivro(i);
        }
    }
   Sleep(5000);
}

int excluirLivro(int ramal){

    int i = pesquisarLivro(ramal);

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
void menuLeitores(){

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
            int cadastro = cadastrarLeitor();
            if(cadastro == 0)
                printf("\n ✔ Cadastro realizado com sucesso!");
            else
                printf("\n ❌ Nao foi possivel realizar o cadastro.");
            printf("\n====================================\n\n\n");
            menuLeitores();
            break;

        case 2:
            printf("====================================\n");
            printf("          MENU: LEITOR\n");
            printf("          SESSAO: BUSCA\n");
            printf("Digite a identidade do leitor: ");
            int id;
            scanf("%d", &id);
            buscarLeitor(id);
            printf("\n====================================\n\n\n");
            menuLeitores();
            break;

        case 3:
            printf("====================================\n");
            printf("          MENU: LEITORES\n");
            printf("          SESSAO: LISTAR\n");
            listarLeitores();
            printf("\n====================================\n\n\n");
            menuLeitores();
            break;

        case 4:
            printf("====================================\n");
            printf("          MENU: LEITORES\n");
            printf("          SESSAO: EXCLUIR\n");
            printf("Digite a identidade do leitor: ");
            int idEx; scanf("%d", &idEx);
            int excluir = excluirLeitor(idEx);
            if(excluir == 0)
                printf("\n ✔ Leitor excluido com sucesso!");
            else
                printf("\n ❌ Leitor nao existe!\n Verifique o código.");
            printf("\n====================================\n\n\n");
            menuLeitores();
            break;

        case 5:
            integrarMenus();
            break;

        default:
            menuLeitores();
            break;
    }

}

int cadastrarLeitor(){

    struct Leitor leitor;
    int status;

    printf("Identidade do Leitor: ");
    scanf("%d", &leitor.id);
    while ((getchar()) != '\n');

    printf("Cpf do Leitor: ");
    scanf(" %14[^\n]", leitor.cpf);
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

    if(leitores == NULL){
        leitores = calloc(10, sizeof(struct Leitor));
        if(leitores == NULL){
            printf("Erro: nao foi possivel alocar memoria!\n");
            exit(1);
        }
    }

    leitores[quantidade2] = leitor;
    quantidade2++;
    return 0;
}

int pesquisarLeitor(int codigo){
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

void buscarLeitor(int codigo){
    printf("a");
    int indice = pesquisarLeitor(codigo);

    if (indice == -1){
        printf("⚠️ LEITOR NAO CADASTRADO NO SISTEMA ⚠️\n");
    }
    else
        mostrarLeitor(indice);

}

void mostrarLeitor(int indice){
     printf("\n\nCodigo do Leitor: %d \nCpf do Leitor: %s \nNome do Leitor: %s \nStatus do Leitor: %s \n\n",
            leitores[indice].id, leitores[indice].cpf, leitores[indice].nome, leitores[indice].statusLeitor);

}

void listarLeitores(){
    for(int i = 0; i < quantidade2; i++){
        if(leitores[i].id > 0){
            mostrarLeitor(i);
        }
    }
   Sleep(5000);
}

int excluirLeitor(int codigo){

    int i = pesquisarLeitor(codigo);

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






//EMPRÉSTIMOS
void menuEmprestimos(){

    int opcao;
    printf("          MENU: EMPRESTIMOS\n");
    printf("====================================\n");
    printf("1 - Cadastrar Novo Emprestimo\n");
    printf("2 - Buscar Emprestimo\n");
    printf("3 - Listar Emprestimos\n");
    printf("4 - Excluir Emprestimo\n");
    printf("5 - Voltar\n");
    printf("====================================\n\n\n");

    scanf("%d", &opcao);
    switch(opcao){

        case 1:
            printf("====================================\n");
            printf("          MENU: EMPRESTIMO\n");
            printf("          SESSAO: CADASTRO\n");
            int cadastro = cadastrarEmprestimo();
            if(cadastro == 0)
                printf("\n ✔ Cadastro realizado com sucesso!");
            else
                printf("\n ❌ Nao foi possivel realizar o cadastro.");
            printf("\n====================================\n\n\n");
            menuEmprestimos(emprestimos);
            break;

        case 2:
            printf("====================================\n");
            printf("          MENU: EMPRESTIMO\n");
            printf("          SESSAO: BUSCA\n");
            printf("Digite o numero do Emprestimo: ");
            int id;
            scanf("%d", &id);
            buscarEmprestimo(id);
            printf("\n====================================\n\n\n");
            menuEmprestimos();
            break;

        case 3:
            printf("====================================\n");
            printf("          MENU: EMPRESTIMO\n");
            printf("          SESSAO: LISTAR\n");
            listarEmprestimos();
            printf("\n====================================\n\n\n");
            menuEmprestimos();
            break;

        case 4:
            printf("====================================\n");
            printf("          MENU: EMPRESTIMO\n");
            printf("          SESSAO: EXCLUIR\n");
            printf("Digite a identidade do Emprestimo: ");
            int idEx; scanf("%d", &idEx);
            int excluir = excluirEmprestimo(idEx);
            if(excluir == 0)
                printf("\n ✔ Emprestimo excluido com sucesso!");
            else
                printf("\n ❌ Emprestimo nao existe!\n Verifique o código.");
            printf("\n====================================\n\n\n");
            menuEmprestimos();
            break;

        case 5:
            integrarMenus();
            break;

        default:
            menuEmprestimos();
            break;
    }
}

int cadastrarEmprestimo(){

    struct Emprestimo emp;

    int contadorTentativas = 0;
    int codigoLeitor = 0;
    int ramalLivro = 0;

    time_t agora = time(NULL);
    struct tm *data;


        //Inserindo e Checando código do Leitor no Sistema
    for(int i = 0; i < 5; i++){
        printf("Digite id do Leitor: ");
        scanf("%d", &codigoLeitor);
        int teste = pesquisarLeitor(codigoLeitor);
        if(teste >= 0){
            break;
        }


        contadorTentativas++;

        if(contadorTentativas == 2){
            printf("⚠️ Esse Leitor NAO EXISTE NO SISTEMA ⚠️ \n Faca o Cadastro do Leitor Primeiro!\n ");
            menuLeitores();
        }
    }
    emp.codigoLeitor = codigoLeitor;

    //Zera as tentativas de procurar o Leitor no sistema
    contadorTentativas = 0;

    //Inserindo e Checando código do Livro no Sistema
    for(int i = 0; i < 5; i++){
        printf("\nDigite o ramal do Livro: ");
        scanf("%d", &ramalLivro);

        if(pesquisarLivro(ramalLivro) >= 0)
            break;

        contadorTentativas++;

        if(contadorTentativas == 2){
            printf("⚠️ Esse Livro NAO EXISTE NO SISTEMA ⚠️\n Faca o Cadastro do Livro Primeiro!\n ");
            menuLivros(livros);
        }
    }
    emp.ramalLivro = ramalLivro;

    printf("\nCódigo do Emprestimo: ");
    scanf(" %[^\n]", &emp.codigo);
    while ((getchar()) != '\n');

    //Definindo datas de Empréstimo e Devolução do Livro
    emp.dataEmprestimo = time(NULL);
    emp.dataDevolucao = time(NULL) + (7 * 86400);

    //Adicionando data para o ponteiro
    data = localtime(&emp.dataEmprestimo);

    //Imprimindo datas
    printf("\nData do Emprestimo: %02d/%02d/%d\n",data->tm_mday,data->tm_mon + 1,data->tm_year + 1900);

     //Atualizando o ponteiro com nova data
     data = localtime(&emp.dataDevolucao);

    //Imprimindo datas
    printf("Data da Devolucao: %02d/%02d/%d\n",data->tm_mday,data->tm_mon + 1,data->tm_year + 1900);

    //Data devolvida é igual a 0. Ou seja, ainda nao foi devolvido o livro
    emp.dataDevolvida = 0;

    if(emprestimos == NULL){
        emprestimos = calloc(10, sizeof(struct Emprestimo));
        if(emprestimos == NULL){
            printf("Erro: nao foi possivel alocar memoria!\n");
            exit(1);
        }
    }

    emprestimos[quantidade3] = emp;
    quantidade3++;

    //Leitor agora está com Status: PENDENTE (precisa devolver livro)
    strcpy(leitores[codigoLeitor].statusLeitor, statusLeitor[1]);
    //Livro tem estado alterado: EMPRESTIMO (não está a disposição no momento)
    strcpy(livros[ramalLivro].estado, estadoLivro[2]);

    return 0;
}

int pesquisarEmprestimo(int codigo){
    if(emprestimos == NULL || quantidade3 <= 0){
        printf("Vetor vazio ou quantidade invalida!\n");
        return -1;
    }

    for(int i = 0; i < quantidade3; i++){
        if(emprestimos[i].codigo == codigo){
            printf("Encontrou no indice %d\n", i);
            return i;
        }
    }

    return -1;
}

void devolucao(int indice){

    time_t agora;
    agora = time(NULL);
    emprestimos[indice].dataDevolvida = agora;
    strcpy(livros[indice].estado, estadoLivro[0]);
    strcpy(leitores[indice].statusLeitor, statusLeitor[0]);

    printf("O livro foi devolvido\n");

}

void buscarEmprestimo(int codigo){
    printf("a");
    int indice = pesquisarEmprestimo(codigo);

    if (indice == -1){
        printf("⚠️ Emprestimo NAO CADASTRADO NO SISTEMA ⚠️\n");
    }
    else
        mostrarEmprestimo(indice);

}

void imprimirData(time_t t) {

    if(t == 0){
        printf("Nao devolvido");
        return;
    }

    struct tm *data = localtime(&t);

    printf("%02d/%02d/%d",
           data->tm_mday,
           data->tm_mon + 1,
           data->tm_year + 1900);
}

void mostrarEmprestimo(int indice){

    printf("\n\nCodigo do Emprestimo: %d\n", emprestimos[indice].codigo);

    printf("Identidade do Leitor : %d", emprestimos[indice].codigoLeitor);

    printf("Identidade do Livro : %d", emprestimos[indice].ramalLivro);

    printf("\nData do Emprestimo: ");
    imprimirData(emprestimos[indice].dataEmprestimo);

    printf("\nData da Devolucao: ");
    imprimirData(emprestimos[indice].dataDevolucao);

    printf("\nData Devolvida: ");
    imprimirData(emprestimos[indice].dataDevolvida);

    printf("\n\n");

}

void listarEmprestimos(){
    for(int i = 0; i < quantidade3; i++){
        if(emprestimos[i].codigo > 0){
            mostrarEmprestimo(i);
        }
    }
   Sleep(5000);
}

int excluirEmprestimo(int codigo){

    int i = pesquisarEmprestimo(codigo);

    if(i != -1){

        emprestimos[i].codigo = 0;
        emprestimos[i].codigoLeitor = 0;
        emprestimos[i].ramalLivro = 0;
        emprestimos[i].dataDevolucao = 0;
        emprestimos[i].dataEmprestimo = 0;
        emprestimos[i].dataDevolvida = 0;

        return 0;
   }

    return 1;
}
