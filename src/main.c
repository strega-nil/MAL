#include <malloc.h>
#include "matr.h"

#define TRUE 1
#define FALSE 0

char multErr[46] = "Multiplication: M1 columns, m2 rows not equal";
char addErr[34] = "Addition: Dimensions do not equal";
char subErr[38] = "Subtraction: Dimensions do not equal.";
char opErr[30] = "Operation: Not an operation.";

char getch()
{
	char tmp;
	char ch = getchar();
	while(TRUE){
		tmp = getchar();
		if (tmp == '\n')
			break;
	}
	return ch;
}

int main(void)
{
	matrix m1, m2, ans;
	int mult, add, sub;

	int r1, c1, r2, c2;
	printf("Which operation: ");
	char op = getch();


	switch(op){
		case 'm':
		case 'M':
		case '*':
			mult = TRUE;
			add = FALSE;
			sub = FALSE;
			break;
		case 'a':
		case 'A':
		case '+':
			mult = FALSE;
			add = TRUE;
			sub = FALSE;
			break;
		case 's':
		case 'S':
		case '-':
			mult = FALSE;
			add = FALSE;
			sub = TRUE;
			break;
		default:
			fprintf(stderr,"Error: %s\n",opErr);
			return 2;
			break;
	}
	
	printf("First matrix rows: ");
	scanf("%d", &r1);
	printf("First matrix columns: ");
	scanf("%d", &c1);

	printf("Second matrix rows: ");
	scanf("%d", &r2);
	printf("Second matrix columns: ");
	scanf("%d", &c2);

	if(mult){
		if(c1 != r2){
			fprintf(stderr,"Error: %s\n",multErr);
			return 1;
		}
	} else if(add){
		if(r1 != r2 || c1 != c2){
			fprintf(stderr,"Error: %s\n",addErr);
			return 1;
		}
	} else if(sub){
		if(r1 != r2 || c1 != c2){
			fprintf(stderr,"Error: %s\n",subErr);
			return 1;
		}
	} else {
		fprintf(stderr,"Error: Unknown");
		return 3;
	}

	printf("MATRIX ONE: \n");
	m1 = matrixInit(r1, c1);
	matrixPrint(m1);

	printf("MATRIX TWO: \n");
	m2 = matrixInit(r2, c2);
	matrixPrint(m2);

	if(mult){
		ans = matrixMul(m1,m2);
	} else if(add){
		ans = matrixAdd(m1,m2);
	} else if(sub){
		ans = matrixSub(m1,m2);
	} else {
		fprintf(stderr,"Error: Unknown");
	}

	printf("ANSWER\n");
	matrixPrint(ans);

	free(m1.mx);
	free(m2.mx);
	free(ans.mx);
	return 0;
}
