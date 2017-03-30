#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaDupla.h"

int main(int argc, char **argv)
{
	no *n;
	lista *l;
	lista *l2;
	lista *l3;
	int i;
	l = criaLista();
	l2 = criaLista();
	l3 = criaLista();
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	for(i = 5 ; i < 9 ; i++){
		n = criaNo(i);
		insereFim(l2,n);
	}
	printf("\n*** Lista 1 *** \n");
	imprimeListaProx(l);
	printf("\n*** Lista 2 *** \n");
	imprimeListaProx(l2);
	
	concatena(l,l2,l3);
	printf("\n*** Concatena ***\n");
	imprimeListaProx(l3);
	
	
	liberaLista(l);
	liberaLista(l2);
	liberaLista(l3);
	return 0;
}

