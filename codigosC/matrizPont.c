#include <stdio.h>

typedef struct matriz{
	int *lin;
	int *col;
	int valor;
}matriz;

matriz criaMat(int lin, int col){
	matriz *mat;
	mat->lin = malloc(sizeof(int) * lin);
	mat->col = malloc(sizeof(int)* col);
	
}


int main(int argc, char **argv)
{
	
	return 0;
}

