#ifndef MAL_H
#define MAL_H

typedef struct {
    int rows, columns;
    double **mx;
} matrix;

matrix *MatrixInit(char *matrix_string);
int MatrixPrint(matrix *mx);
matrix *MatrixAdd(matrix *m1, matrix *m2);
matrix *MatrixSub(matrix *m1, matrix *m2);
matrix *MatrixMul(matrix *m1, matrix *m2);
matrix *MatrixSMul(matrix *m1, double scalar);
matrix *MatrixInv(matrix *mx);
void MatrixFree(matrix *mx);

#endif
