#include <stdio.h>
#include <malloc.h>
#include "matr.h"

// INTERNAL FUNCTIONS

int ArraySum(int len, int * array)
{
	int sum = 0;
	for(int i = 0; i < len; i++)
		sum += array[i];
	return sum;
}


matrix Initialize(int rows, int columns, int i)
{
	matrix mx;
	mx.rows = rows;
	mx.columns = columns;
	// Initial Array
	mx.mx = malloc(sizeof(int*) * mx.rows);
	// Internal Arrays
	for ( int i = 0; i < mx.rows; i++)
		mx.mx[i] = malloc(sizeof(int) * mx.columns);
	// Initialize numbers
	for ( int row = 0; row < mx.rows; row++)
		for ( int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = i;
	return mx;
}


int Check(matrix m1, matrix m2, int mul)
{
	if (mul){
		if ( m1.columns == m2.rows )
			return 0;
		else
			return 1;
	} else {
		if (m1.columns == m2.columns 
		    && m1.rows == m2.rows)
			return 0;
		else
			return 1;
	}
}

// EXTERNAL FUNCTIONS

matrix matrixInit(int rows, int columns)
{
	matrix mx = Initialize(rows, columns, 0);
	// Set numbers
	for ( int row = 0; row < mx.rows; row++)
		for ( int col = 0; col < mx.columns; col++){
			printf("%d, %d: ", row, col);
			scanf("%d", &mx.mx[row][col]);
		}
			
	return mx;
}


int matrixPrint(matrix mx)
{
	printf("[\n");
	for(int row = 0; row < mx.rows; row++){
		for(int col = 0; col < mx.columns; col++)
			printf(" %d", mx.mx[row][col]);
		printf("\n");
	}
	printf("]\n");
	return 0;
}


matrix matrixAdd(matrix m1, matrix m2)
{
	if (Check(m1,m2,0))
		return Initialize(0,0,0);

	matrix mx = Initialize(m1.rows, m1.columns, 0);

	for(int row = 0; row < mx.rows; row++)
		for(int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = 
			(m1.mx[row][col] + m2.mx[row][col]);
	return mx;
}


matrix matrixSub(matrix m1, matrix m2)
{
	if (Check(m1,m2,0))
		return Initialize(0,0,0);
	
	matrix mx = Initialize(m1.rows, m1.columns, 0);

	for(int row = 0; row < mx.rows; row++)
		for(int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = 
			(m1.mx[row][col] - m2.mx[row][col]);
	return mx;
}




matrix matrixMul(matrix m1, matrix m2)
{
	if (Check(m1,m2,0))
		return Initialize(0,0,0);
		
	matrix mx = Initialize(m1.rows, m2.columns, 0);
	int * tmpArr = malloc(sizeof(int) * mx.columns);
	for(int row = 0; row < mx.rows; row++)
		for(int col = 0; col < mx.columns; col++)
			for(int i = 0; i < m1.columns; i++){
				tmpArr[i] = 
				(m1.mx[row][i] * m2.mx[i][col]);
				mx.mx[row][col] = 
				(ArraySum(m1.columns, tmpArr));
			}
	return mx;
}
