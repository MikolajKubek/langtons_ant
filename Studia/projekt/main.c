#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <getopt.h>
#include <ctype.h>

#include "ant.h"
#include "matrix.h"
#include "exporttopng.h"
#include "error.h"
int main(int argc, char ** argv)
{
	int opt;
	int tmp;
	int c = 184;
	int r = 184;
	int amount_of_ants = 1;
	int animation = 0;
	int n = 11000;
	char* outf = "out.png";
	char* inpf = NULL;
	while((opt = getopt(argc, argv, "w:h:q:n:a:o:i:")) != -1)
	{
		switch(opt)
		{
			case 'w':/*szerokosc*/
				if(atoi(optarg)!=0)
				{
					if(checkMatrix(atoi(optarg))==0)
						c =  atoi(optarg);
					else
						printf("Przekroczono limit szerokosci\n");
				}
				else
					printf("Argument podany jako szerokosc nie jest liczbą\n");
			break;
			
			case 'h':/*wysokosc*/
				if(atoi(optarg)!=0)
				{
					if(checkMatrix(atoi(optarg))==0)
						r = atoi(optarg);
					else
						printf("Przekroczono limit wysokosci\n");
				}
				else
					printf("Argument podany jako wysokosc nie jest liczbą\n");
			break;

			case 'q':/*ilosc mrowek*/
				if(atoi(optarg)!=0)
				{
					if(checkAmount(atoi(optarg))==0)
						amount_of_ants = atoi(optarg);
					else
						printf("Przekroczono limit liczby mrowek\n");
				}
				else
					printf("Argument podany jako liczba mrowek nie jest liczbą\n");
			break;
			
			case 'n':/*ilosc krokow*/
				if(atoi(optarg)!=0)
				{
					if(checkSteps(atoi(optarg))==0)
						n = atoi(optarg);
					else
						printf("Przekroczono limit ilosci krokow\n");
				}
				else
					printf("Argument podany jako ilosc krokow nie jest liczbą\n");
			break;

			case 'a':/*czy animacja*/
				if(atoi(optarg)==1 || atoi(optarg)==0)
					animation = atoi(optarg);
				else 
					printf("Argument podany jako animacja jest niewlasciwy\n");	
				
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
