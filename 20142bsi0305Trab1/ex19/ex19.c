#include <stdio.h>
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
	printf("\n **lista ** \n");
	imprimeLista(l);
	printf("\n **remove Direita ou inicio** \n");
	removeDireita(l);
	imprimeLista(l);
	printf("\n \n");
	
	liberaLista(l);
	return 0;
}

