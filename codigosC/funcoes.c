/*
 * funcoes.c
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
#include <stdlib.h>

int meustrlen(char *nome){
	int i;
	for(i = 0; nome[i] != 0; i++);
	return i;
}

void meustrcpy(char *nome, char *nome2){
	int i;
	for(i = 0; nome2[i] != 0; i++){
		nome[i] = nome2[i];
	}
	printf("%s",nome);
}

int meuatoi(char *valor){
	int i;
	int resultado;
	int mult;
	resultado = 0;
	mult = 1;
	for(i = (meustrlen(valor) - 1); i >= 0; i--){
		if((valor[i] >= 48) && (valor[i] <= 57)){
			resultado = resultado + ((valor[i] - 48) * mult);
			mult = mult * 10;
		}	
	}
	return resultado;
}

void maiusculo(char *nome){
	int i;
	char aux;
	for(i = 0; nome[i]!= 0; i++){
		aux = nome[i] + 'A' - 'a';
	}
	printf("%c", aux);
}

void minusculo(char *nome){
	int i;
	char aux;
	for(i = 0; nome[i]!= 0; i++){
		aux = nome[i] + 'a' - 'A';
	}
	printf("%c", aux);
}

int main(int argc, char **argv)
{
	//~ int k;
	//~ char nome[12];
	//~ char cara;
	//~ k = meustrlen("123");
	//~ k = meuatoi("123");
	//~ meustrcpy(nome,"lucas");
	maiusculo("b");
	printf("\n");
	minusculo("B");
	//~ printf("%d", k);
	return 0;
}

