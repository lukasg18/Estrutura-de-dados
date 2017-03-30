#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/listaDupla.h"

int main(int argc, char **argv)
{
	int i;
	lista *l;
	no *n;
	no *achou;
	l = criaLista();
	
	for(i = 0; i < 5; i++){
		n = criaNo(i);
		insereFim(l,n);
	}
	printf("\n**lista normal**\n");
	imprimeLista(l);
	n = criaNo(2);
	achou = BuscaDupOrd(l,n);
	printf("\n achou : %d \n ", achou -> conteudo);
	imprimeLista(l);
	liberaLista(l);
	
	return 0;
}

