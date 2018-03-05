#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ant.h"
#include "matrix.h"

int main(int argc, char ** argv)
{
	int tmp;
	int r = argc > 1 ? atoi(argv[1]) : 10;
	int c = argc > 2 ? atoi(argv[2]) : 10;

	int animation = 0;

	mat_t matrix = init(r, c);

	for(int i = 0; i < matrix->r; i++)
		for(int j = 0; j < matrix->c; j++)
			matrix->t[i][j] = 0;
	int n = 386;//ilosc krokow do wykonania 




	ants_t ants = ants_init(1);

	ants->ants[0]->x = 14; 
	ants->ants[0]->y = 15; 
	ants->ants[0]->pos = 4; 
	/*ants->ants[1]->x = 15; 
	ants->ants[1]->y = 20; 
	ants->ants[1]->pos = 2; 
	ants->ants[2]->x = 31; 
	ants->ants[2]->y = 35; 
	ants->ants[2]->pos = 1; 
	
	ants->ants[1]->brk = ants->ants[1]->brk = ants->ants[2]->brk = 0;
	*/while(n-- >= 0)
	{
		if(animation == 1) //jesli taka opcja zostala wybrana - animacja mrowki jest wypisywana na konsole
			animate(matrix);

		for(int i = 0; i < ants->n; i++)
		{
			if (matrix->t[ants->ants[i]->x][ants->ants[i]->y] > 0)
			{
				matrix->t[ants->ants[i]->x][ants->ants[i]->y] = 0;
				tmp = 1;
			}
			else
			{
				matrix->t[ants->ants[i]->x][ants->ants[i]->y] = i + 1;
				tmp = 0;
			}
			move(ants->ants[i], tmp);
			mirror(ants->ants[i], matrix->c, matrix->r);
		}

		
	}

	animate(matrix);
	free_matrix(matrix);
	free_ants(ants);
}
