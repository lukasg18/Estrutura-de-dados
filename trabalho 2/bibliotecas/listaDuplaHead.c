#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDuplaHead.h"

no *inicia()
{
	no *LISTA = (no *) malloc(sizeof(no));
	LISTA->prox = NULL;
	LISTA->antes = NULL;
	return LISTA;
}

int vazia(no *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

void insereInicio(no *LISTA, int i)
{
	no *ini;
	no *novo;
	novo=(no *) malloc(sizeof(no));
	novo -> num = i;
	
	ini = LISTA->prox;
	LISTA->prox = novo;
	novo->prox = ini;
}

void exibe(no *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	no *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL){
		printf("conteudo: %d \n", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void libera(no *LISTA)
{
	if(!vazia(LISTA)){
		no *proxno,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxno = atual->prox;
			free(atual);
			atual = proxno;
		}
	}
}
