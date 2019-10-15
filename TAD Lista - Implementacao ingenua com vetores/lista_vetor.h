#include <stdio.h>
#include <stdlib.h>

#ifndef _lista_vetor_

#define _lista_vetor_

typedef struct lista lista_t;

/*
	Cria uma lista de tamanho c
		O tamanho da lista, a função de impressao de elemento, de liberação de memoria de elemento
		e de comparação de elemento devem ser passadas como parametro para a função. Se a alocação
		tiver sucesso, uma lista é retornada. Se não for possivel alocar a estrutura da lista ou
		o vetor de ponteiros que irá armazenar seus elementos, a função retorna NULL.
*/
lista_t* 	lista_cria(int c, void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *));

/*
	Destrói lista
		Recebe uma lista, que é destruída. Ao final desta função, todos elementos que eram armazenados
		na lista terão sido desalocados (a função de destruição de elementos deve ser implementada
		externamente ao TAD, pois cada tipo elemento pode requerer uma função diferente). A lista é desalocada
		juntamente com todas suas estruturas e seu ponteiro passa a apontar para NULL.
*/
void 		lista_destroi(lista_t **l);

/*
	Lista inicializada
		Verifica se a lista esta inicializada. Retorna 1, se estiver, 0 caso contrário.
*/
int 		lista_inicializada(lista_t *l);

/*
	Lista vazia
		Verifica se a lista está vazia. Retorna 1 se a lista está vazia, -1 se não está 
		inicializada e 0, caso tenha sido inicializada e não seja vazia.
*/
int 		lista_vazia(lista_t *l);

/*
	Terminar a listagem de descrição das funções
	Listar suas pré e pós condições
	Terminar de implementar as funções no arquivo lista_vetor.c, algumas não foram implementadas
*/

void 		lista_imprime(lista_t *l);
int 		lista_tamanho(lista_t *l);
int 		lista_capacidade(lista_t *l);
int 		lista_insere_inicio(lista_t *l, const void *e);
int 		lista_insere_fim(lista_t *l, const void *e);
int 		lista_insere_posicao(lista_t *l, const void *e, int i);
void* 		lista_remove_fim(lista_t *l);
void* 		lista_remove_inicio(lista_t *l);
void* 		lista_remove_posicao(lista_t *l, int i);
void* 		lista_elemento_posicao(lista_t *l, int i);
int 		lista_encontra_primeiro(lista_t *l, const void *e);
int 		lista_altera_posicao(lista_t *l, const void *e, int i);

#endif