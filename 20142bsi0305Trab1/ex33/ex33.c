#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaEncadeadaCircular.h"


int main(int argc, char **argv)
{
	no *n;
	lista *l;
	lista *l2;
	int i;
	l = criaLista();
	
	for(i = 0 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim2(l,n);
		}
	printf("\n**Lista Normal**\n");
	imprimeLista(l);
	n = criaNo(2);
	l2 = quebraLista(l,n);
	printf("\n**Lista quebrada**\n");
	imprimeLista(l2);
	printf("\n**Lista quebrada**\n");
	imprimeLista(l);
	liberaLista(l);
	return 0;
}
