/*
 * hello.c
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


void imprime(double mat[3][3]){
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("|%.1f|", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n **fim** \n \n");
}

void multMat(double mat[3][3], double mat2[3][3], double mat3[3][3]){
	int i,j,k;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			for(k = 0; k < 3; k++){
				mat3[i][j] += mat[k][j] * mat2[i][k];
			}
		}
	}
	/* *** imprimindo ****/
	imprime(mat);
	imprime(mat2);
	imprime(mat3);
}

int main(int argc, char **argv)
{
	double mat[3][3], mat2[3][3], mat3[3][3];
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			mat[i][j] = j;
			mat2[i][j] = j;
		}
	}
	multMat(mat,mat2,mat3);
	printf("oi");
	return 0;
}

