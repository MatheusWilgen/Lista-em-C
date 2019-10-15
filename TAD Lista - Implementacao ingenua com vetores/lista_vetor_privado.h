#include "lista_vetor.h"

#ifndef _lista_vetor_privado_

#define _lista_vetor_privado_

/*******************************************************************************************************
	Definição da estrutura da lista

		- Ponteiro duplo para void
			A ideia é alocar um array de ponteiros void onde cada posição do array pode apontar
			para qualquer tipo de dados (um tipo por lista). Desta forma a lista fica genérica, 
			ou seja, funciona para qualquer tipo de dados. Note que uma lista pode armazenar um
			único tipo por vez, ou seja, a lista deve ser homogênea, de elementos do mesmo tipo.
		
		- O tamanho da lista, ou seja, seu número de elementos
			Inicialmente este valor é zero, pois as listas criadas são vazias.
		
		- A capacidade da lista
			Indica o tamanho atual do array que guarda ponteiros para seus elementos. Se a lista 
			crescer além da capacidade esse array deve ser realocado, e a capacidade atualizada.
		
		- Destruir 
		    Um ponteiro para uma função que destrói um elemento da lista. Como a lista é genéria, cada tipo 
		    de elemento deve ser desalocado de uma forma específica. Se os elementos armazenados na lista são 
		    estruturas, por exemplo, desalocá-las pode ser uma tarefa complexa. Dessa forma, a função de 
		    desalocação deve ser implementada pelo usuário do TAD Lista para cada tipo de elemento que ele 
		    deseja usar. O ponteiro para a função do usuário é passado e armazenado na lista no momento de 
		    sua criação.

		- Imprime
		 	Função que sabe como imprimir ume elemento da lista. Ela existe pelo mesmo motivo da destruir.

		- Compara
		    Idem funções anteriores. Comparar um inteiro, por exemplo, é simples. Pense no caso, por exemplo,
		  	em que os elementos armazenados na lista são conjuntos (matemáticos). Compará-los não é tão trivial
		  	e não é função do TAD Lista. Dessa forma, essa função de comparação deve ser implementada à parte 
		  	e fornecida ao TAD.
*******************************************************************************************************/

struct lista {
	void **elementos;
	int  tamanho;
	int  capacidade;
	void (*destruir)(void *);
	void (*imprime)(const void *);
	int  (*compara)(const void *, const void *);

};

#define INCREMENTO_TAMANHO 100

typedef struct lista lista_t;

int lista_realoca_vetor(lista_t *l);
int	lista_cheia(lista_t *l);

#endif