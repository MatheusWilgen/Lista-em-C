#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_vetor.h"


//Definição de funções para uma lista de inteiros
void imprime_elemento_int(const void *e) {
	printf("%d",*(int*)e);
}

void destroi_elemento_int(void *e) {
	if (e != NULL)
		free(e);
}

int compara_elemento_int(const void *e1, const void *e2) {
	if (*((int*)e1) == *((int*)e2))
		return 0;
	else 
		if (*((int*)e1) < *((int*)e2))
			return -1;
		else
			return 1;
}

//Definição de funções para uma lista de strings
void imprime_elemento_string(const void *e) {
	printf("%s",(char*)e);
}

void destroi_elemento_string(void *e) {
	if (e != NULL)
		free(e);
}

int compara_elemento_string(const void *e1, const void *e2) {
	return strcmp((char*)e1,(char*)e2);
}


int main() {
	lista_t *li, *ls, *lsd;

	char *numeros[10] = {"zero", "um", "dois", "tres", "quatro",
					     "cinco", "seis", "sete", "oito", "nove"};
	
	li = lista_cria(2,imprime_elemento_int,destroi_elemento_int,compara_elemento_int);
	
	ls = lista_cria(10,imprime_elemento_string,NULL,compara_elemento_string);

	lsd = lista_cria(10,imprime_elemento_string,destroi_elemento_string,compara_elemento_string);

	lista_imprime(li);
	lista_imprime(ls);

	char *str;

	for (int i=0; i<10; i++) {
		str = (char*) malloc (sizeof(char)*65);
		printf("Digite um valor para a lista de strings: ");
		fgets(str,65,stdin);
		str[strlen(str)-1] = '\0';

		lista_insere_fim(lsd,str);
		
		int *elemento = (int*) malloc(sizeof(int));
		*elemento = 10 - i;
		
		lista_insere_fim(li,elemento);
		
		lista_insere_fim(ls,numeros[i]);
	}

	lista_imprime(li);
	lista_imprime(ls);
	lista_imprime(lsd);

	int *elemento = lista_remove_fim(li);
	printf("Elemento removido: %d.\n",*elemento);
	free(elemento);

	char *estr = lista_remove_fim(ls);
	printf("Elemento removido: %s.\n",estr);
	//nao devemos desalocar, pois as strings sao estaticas!!!

	str = lista_remove_fim(lsd);
	printf("Elemento removido: %s.\n",str);
	free(str); //nesse caso precisamos desalocar a memoria...


	lista_imprime(li);
	lista_imprime(ls);
	lista_imprime(lsd);

	lista_destroi(&li);
	lista_destroi(&ls);
	lista_destroi(&lsd);

	lista_imprime(li);	
	lista_imprime(ls);
	lista_imprime(lsd);
	return 0;
}