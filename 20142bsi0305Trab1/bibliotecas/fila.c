#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

no *criaNo(int i){
	no *n;
	n = malloc(sizeof(no));
	n->conteudo = i; 
	n->prox = NULL;
	n->antes = NULL;
	return n;
}

fila *criaFila(){
		fila *l;
		l = malloc(sizeof(fila));
		l->tam = 0;
		l->ini = l->fim = NULL;
		return l;
	}
	
/* inserções são feitas apenas na retaguarda*/
void insereFim(fila *l, no *n){
		if (l->tam !=0)
		{
			n -> antes = l -> fim;
			l -> fim -> prox = n;
		}
		else
			l->ini = n;

		l->fim = n;
		l -> fim -> prox = NULL;
		l->tam++;
	}

/*onde eliminações só são permitidas na frente da fila*/
void removeDireita(fila *l){
		no *aux;
		aux = malloc(sizeof(no));
		aux = l -> ini;
		l -> ini = l-> ini -> prox;
		free(aux);
		l->tam --;
}
	
void imprimeLista(fila *l){
		no *tmp = l->ini;
		while (tmp != NULL)
		{
			printf("conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->prox;
		}
	}

void liberaLista(fila *l){
		int i = l->tam;
		no *tmp;
		while (i-- != 0)
		{
			tmp = l->ini->prox;
			free(l->ini);
			l->ini = tmp;
		}
		free(l);
	}
