#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/pilha.h"

int verificaInverso(pilha *x, pilha *y){
	no *aux;
	no *pega;
	pilha *z;
	int cont = 0;
	int i;
	
	z = criaPilha();
	aux = y -> ini;
	i=0;
	while(i < (y -> tam)){
		pega = criaNo(aux -> conteudo);
		empilha(z,pega); /*pilha auxiliar para verificar se esta certo*/
		aux = aux -> prox;
		i++;
	}
	aux = x->ini;
	pega = z->ini;
	i = 0;
	while(i < (z -> tam)){
		if(aux -> conteudo == pega -> conteudo){
			cont++;
		}
		pega = pega -> prox;
		aux = aux -> prox;
		i++;
	}
	if(cont == (x->tam )){
		cont = 1; /* TRUE */
	}else{
		cont = 0; /*FALSE */
	}
	return cont;
}

int main(int argc, char **argv)
{
	int k;
	pilha *l;
	pilha *l2;
	no *n;
	l = criaPilha();
	l2 = criaPilha();
	n = criaNo('A');
	empilha(l,n);
	n = criaNo('B');
	empilha(l,n);
	n = criaNo('A');
	empilha(l,n);
	n = criaNo('A');
	empilha(l2,n);
	n = criaNo('B');
	empilha(l2,n);
	n = criaNo('A');
	empilha(l2,n);
	imprimeChar(l);
	imprimeChar(l2);
	k = verificaInverso(l,l2);
	printf("\n 1 - SIM \n 0 - NAO \n");
	printf("resposta : %d \n", k);
	//~ liberaLista(l);
	
	return 0;
}
