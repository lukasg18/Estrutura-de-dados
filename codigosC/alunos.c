/*
 * alunos.c
 * 
 * Copyright 2016 lucas <lucas@lucas-Inspiron-3421>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno{
	char *nome;
	int notas[4];
	int matricula;
}aluno;


void cria(aluno *n){
	char *nom;
	int i;
	for(i = 0; i < 2; i++){	
		printf("digite o nome: \n");
		n[i].nome = malloc(100 *sizeof(char));
		scanf("\n %[^\n]",nom);
		
		strcpy(n[i].nome, nom);
		for(int j = 0; j < 4; j++){
			n[i].notas[j] = j;
		}
		n[i].matricula = i;
	}
}

void imprime(aluno *n, int v){
	int cont = 0;
	for(int i = 0; i < v; i++){
		printf("nome:%s  matricula: %d \n", n[i].nome, n[i].matricula);
		for( ; cont < 4; cont++){
			printf("nota %d: %d \n",cont, n[i].notas[cont]);
		}
		cont = 0;
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	aluno *n;
	n = malloc(2 * sizeof(aluno));
	cria(n);
	printf("\n");
	imprime(n,2);
	return 0;
}

