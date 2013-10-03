#ifndef MATR_H
#define MATR_H

typedef struct {
	int rows, columns;
	int ** mx;
} matrix;

matrix matrixInit(int, int);
int matrixPrint(matrix);
matrix matrixAdd(matrix, matrix);
matrix matrixSub(matrix, matrix);
matrix matrixMul(matrix, matrix);
matrix vectorMul(matrix, int);
// NOT YET IMPLEMENTED //
//matrix matrixParsedInit();

#endif
