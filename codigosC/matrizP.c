#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef double KIND;


KIND** createMatrix(int l, int c)
{
	KIND **matrix;
	int j;
	matrix = malloc( l * sizeof(KIND*) );
	for(j=0;j<l;j++)
		matrix[j] = malloc( c * sizeof(KIND) );
	return matrix;
}

void fillMatrix(KIND** matrix, int l, int c)
{
	int i,j;
	for(i=0;i<l;i++)
		for(j=0;j<c;j++){
			matrix[i][j] = 0 + ( rand() % 100 );
		}
}


void freeMatrix(KIND** matrix, int l, int c)
{
	int i;
	for(i=0;i<l;i++)
		free(matrix[i]);
	free(matrix);
}

void imprime(KIND **matrix, int l, int c){
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("| %.1f |",matrix[i][j]);
		}
		printf("\n");
	}
}


int main(int argc, char **argv)
{
	KIND **mat;
	
	mat=createMatrix(2,2);
	fillMatrix(mat,2,2);
	imprime(mat,2,2);
	
	return 0;
}

