/*
    src/mal.c - The Library itself
    This is the source code for the matrix library itself.
    If you'd like to use it, just use mal.h and mal.c
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "mal.h"

/* INTERNAL FUNCTION */
matrix *initialize(int rows, int columns)
{
    if(rows < 1 || columns < 1){
        return NULL;
    }
    matrix *mx = malloc(sizeof(matrix));
    if(mx == NULL)
        return NULL;
    mx->rows = rows;
    mx->columns = columns;
    // Initial Array
    mx->mx = calloc(mx->rows, sizeof(double *));
    if(mx->mx == NULL){
        free(mx);
        return NULL;
    }
    // Internal Arrays
    for ( int i = 0; i < mx->rows; i++) {
        mx->mx[i] = calloc(mx->columns, sizeof(double));
        if (mx->mx[i] == NULL) {
            for(i--; i >= 0; i--)
                free(mx->mx[i]);
            free(mx);
            return NULL;
        }
    }
    return mx;
}


/* EXTERNAL FUNCTIONS */

matrix *MatrixInit(char *string)
{
    int num;
    int rows = 0;
    int cols = 0;

    // amount of rows
    for(int i = 0;; i++) {
        if(string[i] == '\0'){
            break;
        }
        if(string[i] == '['){
            rows = rows + 1;
        }
    }

    // amount of columns
    for(int i = 0;; i++) {
        if(string[i] == ']'){
            break;
        }
        if(string[i] == '[' || string[i] == ','){
            cols = cols + 1;
        }
    }

    matrix *mx = initialize(rows, cols);
    if (mx == NULL){
        return NULL;
    }

    // Putting the numbers where they belong
    int x = 0, y = 0;
    while(true) {
        string = string + 1;

        if(string[0] == '\0'){
            break;
        }

        // Dealing with numbers longer than one char
        while(isdigit(string[-1])){
            if(isdigit(string[0])){
                string = string + 1;
            } else {
                break;
            }
        }

        if(isdigit(string[0])){
            if(x >= cols) {
                x = 0;
                y = y + 1;
            }

            if(y >= rows) {
                break;
            }

            num = atoi(string);

            mx->mx[y][x] = num;
            x = x + 1;
        }
    }

    return mx;
}

int MatrixPrint(matrix *mx)
{
    for(int row = 0; row < mx->rows; row++){
        printf("[ ");

        for(int col = 0; col < mx->columns; col++) {
            printf("%g ", mx->mx[row][col]);
        }

        printf("]\n");
    }
    return 0;
}


matrix *MatrixAdd(matrix *m1, matrix *m2)
{
    if (m1->columns != m2->columns || m1->rows != m2->rows)
        return NULL;

    matrix *mx = initialize(m1->rows, m1->columns);
    if (mx == NULL){
        return NULL;
    }

    for(int row = 0; row < mx->rows; row++)
        for(int col = 0; col < mx->columns; col++)
            mx->mx[row][col] =
            (m1->mx[row][col] + m2->mx[row][col]);
    return mx;
}


matrix *MatrixSub(matrix *m1, matrix *m2)
{
    if (m1->columns != m2->columns || m1->rows != m2->rows)
        return NULL;

    matrix *mx = initialize(m1->rows, m1->columns);

    for(int row = 0; row < mx->rows; row++){
        for(int col = 0; col < mx->columns; col++){
            mx->mx[row][col] =
            (m1->mx[row][col] - m2->mx[row][col]);
        }
    }
    return mx;
}


matrix *MatrixSMul(matrix *mx, double n)
{
    matrix *sc = initialize(mx->columns, mx->columns);
    if (sc == NULL){
        return NULL;
    }

    for(int i = 0; i < mx->columns; i++){
        sc->mx[i][i] *= n;
    }

    matrix *ret = MatrixMul(mx, sc);
    free(sc);
    return ret;
}


matrix *MatrixMul(matrix *m1, matrix *m2)
{
    if(m1->columns != m2->rows)
        return NULL;

    matrix *mx = initialize(m1->rows, m2->columns);
    if (mx == NULL){
        return NULL;
    }

    for(int row = 0; row < mx->rows; row++){
        for(int col = 0; col < mx->columns; col++){
            for(int i = 0; i < m1->columns; i++){
                mx->mx[row][col] +=
                (m1->mx[row][i] * m2->mx[i][col]);
            }
        }
    }
    return mx;
}

matrix *MatrixInv(matrix *mx)
{
    if(mx->rows != mx->columns)
        return NULL;

    if(mx->rows == 2){

        matrix *inv = initialize(mx->rows, mx->columns);
        if(inv == NULL){
            return NULL;
        }

        double tmp;
        double det =
        1 / ( (mx->mx[0][0] * mx->mx[1][1]) - (mx->mx[0][1] * mx->mx[1][0]) );
        tmp = mx->mx[0][0];
        inv->mx[0][0] = mx->mx[1][1];
        inv->mx[1][1] = tmp;

        inv->mx[0][1] = mx->mx[0][1] * (-1);
        inv->mx[1][0] = mx->mx[1][0] * (-1);
        matrix *ret = MatrixSMul(mx, det);
        free(inv);
        return ret;
    } else {
        return NULL;
    }
}

void MatrixFree(matrix *mx)
{
    if(mx == NULL)
        return;

    for(int i = 0; i < mx->rows; i++){
        if(mx->mx[i] != NULL)
            free(mx->mx[i]);
    }

    if(mx->mx != NULL)
        free(mx->mx);

    free(mx);
}
