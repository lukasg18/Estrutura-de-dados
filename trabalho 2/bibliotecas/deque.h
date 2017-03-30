#ifndef __deque__h
#define __deque__h

typedef struct no{
	int conteudo;
	struct no *prox;
	struct no *antes;
}no;

typedef struct fila{
		int tam;
		no *ini , *fim;
}fila;

no *criaNo(int i);

fila *criaFila();

void insereFim(fila *l, no *n);

void insereIni(fila *l, no *n);

void removeIni(fila *l);

void imprimeDeque(fila *l);

void liberaDeque(fila *l);

void removeFim(fila *l);
	
#endif
