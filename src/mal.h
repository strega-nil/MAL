/*
    MAL - Matrix Arithmetic Library

    Written in 2013 by Mazzuca, Nicholas <npmazzuca@gmail.com>

    To the extent possible under law, the author has dedicated all
    copyright and related and neighboring rights to this software
    to the public domain worldwide. This software is distributed
    without any warranty.

    You should have received a copy of the CC0 Public Domain
    Dedication along with this software. If not, see
    <http://creativecommons.org/publicdomain/zero/1.0/>
*/

#ifndef _MAL_H
#define _MAL_H

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
int MatrixFree(matrix *mx);

#endif
