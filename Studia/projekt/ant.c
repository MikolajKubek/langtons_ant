#include <stdlib.h>
#include "ant.h"

void move(ant_t ant, int s)
{
	switch (ant->pos)
	{
		case 1:
			if(s == 0)
			{
				ant->pos = 4;
				ant->x--;
			}
			else if(s == 1)
			{
				ant->pos = 2;
				ant->x++;
			}

		break;
		case 2:
			if(s == 0)
			{
				ant->pos = 1;
				ant->y++;
			}
			else if(s == 1)
			{
				ant->pos = 3;
				ant->y--;
			}
			
		break;
		case 3:
			if(s == 0)
			{
				ant->pos = 2;
				ant->x++;
			}
			else if(s == 1)
			{
				ant->pos = 4;
				ant->x--;
			}
		break;
		case 4:
			if(s == 0)
			{
				ant->pos = 3;
				ant->y--;
			}
			if(s == 1)
			{
				ant->pos = 1;
				ant->y++;
			}
		break;
	}

}

void mirror(ant_t ant, int x, int y)
{
	x--;
	y--;
	if(ant->x < 0)
		ant->x = x;
	else if(ant->x > x)
		ant->x = 0;

	if(ant->y < 0)
		ant->y = y;
	else if(ant->y > y)
		ant->y = 0;
}

ants_t ants_init(int n)
{
	ants_t ants = malloc(sizeof(ants));
	ants->n = n;

	ants->ants = malloc(n*sizeof(ants->ants));

	for(int i = 0; i < n; i++)
		ants->ants[i] = malloc(sizeof(ants->ants[i]));	
	return ants;
}

void free_ants(ants_t ants)
{
	for(int i = 0; i < ants->n; i++)
		free(ants->ants[i]);

	free(ants->ants);

	free(ants);
}

