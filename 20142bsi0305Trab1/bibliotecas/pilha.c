#include <stdio.h>
#include <stdlib.h>
#include <string.h>

no *criaNo(int i){
	no *n;
	n = malloc(sizeof(no));
	n->conteudo = i; 
	n->prox = NULL;
	return n;
}

pilha *criaPilha(){
		pilha *l;
		l = malloc(sizeof(pilha));
		l->tam = 0;
		l->ini = l->fim = NULL;
		return l;
	}
	
void insereIni(pilha *l, no *n){
		if (l -> tam != 0)
		{
			n -> prox = l -> ini;
		}
		else
			l -> fim = n;
			
		l -> ini = n;	
		l -> tam++;
	}
		
void removeIni(pilha *l){
		no *aux;
		aux = malloc(sizeof(no));
		aux = l -> ini;
		l -> ini = l-> ini -> prox;
		free(aux);
		l->tam --;
}
	
void imprimeLista(pilha *l){
		no *tmp = l->ini;
		while (tmp != NULL)
		{
			printf("conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->prox;
		}
	}

void liberaLista(pilha *l){
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
