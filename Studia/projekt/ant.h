#ifndef _ANT_H
#define _ANT_H

typedef struct
{
	int x;
	int y;
	int pos;
	int brk;
}*ant_t;

typedef struct 
{
	ant_t *ants;
	int n;
}*ants_t;

void move(ant_t ant, int s);
void mirror(ant_t ant, int x, int y);
ants_t ants_init(int n);
void free_ants(ants_t ants);
#endif
