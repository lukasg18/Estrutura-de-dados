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
	int i;
	l1 = criaLista();
	l2 = criaLista();
	l3 = criaLista();
	
	for(i = 1 ; i < 6 ; i++){
			n = criaNo(i);
			insereFim(l1,n);
		}
	imprimeLista(l1);
	
	imparPar(l1,l2,l3);
	printf("\n *** lista impar*** \n");
	imprimeLista(l2);
	printf("\n *** lista par*** \n");
	imprimeLista(l3);
	
	liberaLista(l3);
	liberaLista(l2);
	return 0;
}

