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
	printf("\n ** Lista Normal ** \n");
	imprimeLista(l);
	
	inverteLista(l,l2);
	printf("\n ** Lista invertida ** \n");
	imprimeLista(l2);
	
	liberaLista(l);
	liberaLista(l2);
	return 0;
}

