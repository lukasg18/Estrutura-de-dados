#ifndef __listaEncadeada__h
#define __listaEncadeada__h


typedef struct no{
	int conteudo;
	struct no *prox;
}no;

typedef struct lista{
		int tam;
		no *ini , *fim;
	}lista;
	
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

void troca(lista *l, no *n,int t);

void insereEsq(lista *l, no *n,int t);

void insereDir(lista *l, no *n,int t);

void inverteLista(lista *l, lista *l2);

void imprimeListaR(no *n);

void imprimeChar(lista *l);
	
void imparPar(lista *l1, lista*impar, lista *par);

void ordenaListaCrescente(lista *l1, lista *l2);

void ordenaListaDescrescente(lista *l1, lista *l2);

int achaKEsimo(lista *l, int k);

int pertence(lista *l1, lista *l2);

void intersecao(lista *l1, lista *l2, lista *l3);

void uniao(lista *l1, lista *l2, lista *l3);

int removerVetor(int k, int n, int *v);

int inserirVetor(int k, int x, int n, int v[]);

void trocaPalavra(lista *l);

#endif
