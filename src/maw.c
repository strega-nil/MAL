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

/*
    src/maw.c - Matrix Arithmetic Wrapper
    This gives an example for how to use the library.
    It probably isn't safe, so don't use it in production code.
    It's also kinda terrible. It doesn't error check AT ALL.
    You can probably use it as just a calculator though...
*/

#include <malloc.h>
#include <ctype.h>
#include "mal.h"

char opErr[] = "Invalid Op. Valid operations: +, -, /, *, 'i'nv";

int main(void)
{
    char mStr[1024];
    matrix *ans, *m1, *m2;
    int sc = 0;

    printf("Which operation: ");
    char op = tolower(getchar());

    while(op != '+' || op != '-' || op != '*' || op != '/' || op != 'i') {
        puts(opErr);
        op = tolower(getchar());
    }

    printf("First matrix:\n");
    scanf("%s", mStr);
    m1 = MatrixInit(mStr);
    MatrixPrint(m1);

    if(op == 'a' || op == 's' || op == 'm'){
        printf("Second matrix:\n");
        scanf("%s", mStr);
        m2 = MatrixInit(mStr);
        MatrixPrint(m2);
    } else if(op == 'c') {
        printf("Scalar multiple:\n");
        scanf("%d", &sc);
    }

    switch(op){
        case 'a':
            ans = MatrixAdd(m1, m2);
            break;
        case 's':
            ans = MatrixSub(m1, m2);
            break;
        case 'm':
            ans = MatrixMul(m1, m2);
            break;
        case 'i':
            ans = MatrixInv(m1);
            break;
        case 'c':
            ans = MatrixSMul(m1, sc);
            break;
        default:
            printf("Something went very wrong.\n");
            return 1;
    }

    printf("Answer:\n");
    MatrixPrint(ans);

    MatrixFree(m1);
    MatrixFree(ans);
    if(op == 'a' || op == 's' || op == 'm'){
        MatrixFree(m2);
    }

    return 0;
}
