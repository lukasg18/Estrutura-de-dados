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
	printf("\n Lista \n");
	imprimeLista(l);
	
	k = tamLista(l);
	printf("\n Tamanho da lista: %d \n", k);
	
	return 0;
}

