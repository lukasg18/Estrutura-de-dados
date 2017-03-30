#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaDuplaCircular.h"


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
	printf("\n **lista 1** \n");
	imprimeLista(l);
	printf("\n **lista 2** \n");
	imprimeLista(l2);
	
	printf("\n **lista intercalada** \n");
	intercala(l,l2,l3);
	imprimeLista(l3);
	printf("\n **lista copiada l3 para l1** \n");
	copiaLista(l,l3);
	imprimeLista(l);
	
	liberaLista(l);
	return 0;
}

