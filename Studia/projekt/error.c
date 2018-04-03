#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "matrix.h"

int checkMatrix( int x)
{
	if(x>10000 || x<0)
	{
		return 1;
	}
	else
	{	
		return 0;
	}
}
int checkSteps( int x)
{
	if(x>10000000 || x<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int checkAmount( int x)
{
	if(x>1000 || x<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*int checkHeight( int cord, mat_t matrix)
{
	if(cord<0 || cord >= matrix->r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkWidth( int cord, mat_t matrix)
{
	
	if(cord<0 || cord >= matrix->c)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
*/

