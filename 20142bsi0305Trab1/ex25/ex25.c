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
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereIni(l2,n);
		}	
	printf("\n ***inserindo no fim e imprimindo*** \n");
	imprimeLista(l);
	
	printf("\n ***inserindo no inicio e imprimindo*** \n");
	imprimeLista(l2);
	
	liberaLista(l);/* libernado as listas*/
	liberaLista(l2); /* libernado as listas*/
	return 0;
}

