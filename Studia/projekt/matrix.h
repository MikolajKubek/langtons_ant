#ifndef MATRIX_H
#define MATRIX_H
typedef struct matrix
{
	int **t;
	int r;
	int c;
}*mat_t;

mat_t init(int r, int c);
void animate(mat_t matrix);
void free_matrix(mat_t matrix);
#endif
