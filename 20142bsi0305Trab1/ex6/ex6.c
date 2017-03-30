#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	no *n;
	lista *l;
	lista *l2;
	int i;
	l = criaLista();
	l2 = criaLista();
	
	for(i = 6 ; i < 10 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	printf("\n ***imprimindo recursivamente*** \n");
	imprimeListaR(l->ini);
	
	liberaLista(l);
	liberaLista(l2);
	return 0;
}

