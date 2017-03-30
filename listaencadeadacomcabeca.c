#include <stdio.h>

struct no{
	int conteudo;
	struct Node *prox;
}no; 


no *criaLista(int i){
	no *n
	n = malloc(sizeof(no));
	n->prox = NULL;
	n->conteudo = i
	return n;
}

int vazia(no *n)
{
	if(n->prox == NULL)
		return 1;
	else
		return 0;
}

void insereFim(no *n, no *novo)
{
	no *tmp;
	if(vazia(n))
		n->prox=novo;
	else{
		tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}

void insereInicio(no *n, no *novo)
{
	no *oldHead = n->prox;
	
	n->prox = novo;
	novo->prox = oldHead;
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
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void libera(no *LISTA)
{
	if(!vazia(LISTA)){
		no *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}


int main(int argc, char **argv)
{
	no *l;
	no *novo;
	int i;
	l = criaLista(4);
	for(i = 0; i < 5; i++){
		insereInicio(l,)
	}
	return 0;
}

