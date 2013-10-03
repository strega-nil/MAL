#include <stdio.h>
#include <malloc.h>
#include "matr.h"

#define TRUE 1
#define FALSE 0

// INTERNAL FUNCTIONS
int IsRealMatrix(matrix mx)
{
	if(mx.rows < 1 || mx.columns < 1)
		return FALSE;
	else
		return TRUE;
}


matrix Initialize(int rows, int columns)
{
	matrix mx;
	mx.rows = rows;
	mx.columns = columns;
	if(!IsRealMatrix){
		mx.rows = -1;
		mx.columns = -1;
		return mx;
	}
	// Initial Array
	mx.mx = malloc(sizeof(int*) * mx.rows);
	// Internal Arrays
	for ( int i = 0; i < mx.rows; i++)
		mx.mx[i] = malloc(sizeof(int) * mx.columns);
	// Initialize numbers
	for ( int row = 0; row < mx.rows; row++)
		for ( int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = 0;
	return mx;
}


int IsValidOp(matrix m1, matrix m2, int mul)
{
	if (mul){
		if ( m1.columns == m2.rows )
			return TRUE;
		else
			return FALSE;
	} else {
		if (m1.columns == m2.columns 
		    && m1.rows == m2.rows)
			return TRUE;
		else
			return FALSE;
	}
}

// EXTERNAL FUNCTIONS

matrix matrixInit(int rows, int columns)
{
	matrix mx = Initialize(rows, columns);
	if(!IsRealMatrix(mx)){
		return mx;
	}
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
	printf("[");
	for(int row = 0; row < mx.rows; row++){

		if(row == 0)
			printf("[ ");
		else
			printf("\n [ ");

		for(int col = 0; col < mx.columns; col++)
			printf("%d ", mx.mx[row][col]);

		printf("]");
	}
	printf("]\n");
	return 0;
}


matrix matrixAdd(matrix m1, matrix m2)
{
	if (!IsValidOp(m1,m2,FALSE))
		return Initialize(0,0);

	matrix mx = Initialize(m1.rows, m1.columns);

	for(int row = 0; row < mx.rows; row++)
		for(int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = 
			(m1.mx[row][col] + m2.mx[row][col]);
	return mx;
}


matrix matrixSub(matrix m1, matrix m2)
{
	if (!IsValidOp(m1,m2,FALSE))
		return Initialize(0,0);
	
	matrix mx = Initialize(m1.rows, m1.columns);

	for(int row = 0; row < mx.rows; row++)
		for(int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = 
			(m1.mx[row][col] - m2.mx[row][col]);
	return mx;
}


matrix matrixMul(matrix m1, matrix m2)
{
	if (!IsValidOp(m1,m2,TRUE))
		return Initialize(0,0);
		
	matrix mx = Initialize(m1.rows, m2.columns);
	for(int row = 0; row < mx.rows; row++)
		for(int col = 0; col < mx.columns; col++)
			for(int i = 0; i < m1.columns; i++){
				mx.mx[row][col] =
				(m1.mx[row][i] * m2.mx[i][col]);
			}
	return mx;
}
