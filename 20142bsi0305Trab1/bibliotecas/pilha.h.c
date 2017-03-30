#ifndef __pilha__h
#define __pilha__h

typedef struct no{
	int conteudo;
	struct no *prox;
}no;

typedef struct pilha{
		int tam;
		no *ini , *fim;
}pilha;
	
no *criaNo(int i);

pilha *criaPilha();

void insereIni(pilha *l, no *n);

void removeIni(pilha *l);

void imprimeLista(pilha *l);

void liberaLista(pilha *l);

#endif
