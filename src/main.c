#include <malloc.h>
#include "mal.h"

#define TRUE 1
#define FALSE 0

char multErr[47] = "Multiplication: M1 columns, m2 rows not equal\n";
char addErr[35] = "Addition: Dimensions do not equal\n";
char subErr[38] = "Subtraction: Dimensions do not equal\n";
char invErr[31] = "Inversion: Matrix not square.\n";
char opErr[30] = "Operation: Not an operation\n";

char * getString(int len)
{
	char * ch;
	int i;
	ch = malloc(sizeof(char) * len);
	for(i = 0; i < len; i++){
		ch[i] = getchar();
		if(ch[i] == '\n')
			break;
	}

	ch[i] = '\0';
	if(ch[len - 1] != '\0'){
		char tmp;
		while(TRUE){
			tmp = getchar();
			if (tmp == '\n')
				break;
		}
	}

	return ch;
}

int main(void)
{
	matrix m1, m2, ans;
	int smult, mult, add, sub, inv;

	int r1, c1, r2, c2, sc;
	printf("Which operation: ");
	char * op = getString(5);

	switch(op[0]){
		case 'c':
		case 'C':
			smult = TRUE;
			mult = FALSE;
			add = FALSE;
			sub = FALSE;
			inv = FALSE;
			break;
		case 'm':
		case 'M':
		case '*':
			smult = FALSE;
			mult = TRUE;
			add = FALSE;
			sub = FALSE;
			inv = FALSE;
			break;
		case 'a':
		case 'A':
		case '+':
			smult = FALSE;
			mult = FALSE;
			add = TRUE;
			sub = FALSE;
			inv = FALSE;
			break;
		case 's':
		case 'S':
		case '-':
			smult = FALSE;
			mult = FALSE;
			add = FALSE;
			sub = TRUE;
			inv = FALSE;
			break;
		case 'i':
		case 'I':
			smult = FALSE;
			mult = FALSE;
			add = FALSE;
			sub = FALSE;
			inv = TRUE;
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

	if(smult || inv){
		r2 = r1;
		c2 = c1;
	} else {
		printf("Second matrix rows: ");
		scanf("%d", &r2);
		printf("Second matrix columns: ");
		scanf("%d", &c2);
	}
	if(smult){
	} else if(mult){
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
	} else if(inv){
		if(r1 != c1){
			fprintf(stderr,"Error: %s\n",invErr);
			return 1;
		}
	} else {
		fprintf(stderr,"Error: Unknown\n");
		return 3;
	}

	printf("MATRIX ONE: \n");
	m1 = matrixInit(r1, c1);
	matrixPrint(m1);

	if(smult){
		printf("SCALAR: ");
		scanf("%d", &sc);
	} else if (inv) {
	} else {
		printf("MATRIX TWO: \n");
		m2 = matrixInit(r2, c2);
		matrixPrint(m2);
	}

	if(smult){
		ans = scalarMul(m1,sc);
	} else if(mult){
		ans = matrixMul(m1,m2);
	} else if(add){
		ans = matrixAdd(m1,m2);
	} else if(sub){
		ans = matrixSub(m1,m2);
	} else if(inv){
		ans = matrixInv(m1);
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
