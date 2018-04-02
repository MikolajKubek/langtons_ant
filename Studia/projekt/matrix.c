#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "matrix.h"

mat_t init(int r, int c) //chyba wiersze, kolumny
{
	mat_t matrix = malloc(sizeof(matrix));

	matrix->t = malloc(r*sizeof(matrix->t));

	matrix->r = r;
	matrix->c = c;

	for(int i = 0; i < r; i++)
		matrix->t[i] = malloc(c*sizeof(matrix->t[i]));
	return matrix;
}

void animate(mat_t matrix)
{
	printf("\033[H\033[J");
	for(int i = 0; i < matrix->r; i++)
	{
		for(int j = 0; j < matrix->c; j++)
		{			
			if(matrix->t[i][j] != 0)
				printf("\x1B[%dm  x", 90 + matrix->t[i][j]);
			
			else 
				printf("\x1B[90m  0");							
		}
		printf("\n");
	}

	usleep(10000);
}

void free_matrix(mat_t matrix)
{
	for(int i = 0; i < matrix->r; i++)
		free(matrix->t[i]);

	free(matrix->t);

	free(matrix);
}
