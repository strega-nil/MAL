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
