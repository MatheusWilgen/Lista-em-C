all: aplicacao

aplicacao: lista_vetor_privado.o lista_vetor.o aplicacao.o
	gcc -o aplicacao aplicacao.o lista_vetor.o lista_vetor_privado.o

aplicacao.o:
	gcc -c aplicacao.c

lista_vetor.o:
	gcc -c lista_vetor.c

lista_vetor_privado.o:
	gcc -c lista_vetor_privado.c

clean:
	rm *.o aplicacao
