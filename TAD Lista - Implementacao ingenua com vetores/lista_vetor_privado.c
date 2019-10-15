#include "lista_vetor_privado.h"

int lista_cheia(lista_t *l) {
	return (l->capacidade == l->tamanho);
}

int lista_realoca_vetor(lista_t *l) {
	void **elementostmp = (void**) realloc(l->elementos,sizeof(void*) * (l->capacidade + INCREMENTO_TAMANHO));
	if (elementostmp == NULL) {
		return 0;
	} 
	l->elementos = elementostmp;
	l->capacidade = l->capacidade + INCREMENTO_TAMANHO;
	return 1;
}