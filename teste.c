#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	int conteudo;
	struct no *prox;
}no;

typedef struct lista
	{
		int tam;
		no *ini , *fim;
	} lista;

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
	
void insereIni(lista *l, no *n){
		if (l -> tam != 0)
		{
			n -> prox = l -> ini;
		}
		else
			l -> fim = n;
			
		l -> ini = n;	
		l -> tam++;
	}

void insereFim(lista *l, no *n){
		if (l->tam !=0)
		{
			l -> fim -> prox = n;
		}
		else
			l->ini = n;

		l->fim = n;
		l -> fim -> prox = NULL;
		l->tam++;
	}

void insereEsq(lista *l, no *n,int t){
		int i;
		no *aux;
		if(t == 0)
		{
			insereIni(l,n);
			return;
		}
		if(t == l -> tam + 1)
		{
			insereFim(l,n);
			return;
		}
		for( i = 0 , aux = l -> ini; i < t-2; aux = aux -> prox , i++);
		n->prox = aux -> prox;
		aux->prox = n;
		l -> tam++;
	}

void ordenaLista(lista *l1, lista *l2){
	int cont, cont2, verifica;
	no *aux;
	no *aux2;
	no *pega;
	
	aux  = l1 -> ini;
	pega = criaNo(aux -> conteudo);
	insereFim(l2,pega);
	aux = aux -> prox;
	cont = 1;
	while(cont < l1 -> tam ){
		aux2 = l2 -> ini;
		cont2 = 0;
		verifica = 0;
		printf("aux: %d aux2: %d \n", aux->conteudo, aux2->conteudo);
		while(cont2 < l2 -> tam - 1){
			//~ printf("aux: %d aux2: %d \n", aux->conteudo, aux2->conteudo);
			if(aux->conteudo < aux2 -> conteudo){
				if(cont2 == 0){
					pega = criaNo(aux -> conteudo);
					insereIni(l2,pega);		
					verifica++;
					cont2 = l2 -> tam;
				}else{
					pega = criaNo(aux -> conteudo);
					insereEsq(l2,pega,cont2);
					verifica++;
					cont2 = l2 -> tam;
				}
			}
			cont2++;
			aux2 = aux2 -> prox;
		}
		if(verifica == 0){
			pega = criaNo(aux -> conteudo);
			insereFim(l2,pega);
		}
		cont++;
		aux = aux -> prox;
	}
}

void imprimeLista(lista *l){
		no *tmp = l->ini;
		int i;
		i = (l->tam - 1);
		while (i >-1)
		{
			printf("conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->prox;
			i--;
		}
	}


int main(int argc, char **argv)
{
	no *n;
	lista *l;
	lista *l2;
	int i;
	l = criaLista();
	l2 = criaLista();
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereIni(l,n);
		}
	
	imprimeLista(l);
	printf("\n \n ");
	ordenaLista(l,l2);
	imprimeLista(l2);
	
	return 0;
}

