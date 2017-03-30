#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/fila.h"

int main(int argc, char **argv)
{
	no *n;
	fila *l;
	int i;
	l = criaFila();
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	printf("\n *** Inserindo Fim *** \n");
	imprimeLista(l);
	
	printf("\n **Remove direita** \n");
	removeDireita(l);
	imprimeLista(l);
	
	liberaLista(l);
	return 0;
}

