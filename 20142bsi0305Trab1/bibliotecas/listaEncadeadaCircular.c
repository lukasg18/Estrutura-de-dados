#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEncadeadaCircular.h"

no *criaNo(int i){
	no *n;
	n = malloc(sizeof(no));
	n->conteudo = i; 
	n->prox = NULL;
	return n;
}

lista *criaLista(){
		lista *l;
		l = malloc(sizeof(lista));
		l->tam = 0;
		l->ini = l->fim = NULL;
		return l;
	}

/* contar o número de elementos numa lista circular */		
int tamLista(lista *l){
	return l->tam;
}

/* inserir um elemento à esquerda da cabeça da lista */
void insereEsq(lista *l, no *n){
		if (l -> tam != 0)
		{
			n -> prox = l -> ini; 
		}
		else
			l -> fim = n;
			
		l -> ini = n;	
		l -> tam++;
	}
	
/*eliminar o elemento de valor x */
void removePos(lista *l,int t){
	int i;
	no *aux;
	no *lixo;
	for(i = 0,aux = l -> ini; i < t-1 ; aux = aux -> prox,i++);
	lixo = aux->prox;
	aux -> prox  = lixo -> prox;
	aux = aux -> prox;
	free(lixo);
	l -> tam --;
	}
	
/* funçao de insercao no final*/
void insereFim(lista *l, no *n){
		if (l->tam !=0)
		{
			l -> fim -> prox = n;
		}
		else
			l->ini = n;

		l->fim = n;
		l -> fim -> prox = l-> ini; 
		l->tam++;
	}

void insereFim2(lista *l, no *n){
		if (l->tam !=0)
		{
			l -> fim -> prox = n;
		}
		else
			l->ini = n;

		l->fim = n;
		l->tam++;
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

/* funçao de remocao do fim*/
void removeFim(lista *l){
		no *aux;
		no *pega;
		int i;
		for(i = 0, aux = l->ini; i < (l -> tam - 2); aux = aux -> prox, i++);
		pega = aux -> prox;
		l->fim = aux;
		l -> fim -> prox = l->ini;
		free(pega);
		l -> tam--;
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

void imprimeLista(lista *l){
		no *tmp = l->ini;
		int i;
		i = (l->tam - 1);
		while (i >-1)
		{
			printf(" conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->prox;
			i--;
		}
	}
	
void liberaLista(lista *l){
		int i = 0;
		no *tmp;
		while (i < (l -> tam))
		{
			tmp = l->ini->prox;
			free(l->ini);
			l->ini = tmp;
			i++;
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

lista *quebraLista(lista *l, no *n){
	int i;
	lista *l2;
	no *aux;
	no *aux2;
	l2 = criaLista();
	i = 0;
	aux = aux2 = l->ini;
	while(i < (l->tam)){
		if(n->conteudo == aux->conteudo){
			aux2 = aux->prox;
			l -> fim = aux;
			l->fim -> prox = l->ini;
			i = (l->tam); /* achou ja posso sair */
		}
		aux = aux -> prox;
		i++;
	}
	while(aux2 != NULL){
		insereFim2(l2,aux2);
		aux2 = aux2 -> prox;
	}
	l2 -> fim -> prox = l2 -> ini;
	l -> tam =  (l -> tam - l2 -> tam);
	return l2;
}
