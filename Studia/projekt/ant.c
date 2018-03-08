#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "ant.h"
#include "matrix.h"
#include "exporttopng.h"
int main(int argc, char ** argv)
{
	int tmp;
	int r = argc > 1 ? atoi(argv[1]) : 10;
	int c = argc > 2 ? atoi(argv[2]) : 10;
	int amount_of_ants = argc > 3 ? atoi(argv[3]) : 3;
	int animation = 0;

	mat_t matrix = init(r, c);

	for(int i = 0; i < matrix->r; i++)
		for(int j = 0; j < matrix->c; j++)
			matrix->t[i][j] = 0;
	int n = 11000;//ilosc krokow do wykonania 

	srand(time(NULL));


	ants_t ants = ants_init(amount_of_ants);
	
	for(int i = 0; i < amount_of_ants; i++)
	{
		ants->ants[i]->x = rand()%r; 
		ants->ants[i]->y = rand()%c; 
		ants->ants[i]->pos = rand()%4 + 1; 
	}
	while(n-- >= 0)
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
			mirror(ants->ants[i], matrix->r, matrix->c);
		}

		
	}

	//animate(matrix);
	process_file(matrix);
	write_png_file("out.png");
	free_matrix(matrix);
	free_ants(ants);
}
