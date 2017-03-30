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

void empilha(pilha *l, no *n);

void desempilha(pilha *l);

void imprimePilha(pilha *l);

void liberaPilha(pilha *l);

void imprimeChar(pilha *l);

int verificaExpressao(pilha *p);

#endif
