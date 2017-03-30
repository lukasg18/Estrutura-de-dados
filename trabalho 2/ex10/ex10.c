#include <stdio.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	lista *l;
	no *n;
	
	l = criaLista();
	n = criaNo('a');
	insereFim(l,n);
	n = criaNo('e');
	insereFim(l,n);
	n = criaNo('i');
	insereFim(l,n);
	n = criaNo('o');
	insereFim(l,n);
	n = criaNo('u');
	insereFim(l,n);
	printf("\n**lista normal**\n");
	imprimeChar(l);
	inverteLista2(l);
	printf("\n**lista invertida**\n");
	imprimeChar(l);
	//~ liberaLista(l);
	
	return 0;
}

