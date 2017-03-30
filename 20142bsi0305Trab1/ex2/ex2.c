#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	no *n;
	lista *l1;
	lista *l2;
	lista *l3;
	lista *l4;
	int i;
	l1 = criaLista();
	l2 = criaLista();
	l3 = criaLista();
	l4 = criaLista();
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l1,n);
		}
	
	for(i = 5 ; i < 9 ; i++){
			n = criaNo(i);
			insereFim(l2,n);
		}
	printf(" \n ** lista 1 *** \n");
	imprimeLista(l1);
	printf("\n");
	printf("\n ** lista 2 *** \n");
	imprimeLista(l2);
	concatena(l1,l2,l3);
	printf("\n \n");
	printf("\n ** lista concatenada *** \n");
	imprimeLista(l3);
	
	printf("\n \n");
	printf("\n ** lista intercalada *** \n");
	intercala(l1,l2,l4);
	imprimeLista(l4);
	liberaLista(l1);
	liberaLista(l2);
	liberaLista(l3);
	liberaLista(l4);
	return 0;
}

