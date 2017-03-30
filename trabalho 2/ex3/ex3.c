#include <stdio.h>
#include "../bibliotecas/listaEstatica.h"

int main(){
	int i;
    lista l;
    no n;
    criaLista(&l);
    for(i = 0; i < 10; i++){
		criaNo(&n,i);
		insereFim(&l,n);
	}
	criaNo(&n,5);
	insereNCopias(&l,n,2,4);
	printf("\n**INSERE NCOPIAS\n");
	imprimeLista(&l);
	
	liberaLista(&l);
	
    return 0;
}

