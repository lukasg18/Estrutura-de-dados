#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

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
	
void empilha(pilha *l, no *n){
		if (l -> tam != 0)
		{
			n -> prox = l -> ini;
		}
		else
			l -> fim = n;
			
		l -> ini = n;	
		l -> tam++;
	}
		
void desempilha(pilha *l){
		no *aux;
		aux = malloc(sizeof(no));
		aux = l -> ini;
		l -> ini = l-> ini -> prox;
		free(aux);
		l->tam --;
}
	
void imprimePilha(pilha *l){
		no *tmp = l->ini;
		while (tmp != NULL)
		{
			printf("conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->prox;
		}
	}

void imprimeChar(pilha *l){
		no *tmp = l->ini;
		int i;
		i = (l->tam - 1);
		while (i >-1)
		{
			printf(" %c  ", tmp -> conteudo);
			tmp = tmp->prox;
			i--;
		}
		printf("\n\n");
	}

void liberaPilha(pilha *l){
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

int verificaExpressao(pilha *p){
	no *n;
	int i;
	int contap1, contap2, verifica;
	contap1 = contap2  = verifica = 0;
	n = p -> ini;
	i = 0;
	while(i < (p -> tam - 1)){
		if((i == 0) && (n -> conteudo == ')')){
			verifica = 0;
		}
		if((n -> conteudo == '(')){
			contap1++;
		}
		if((n -> conteudo == ')')){
			contap2++;
		}
		n = n -> prox;
		i++;
	}
	if(n -> conteudo == '('){
		verifica = 0; /*false*/
	}
	if(n -> conteudo == ')'){
		contap2++;
	}
	if(contap1 == contap2){
		verifica = 1; /* true*/
	}
	return verifica;
}
