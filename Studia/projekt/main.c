#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <getopt.h>

#include "ant.h"
#include "matrix.h"
#include "exporttopng.h"
int main(int argc, char ** argv)
{
	int opt;
	int tmp;
	int c = 10;
	int r = 10;
	int amount_of_ants = 3;
	int animation = 0;
	int n = 11000;
	char* outf = "out.png";
	char* inpf = NULL;
	while((opt = getopt(argc, argv, "w:h:q:n:a:o:i:")) != -1)
	{
		switch(opt)
		{
			case 'w':/*szerokosc*/
				c = atoi(optarg);
			break;
			
			case 'h':/*wysokosc*/
				r = atoi(optarg);
			break;

			case 'q':/*ilosc mrowek*/
				amount_of_ants = atoi(optarg);
			break;
			
			case 'n':/*ilosc krokow*/
				n = atoi(optarg);
			break;

			case 'a':/*czy animacja*/
				animation = atoi(optarg); 
			break;
			
			case 'o':/*plik png w ktorym ma zostac zapisany obraz*/
				outf = optarg;
			break;
			
			case 'i':/*plik txt z konfiguracja*/
				inpf = optarg;
			break;		
		}
	}

	if(inpf != NULL)
	{
		printf("miejsce na wczytanie powyższych zmiennych z pliku\n");
	}

	mat_t matrix = init(r, c);

	for(int i = 0; i < matrix->r; i++)
		for(int j = 0; j < matrix->c; j++)
			matrix->t[i][j] = 0;

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
		if(animation == 1) /*jesli taka opcja zostala wybrana - animacja mrowki jest wypisywana na konsole*/
		{
			animate(matrix);
		}
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
	
	if(animation == 1)
		animate(matrix);
	process_file(matrix);
	write_png_file(outf);
	free_matrix(matrix);
	free_ants(ants);
}
