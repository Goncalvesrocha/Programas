/*
 * Ex:16
 * Autor: Ryan Gonçalves Rocha
 * Data: 03/04/2026
 * Descrição: Implementação de uma lista encadeada simples em linguagem C.
  O programa permite inserir elementos no final da lista, percorrer
  e imprimir seus valores, buscar elementos por valor e remover um
  nó específico da lista. O foco principal está na manipulação de
  ponteiros e na operação de exclusão de nós.
 */

//Sessao de importacao
#include <stdio.h>
#include <stdlib.h>

//Declarando Struct No
typedef struct No {
	int valor;
	struct No *ptr;
} No;

//Sessao de prototipacao
int inserirNoFim(No** last, int valor);
int printarLista(No* no);
int printarPorId(No* no, int valor);
int excluirLista(No** excluir, int valor);

//Variavel global
No* primeiroIndice;
No* excluirIndice;

int main() {
	No* last = (No*)malloc(10 * sizeof(No));
	if(last == NULL) {
		printf("Falha na alocacao dinamica");
		return 1;
	}
	primeiroIndice = last;
	inserirNoFim(&last, 1);
	inserirNoFim(&last, 2);
	inserirNoFim(&last, 3);
	inserirNoFim(&last, 4);
	inserirNoFim(&last, 5);
	inserirNoFim(&last, 6);
	printarLista(primeiroIndice);

	excluirLista(&primeiroIndice, 3);

	free(last);
	last = NULL;
}

int printarLista(No* no) {

	while(1) {
		if(no->ptr != NULL){
		    printf("endereco: %p\n", no);
			printf("valor: %d\n", no->valor);
			printf("aponta para %p->", no->ptr);
		}
		else {
			printf("NULL");
			break;
		}
		no = no->ptr;
	}
	return 0;
}

int inserirNoFim(No** last, int valor) {

	No* novo = malloc(sizeof(No));

	novo->valor = valor;
	novo->ptr = NULL;

	if((*last) != NULL) {
		(*last)->valor = valor;
		(*last)->ptr = novo;
	}

	(*last) = novo;

	return 0;
}

int printarPorId(No* no, int valor){
    while(no->ptr != NULL) {
		if(no->valor == valor){
		    printf("Valor: %d\n Posicao: %p\n Endereco que aponta: %p\n", no->valor, (*no), no->ptr);
		    return 0;
		}
		no = no->ptr;
	}
	return 1;
}

int excluirLista(No** excluir, int valorExcluir){
    No* atual = *excluir;
    No* anterior = NULL;

    while(atual != NULL){

        if(atual->valor == valorExcluir){

            if(anterior == NULL){
                *excluir = atual->ptr;
            } else {
                anterior->ptr = atual->ptr;
            }

            free(atual);
            return 0;
        }

        anterior = atual;
        atual = atual->ptr;
    }

    return 1;
}