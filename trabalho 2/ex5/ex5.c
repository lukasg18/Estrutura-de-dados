#include <stdio.h>
#include "../bibliotecas/listaEstatica.h"

int main(){
	int i;
    lista l,l2,l3,l4;
    no n;
    criaLista(&l);
    criaLista(&l2);
    criaLista(&l3);
    criaLista(&l4);
    for(i = 0; i < 5; i++){
		criaNo(&n,i);
		insereFim(&l,n);
	}
	 for(i = 0; i < 5; i++){
		criaNo(&n,i);
		insereFim(&l2,n);
	}
	criaNo(&n,4);
	insereFim(&l,n);
	ordenaListaCres(&l);
	i = verificaOrdena(&l);
	printf("\n verifica ordena: %d \n", i);
	printf("\n**Lista1 Ordenada**\n");
	imprimeLista(&l);
	copiaListaSemOcorrencia(&l2,&l);
	printf("\n**Lista2 copiada de lista1 sem ocorrencia**\n");
	imprimeLista(&l2);
	//~ inverteLista(&l,&l2);
	//~ printf("\n**Lista 1 Invertida**\n");
	//~ imprimeLista(&l);
	printf("\n**Intercala**\n");
	intercalaLista(&l,&l2,&l3);
	imprimeLista(&l3);
	printf("\n**insere valores repetidos em lista4**\n");
	insereNoRepetidos(&l,&l2,&l4);
	imprimeLista(&l4);
	//~ liberaLista(&l);
	
    return 0;
}

