#ifndef __fila__h
#define __fila__h

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

void removeDireita(fila *l);

void imprimeLista(fila *l);

void liberaLista(fila *l);
	
#endif
