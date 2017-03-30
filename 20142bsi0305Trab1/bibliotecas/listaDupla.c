#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDupla.h"

no *criaNo(int i){
	no *n;
	n = malloc(sizeof(no));
	n->conteudo = i; 
	n->prox = NULL;
	n->antes = NULL;
	return n;
}

lista *criaLista(){
		lista *l;
		l = malloc(sizeof(lista));
		l->tam = 0;
		l->ini = l->fim = NULL;
		return l;
	}
	
void insereIni(lista *l, no *n){
		if (l -> tam != 0)
		{
			n -> prox = l -> ini;
			l -> ini -> antes = n;
		}
		else
			l -> fim = n;
			
		l -> ini = n;
		l -> tam++;
	}
	
void insereFim(lista *l, no *n){
		if (l->tam !=0)
		{
			n -> antes = l -> fim;
			l -> fim -> prox = n;
		}
		else
			l->ini = n;

		l->fim = n;
		l->fim -> prox = NULL;
		l->tam++;
	}
	
void inserePos(lista *l, no *n,int t){
		int i;
		no *aux;
		if(t == 1)
		{
			insereIni(l,n);
			return;
		}
		if(t == l -> tam + 1)
		{
			insereFim(l,n);
			return;
		}
		for( i = 0 , aux = l -> ini; i < t - 1; aux = aux -> prox , i++);
		n -> antes = aux -> antes;
		n -> prox = aux;
		aux -> antes -> prox = n;
		aux -> antes = n;
		l -> tam++;
	}
	
/* (a) função numero (L) – retorna o número de elementos da lista L. */		
int tamLista(lista *l){
	return l->tam;
}
	
void removeIni(lista *l){
		no *aux;
		aux = malloc(sizeof(no));
		aux = l -> ini;
		l -> ini = l-> ini -> prox;
		free(aux);
		l->tam --;
}

void removeFim(lista *l){
		no *aux;
		aux = l-> fim;
		l->fim = l->fim->antes;
		l -> fim -> prox = NULL;
		free(aux);
		l -> tam--;
}
	
void removePos(lista *l,int t){
	int i;
	no *aux;
	for(i = 0,aux = l -> ini; i < t-1 ; aux = aux -> prox,i++);
	aux -> prox -> antes = aux -> antes;
	aux -> antes -> prox = aux -> prox;
	free(aux);
	l -> tam --;
	
	}	
	
int busca(lista *l,int i)
	{
		int cont = 0;
		int x = 0;
		no *aux;
		aux = l->ini;
		while(x < (l -> tam)){
			if(aux -> conteudo == i){
				cont++;
			}
			x++;
			aux = aux -> prox;
	}
	return cont;
}

/*concatenar duas listas circulares*/
void concatena(lista *l1, lista *l2, lista *l3){
	no *aux;
	no *aux2;
	int i,j;
	aux = l1->ini;
	i = j = 0;
	while(i < (l1 -> tam)){
		aux2 = criaNo(aux->conteudo);
		insereFim(l3,aux2);
		aux = aux -> prox;
		i++;
	}
	aux = l2->ini;
	while(j < (l2 -> tam)){
		aux2 = criaNo(aux -> conteudo);
		insereFim(l3,aux2);
		aux = aux -> prox;
		j++;
	}
	
}

/* intercalar duas listas ordenadas*/
void intercala(lista *l1, lista*l2, lista *l3){
	no *aux;
	no *aux2;
	no *pega;
	int i,j;
	aux = l1 -> ini;
	aux2 = l2 -> ini;
	i = j = 0;
	while(i < (l1 -> tam) || j < (l2 -> tam)){
		if(i < (l1 -> tam)){
			if(j < (l2 -> tam)){
				if((aux -> conteudo) < (aux2 -> conteudo)){
					pega = criaNo(aux -> conteudo);
					insereFim(l3,pega);
					aux = aux -> prox;
					i++;
				}else{
					pega = criaNo(aux2 -> conteudo);
					insereFim(l3,pega);
					aux2 = aux2 -> prox;
					j++;
				}		
			}else{
				pega = criaNo(aux->conteudo);
				insereFim(l3,pega);
				aux = aux -> prox;
				i++;
			}
		}else{
			pega = criaNo(aux2->conteudo);
			insereFim(l3,pega);
			aux2 = aux2 -> prox;
			j++;
		}
	}
}

void liberaLista(lista *l){
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

void liberaListaAntes(lista *l){
		int i = l->tam;
		no *tmp;
		while (i-- != 0)
		{
			tmp = l->ini->antes;
			free(l->ini);
			l->ini = tmp;
		}
		free(l);
	}

/* fazer uma cópia da lista*/
void copiaLista(lista *l1, lista *l2){
	no *aux;
	no *pega;
	int i;
	liberaLista(l1);
	l1 = criaLista();
	aux = l2 -> ini;
	i = 0;
	while(i < (l2 -> tam)){
		pega = criaNo(aux -> conteudo);
		insereFim(l1,pega);
		aux = aux -> prox;
		i++;
	}
}

void imprimeListaAntes(lista *l){
		no *tmp = l->ini;
		while (tmp != NULL)
		{
			printf("conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->antes;
		}
	}

void imprimeListaProx(lista *l){
		no *tmp = l->ini;
		while (tmp != NULL)
		{
			printf("conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->prox;
		}
	}
	
void invertePonteiros(lista *l){
	no *tmp;
	tmp = l->ini;
	l->ini = l->fim;
	l->fim = tmp;
	
}
