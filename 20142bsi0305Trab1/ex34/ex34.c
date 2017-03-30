#include <stdio.h>
#include "../bibliotecas/listaDupla.h"

int main(int argc, char **argv)
{
	lista *l;
	no *n;
	int i;
	l = criaLista();
	for(i = 0; i < 5; i++){
		n = criaNo(i);
		insereFim(l,n);
	}
	printf("\n*** lista 1***\n");
	imprimeListaProx(l);
	printf("\n*** lista invertida***\n");
	invertePonteiros(l);
	imprimeListaAntes(l);
	
	liberaListaAntes(l);
	
	
	return 0;
}

