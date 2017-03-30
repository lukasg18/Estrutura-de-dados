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
	removeNElem(&l,2,4);
	printf("\n**Remove N Elementos**\n");
	imprimeLista(&l);
	
	liberaLista(&l);
	
    return 0;
}

