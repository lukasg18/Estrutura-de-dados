#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TadPolinomio.h"

no *criaNo(float i, int j){
	no *n;
	n = malloc(sizeof(no));
	n->coef = i; 
	n->exp = j;
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
	
void insereFim(lista *l, no *n){
		if (l->tam !=0)
		{
			l -> fim -> prox = n;
		}
		else
			l->ini = n;

		l->fim = n;
		l->tam++;
	}

void imprimeLista(lista *l){
		no *tmp = l->ini;
		int i;
		i = (l->tam - 1);
		while (i >-1)
		{
			printf("%.1fX^%d ", tmp -> coef, tmp -> exp);
			tmp = tmp->prox;
			i--;
		}
		printf("\n \n ");
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

void somaPolinomio(lista *l1, lista *l2, lista *l3){
	int cont, cont2,verifica;
	float soma;
	no *aux;
	no *aux2;
	no *pega;
	
	if(l1 -> tam > l2 -> tam){
		aux  = l1 -> ini;
		cont = 0;
		soma = 0.0;
		while(cont < l1 -> tam){
			aux2 = l2 -> ini;
			cont2 = 0;
			verifica = 0;
			while(cont2 < l2 -> tam ){
				if(aux -> coef != 0 && aux2 -> coef != 0){
					if(aux->exp == aux2 -> exp){
						soma = (aux -> coef + aux2 -> coef);
						pega = criaNo(soma,(aux -> exp));
						insereFim(l3,pega);
						verifica++;
					}
				}
				cont2++;
				aux2 = aux2 -> prox;
			}
			if(verifica == 0 && aux -> coef != 0){
				pega = criaNo((aux -> coef),(aux -> exp));
				insereFim(l3,pega);
			}
			cont++;
			aux = aux -> prox;
		}
	}else{
		aux  = l2 -> ini;
		cont = 0;
		soma = 0.0;
		while(cont < l2 -> tam){
			aux2 = l1 -> ini;
			cont2 = 0;
			verifica = 0;
			while(cont2 < l1 -> tam ){
				if(aux -> coef != 0 && aux2 -> coef != 0){
					if(aux->exp == aux2 -> exp){
						soma = (aux -> coef + aux2 -> coef);
						pega = criaNo(soma,(aux -> exp));
						insereFim(l3,pega);
						verifica++;
					}
				}
				cont2++;
				aux2 = aux2 -> prox;
			}
			if(verifica == 0 && aux -> coef != 0){
				pega = criaNo((aux -> coef),(aux -> exp));
				insereFim(l3,pega);
			}
			cont++;
			aux = aux -> prox;
		}
	}
}

void derivar(lista *l, lista *l2){
	int cont,diminuiExp;
	float multiplicaCoef;
	no *aux;
	no *pega;
	cont = 0;
	aux = l -> ini;
	while(cont < (l -> tam)){
		multiplicaCoef = diminuiExp = 0;
		if(aux -> exp != 0){
			multiplicaCoef = (aux -> coef) * (aux -> exp);
			diminuiExp = (aux -> exp) - 1;
			pega = criaNo(multiplicaCoef, diminuiExp);
			insereFim(l2,pega);
		}
		cont++;
		aux = aux -> prox;
	}
}

void multiplica(lista *l1, lista *l2, lista *l3){
	int cont, cont2, soma;
	float mult;
	no *aux;
	no *aux2;
	no *pega;
	
	aux  = l1 -> ini;
	cont = soma = 0;
	mult = 0.0;
	while(cont < l1 -> tam ){
		aux2 = l2 -> ini;
		cont2 = 0;
		while(cont2 < l2 -> tam ){
			if(aux -> coef != 0 && aux2 -> coef != 0){
				mult = (aux -> coef * aux2 -> coef);
				soma = (aux -> exp + aux2 -> exp);
				pega = criaNo(mult,soma);
				insereFim(l3,pega);
			}
			cont2++;
			aux2 = aux2 -> prox;
		}
		cont++;
		aux = aux -> prox;
	}
}
