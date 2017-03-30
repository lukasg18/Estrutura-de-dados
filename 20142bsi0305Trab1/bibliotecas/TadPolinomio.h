#ifndef __TadPolinomio__h
#define __TadPolinomio__h


typedef struct no{
	float coef;
	int exp;
	struct no *prox;
}no;

typedef struct lista{
		int tam;
		no *ini , *fim;
	}lista;
	
no *criaNo(float i, int j);

lista *criaLista();

void insereFim(lista *l, no *n);

void imprimeLista(lista *l);

void liberaLista(lista *l);

void derivar(lista *l, lista *l2);

void somaPolinomio(lista *l1, lista *l2, lista *l3);

void multiplica(lista *l1, lista *l2, lista *l3);

#endif
