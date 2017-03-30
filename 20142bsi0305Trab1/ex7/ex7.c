#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	no *n;
	lista *l;
	lista *l2;
	//~ int i;
	l = criaLista();
	l2 = criaLista();
	
	//~ for(i = 1 ; i < 5 ; i++){
			//~ n = criaNo(i);
			//~ insereFim(l,n);
		//~ }
	printf("\n *** Lista  *** \n");
	n = criaNo(5);
	insereFim(l,n);
	n = criaNo(4);
	insereFim(l,n);
	n = criaNo(7);
	insereFim(l,n);
	n = criaNo(12);
	insereFim(l,n);
	n = criaNo(1);
	insereFim(l,n);
	imprimeLista(l);
	printf("\n *** ORDENA *** \n");
	ordenaListaCrescente(l,l2);
	imprimeLista(l2);
	
	return 0;
}

