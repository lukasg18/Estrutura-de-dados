#ifndef __listaEstatica__h
#define __listaEstatica__h

typedef struct no{
	int conteudo;
}no;

typedef struct lista{
	no vet[10];  /*CAPACIDADE MAXIMA*/
	int fim;  /* NUMERO DE ELEMENTOS QUE ESTAO DENTRO DO VETOR*/
}lista;

void criaNo(no *n, int i);

void criaLista(lista *l);

void insereFim(lista *l, no n);

void inserePos(lista *l, no n, int pos);

void insereIni(lista *l, no n);

no *retornaPos(lista *l, int pos);

void imprimeLista(lista *l);

void imprimeListaInverso(lista *l);

int tamanhoLista(lista l);

void liberaLista(lista *l);

void removePos(lista *l, int pos);

no *buscaValor(lista *l, int x);

int buscaPos(lista *l, int x);

void trocaPos(lista *l, int pos1, int pos2);

void insereNCopias(lista *l,no n, int pos, int ncopia);

void removeNElem(lista *l, int pos, int qtd);

void ordenaListaDecre(lista *l);

void ordenaListaCres(lista *l);

int verificaOrdena(lista *l);

void copiaLista(lista *l2, lista *l1);

void copiaListaSemOcorrencia(lista *l2, lista *l1);

void inverteLista(lista *l,lista *aux);

void intercalaLista(lista *l1, lista *l2, lista *l3);

void insereNoRepetidos(lista *l1, lista*l2, lista*l4);

void retiraIniInsereFim(lista *l, int x);

#endif
