#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaEncadeada.h"


int main(int argc, char **argv)
{
	no *n;
	lista *l;
	int i,k;
	l = criaLista();
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	imprimeLista(l);
	
	printf("\n **troca** \n");
	n = criaNo(27);
	troca(l,n,4);
	imprimeLista(l);
	
	printf("\n **INSERE esquerda** \n");
	n = criaNo(12);
	insereEsq(l,n,5);
	imprimeLista(l);
	
	printf("\n **REMOVE POS** \n");
	removePos(l,2);
	imprimeLista(l);
	
	
	printf("\n");
	k = tamLista(l);
	printf("TAM LISTA: %d \n", k);
	
	printf("\n BUSCA:\n 0 - nao achou \n 1 - achou \n");
	k = busca(l,1);
	printf("resultado da busca: %d \n", k);
	liberaLista(l);
	return 0;
}
