#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int *vet1;
	int vet2[10];
	int i;
	vet1 = (int*)malloc(10 * sizeof(int));
	for(i = 0; i < 10; i++){
		vet1[i] = i;
		vet2[i] = i;
	}
	for(i = 0; i < 10; i++){
		printf(" estatico: %d | dinamico: %d \n", vet2[i], vet1[i]);
	}
	return 0;
}
/*                          ***RESPOSTA***                                                  */
/*Estatico: sobre as vantagens do estatico seria a questao de ele alocar automaticamente e tambem
 desalocar memoria automaticamente pra o programador. A desvantagem seria o limite do tamanho, por ele ser estatico 
 o programador fica limitado a usar um tamanho definido.

 Dinamico: sobre as vantagens do vetor dinamico seria a questao do tamanho do mesmo, como ele é dinamico
 o programador tem a liberdade definir um tamanho de inicio e se precisar de mais tamanho ele pode aumentar sem perder
 os dados ja inseridos. A desvantagem seria na velocidade, como vc nao aloca memoria sequencial fica um pouco mais demorado.

 Diferença: A diferença basica entre um vetor estatico para um dinamico, é que no vetor dinamico é necessario dar um free para
 liberar espaço na memoria, ja no estatico o "free" é automatico.*/
