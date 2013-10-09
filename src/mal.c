#include <stdio.h>
#include <malloc.h>
#include "mal.h"

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
	if(!IsRealMatrix(mx)){
		mx.rows = -1;
		mx.columns = -1;
		return mx;
	}
	// Initial Array
	mx.mx = malloc(sizeof(double*) * mx.rows);
	// Internal Arrays
	for ( int i = 0; i < mx.rows; i++)
		mx.mx[i] = malloc(sizeof(double) * mx.columns);
	// Initialize numbers
	for ( int row = 0; row < mx.rows; row++)
		for ( int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = 0;
	return mx;
}


int IsValidOp(matrix m1, matrix m2, char op)
{
	switch (op){
		case 'm':
			if ( m1.columns == m2.rows )
				return TRUE;
			else
				return FALSE;
			break;
		case 'a':
		case 's':
			if (m1.columns == m2.columns 
			    && m1.rows == m2.rows)
				return TRUE;
			else
				return FALSE;
			break;
		case 'i':
			if(m1.rows == m1.columns)
				return TRUE;
			else
				return FALSE;
			break;
		default:
			return FALSE;
	}
}

// EXTERNAL FUNCTIONS

void matrixParsedInit()
{
	///IMPLEMENT LATER
	/* Specs: 
	 * Should take a string
	 * Figure out how many rows (maybe counting '\n's, '['s)
	 * then use ','s as a delimeter between two numbers
	 * ignore ' 's
	 * make a matrix using this.
	 * a valid input, for example, would be:
	 * "[[3, 4, 5]\n[2,3,4]\n[1,5,3]]"
	 * You should allow for strings both with and without '\n's.
	 * If the input is invalid, return:
	 * matrix {rows = -1, columns = -1}
	 */
}


matrix matrixInit(int rows, int columns)
{
	matrix mx = Initialize(rows, columns);
	if(!IsRealMatrix(mx))
		return mx;
	
	// Set numbers
	for ( int row = 0; row < mx.rows; row++){
		for ( int col = 0; col < mx.columns; col++){
			printf("%d, %d: ", row, col);
			scanf("%lf", &mx.mx[row][col]);
		}
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
			printf("%g ", mx.mx[row][col]);

		printf("]");
	}
	printf("]\n");
	return 0;
}


matrix matrixAdd(matrix m1, matrix m2)
{
	if (!IsValidOp(m1,m2,'a'))
		return Initialize(0,0);

	matrix mx = Initialize(m1.rows, m1.columns);

	for(int row = 0; row < mx.rows; row++)
		for(int col = 0; col < mx.columns; col++)
			mx.mx[row][col] = (m1.mx[row][col] + m2.mx[row][col]);
	return mx;
}


matrix matrixSub(matrix m1, matrix m2)
{
	if (!IsValidOp(m1,m2,'s'))
		return Initialize(0,0);
	
	matrix mx = Initialize(m1.rows, m1.columns);

	for(int row = 0; row < mx.rows; row++){
		for(int col = 0; col < mx.columns; col++){
			mx.mx[row][col] = 
			(m1.mx[row][col] - m2.mx[row][col]);
		}
	}
	return mx;
}


matrix scalarMul(matrix mx, double n)
{
	matrix sc = Initialize(mx.columns, mx.columns);
	for(int i = 0; i < mx.columns; i++)
		sc.mx[i][i] = n;
	return matrixMul(mx, sc);
}


matrix matrixMul(matrix m1, matrix m2)
{
	if (!IsValidOp(m1,m2,'m'))
		return Initialize(0,0);
		
	matrix mx = Initialize(m1.rows, m2.columns);
	for(int row = 0; row < mx.rows; row++){
		for(int col = 0; col < mx.columns; col++){
			for(int i = 0; i < m1.columns; i++){
				mx.mx[row][col] +=
				(m1.mx[row][i] * m2.mx[i][col]);
			}
		}
	}
	return mx;
}

matrix matrixInv(matrix mx)
{
	if (!IsValidOp(mx,mx,'i'))
		return Initialize(0,0);
	if(mx.rows == 2){
		double tmp;
		double det = 1 / ((mx.mx[0][0] * mx.mx[1][1]) 
		                 -(mx.mx[0][1] * mx.mx[1][0]));
		// Now for the actual calculation
		tmp = mx.mx[0][0];
		mx.mx[0][0] = mx.mx[1][1];
		mx.mx[1][1] = tmp;

		mx.mx[0][1] = mx.mx[0][1] * (-1);
		mx.mx[1][0] = mx.mx[1][0] * (-1);
		// now just multiply by the determinant
		return scalarMul(mx, det);
	} else {
		return Initialize(0,0);
	}
}
