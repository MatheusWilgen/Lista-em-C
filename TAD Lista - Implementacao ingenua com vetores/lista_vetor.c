#include "lista_vetor_pr	ivado.h"

lista_t* lista_cria(int c, void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)) {
	//Alocando a estrutura da lista
	lista_t *l = (lista_t*) malloc(sizeof(lista_t));
	if (l == NULL)		 			//caso nao seja possivel alocar a estrutura da lista
		return NULL; 				//retornamos null

	//alocando o vetor de ponteiros void, para acomodar ponteiros para elementos
	l->elementos = (void**) malloc(sizeof(void*)*c);
	if (l->elementos == NULL) {		//caso nao seja possivel...
		free(l);					//devemos liberar a memoria previamente alocada para a lista
		return NULL;				//retornamos null
	}

	//setamos todos os ponteiros para elementos como nulo
	for (int i=0; i<l->tamanho; i++)
		l->elementos[i] = NULL;
	
	l->capacidade 	= c;			//setamos a capacidade da lista (tamanho do vetor)
	l->tamanho 		= 0;			//numero de elementos é zero
	l->imprime 		= imp;			//funcao de impressao de elementos
	l->compara 		= comparar;		//funcao para comparacao de elementos
	l->destruir 	= libera;		//funcao para desalocar um elemento
	
	return l;						//se tudo correu bem, retornamos a lista
}

void lista_destroi(lista_t **l) {
	//se a lista for nula, nada a ser feito
	if (*l == NULL) return;

	//se o vetor for diferente de nulo
	if ((*l)->elementos != NULL) {
		//destruimos cada um dos elementos armazenados
		for (int i=0; i<(*l)->tamanho; i++) {
			if ((*l)->destruir != NULL)
				(*l)->destruir((*l)->elementos[i]); //a função destruir, setada na inicialização da lista
		}										//faz isso. Lembre-se, elementos podem ser complexos.
		free((*l)->elementos);		//após todos elementos deletados, o vetor é então deletado			
	}
	free(*l);						//uma vez que elementos e vetor foram liberados, deletamos a lista
	*l = NULL;						//setamos seu ponteiro para nulo
}

int lista_inicializada(lista_t *l) {
	return l!=NULL;
}

int lista_vazia(lista_t *l) {
	if (!lista_inicializada(l)) {
		return -1;
	} else {
		if (l->tamanho == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

void lista_imprime(lista_t *l) {
	if (!lista_inicializada(l)) {
		printf("Lista nao inicialida.\n");
	} else {
		if (lista_vazia(l)) {
			printf("Lista vazia.\n");
		} else {
			printf("Lista = <");
			for (int i=0; i<(l->tamanho-1); i++) {
				l->imprime(l->elementos[i]);
				printf(", ");
			}
			l->imprime(l->elementos[l->tamanho-1]);
			printf(">\n");
		}
	}
}

int lista_tamanho(lista_t *l) {
	if (!lista_inicializada(l)) {
		return -1;
	} else {
		return l->tamanho;
	}
}

int lista_insere_fim(lista_t *l, const void *e) {
	if (!lista_inicializada(l)) {
		return 0;
	} else {
		if (lista_cheia(l)) {
			if (!lista_realoca_vetor(l)) return 0;
		}
		l->elementos[l->tamanho] = (void*)e;
		l->tamanho++;
		return 1;
	}
}

int lista_insere_inicio(lista_t *l, const void *e) {
	//insere o elemento no inicio (cabeca) da lista
	//retorna 1, caso sucesso, 0 caso contrário
	printf("Eu ainda nao fui implementada :(\n");
}
int lista_insere_posicao(lista_t *l, const void *e, int i) {
	//insere o elemento na posicao especifica
	//retorna 1, caso sucesso, 0 caso contrário
	printf("Eu ainda nao fui implementada :(\n");
}
void* lista_remove_fim(lista_t *l) {
	if (!lista_inicializada(l) || lista_vazia(l)) {
		return  NULL;
	} else {
		l->tamanho--;
		void* elemento = l->elementos[l->tamanho];
		l->elementos[l->tamanho] = NULL;
		return elemento;
	}
}

void* lista_remove_inicio(lista_t *l) {
	//remove o primeiro elemento da lista (cabeca) e retorna o ponteiro para o elemento 
	printf("Eu ainda nao fui implementada :(\n");
}
void* lista_remove_posicao(lista_t *l, int i) {
	//remove o elemento da posicao i e retorna o ponteiro para o elemento
	printf("Eu ainda nao fui implementada :(\n");
}
void* lista_elemento_posicao(lista_t *l, int i) {
	//retorna o ponteiro para o elemento da posicao i
	printf("Eu ainda nao fui implementada :(\n");
}
int lista_encontra_primeiro(lista_t *l, const void *e) {
	//encontra a primeira ocorrencia do elemento apontado por e, e retorna sua posicao
	printf("Eu ainda nao fui implementada :(\n");
}
int lista_altera_posicao(lista_t *l, const void *e, int i) {
	//altera o conteudo da posicao i da lista para o elemento apontado por e
	printf("Eu ainda nao fui implementada :(\n");
}
