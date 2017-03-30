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
	achou = locate(l,2);
	achou = criaNo(34);
	insereP(l,achou,3);
	printf("\n achou : %d \n ", achou -> conteudo);
	printf("\n**lista insereP**\n");
	imprimeLista(l);
	achou = removeP(l,3);
	printf("\n**lista removeP**\n");
	imprimeLista(l);
	printf("\n Node removido: %d \n ", achou -> conteudo);
	liberaLista(l);
	
	return 0;
}

