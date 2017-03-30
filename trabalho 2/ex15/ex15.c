#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/pilha.h"

int main(int argc, char **argv)
{
	int verifica;
	pilha *l;
	no *n;
	l = criaPilha();
	
	n = criaNo(')');
	empilha(l,n);
	n = criaNo('A');
	empilha(l,n);
	n = criaNo('+');
	empilha(l,n);
	n = criaNo('B');
	empilha(l,n);
	n = criaNo('(');
	empilha(l,n);
	
	printf("\n**lista normal**\n");
	imprimeChar(l);
	//~ desempilha(l);
	//~ printf("\n**lista normal**\n");
	//~ imprimePilha(l);
	verifica = verificaExpressao(l);
	printf("\n 0 - nao eh expressao matematica\n 1 - sim, eh expressao matematica \n");
	printf("\n %d \n", verifica);
	
	
	//~ liberaLista(l);
	
	return 0;
}

