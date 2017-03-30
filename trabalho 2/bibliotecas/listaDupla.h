#ifndef __listaDupla__h
#define __listaDupla__h


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

void insereIni(lista *l, no *n);

void insereFim(lista *l, no *n);

void inserePos(lista *l, no *n,int t);

int tamLista(lista *l);

void removeIni(lista *l);

void removeFim(lista *l);

void removePos(lista *l,int t);

int busca(lista *l,int i);

void concatena(lista *l1, lista *l2, lista *l3);

void intercala(lista *l1, lista*l2, lista *l3);

void imprimeLista(lista *l);
	
void liberaLista(lista *l);

void copiaLista(lista *l1, lista *l2);

no *locate(lista *l,int pos);

void insereP(lista *l, no *n,int t);

no *removeP(lista *l,int t);

no *BuscaDupOrd(lista *l,no *n);

#endif
