#ifndef MAL_H
#define MAL_H

typedef struct {
	int rows, columns;
	double ** mx;
} matrix;

matrix matrixInit(int, int);
int matrixPrint(matrix);
matrix matrixAdd(matrix, matrix);
matrix matrixSub(matrix, matrix);
matrix matrixMul(matrix, matrix);
matrix scalarMul(matrix, double);
matrix matrixInv(matrix);
// NOT YET IMPLEMENTED //
//matrix matrixParsedInit();

#endif
