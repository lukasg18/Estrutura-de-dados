#ifndef __listaEncadeadaCircular__
#define __listaEncadeadaCircular__

typedef struct no{
	int conteudo;
	struct no *prox;
	struct no *antes;
}no;

typedef struct lista
	{
		int tam;
		no *ini , *fim;
	} lista;
	

no *criaNo(int i);

lista *criaLista();

int tamLista(lista *l);

void insereEsq(lista *l, no *n);

void removePos(lista *l,int t);

void insereFim(lista *l, no *n);

void concatena(lista *l1, lista *l2, lista *l3);

void removeFim(lista *l);

void intercala(lista *l1, lista*l2, lista *l3);

void imprimeLista(lista *l);

void liberaLista(lista *l);

void copiaLista(lista *l1, lista *l2);

#endif
