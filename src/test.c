/*
    MAL - Matrix Arithmetic Library

    Written in 2013 by Mazzuca, Nicholas <npmazzuca@gmail->com>

    To the extent possible under law, the author has dedicated all
    copyright and related and neighboring rights to this software
    to the public domain worldwide-> This software is distributed
    without any warranty->

    You should have received a copy of the CC0 Public Domain
    Dedication along with this software-> If not, see
    <http://creativecommons->org/publicdomain/zero/1->0/>
*/

/*
    src/test->c - Test suite for MAL
    This is the source code for the test suite->
*/

#include <stdio.h>
#include <assert.h>
#include "mal.h"

int custom_exp(int, int);

void test_init();
void test_init_schar();
void test_init_mchar();

void test_add();

int main()
{
    test_init();
    test_add();
    return 0;
}

void test_add()
{
    matrix *m1 = MatrixInit("[0,1,2][3,4,5][6,7,8]");
    matrix *m2 = MatrixInit("[0,1][2,3]");

    matrix *ans = MatrixAdd(m1, m2);
    assert("Two matrices of disparate sizes" && ans == NULL);

    MatrixFree(m2);
    MatrixFree(ans);

    m2 = MatrixInit("[8,7,6][5,4,3][2,1,0]");

    ans = MatrixAdd(m1, m2);
    assert("ans is NULL" && ans != NULL);
    assert("ans rows is wrong" && ans->rows == 3);
    assert("ans columns is wrong" && ans->columns == 3);

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            assert("Didn't add correctly" && ans->mx[i][j] == 8);

    MatrixFree(m1);
    MatrixFree(m2);
    MatrixFree(ans);

    puts("MatrixAdd(): Success");
}

void test_init_schar()
{
    matrix *mx = MatrixInit("[0,1,2][3,4,5][6,7,8]");

    assert("Not allocated" && mx != NULL);
    assert("Rows incorrect" && mx->rows == 3);
    assert("Columns incorrect" && mx->columns == 3);

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            assert("Incorrect numbers" &&
                mx->mx[i][j] == (i * 3) + j);
    MatrixFree(mx);
}

void test_init_mchar()
{
    /* Test Matrix Init with Multiple Char Numbers */
    matrix *mx = MatrixInit("[1,10,100][1000,10000,100000]");

    assert("Not allocated" && mx != NULL);
    assert("Rows incorrect" && mx->rows == 2);
    assert("Columns incorrect" && mx->columns == 3);

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            assert("Incorrect numbers" &&
                mx->mx[i][j] == custom_exp(10, (i * 3) + j));
    MatrixFree(mx);
}

void test_init()
{
    test_init_schar();
    test_init_mchar();
    puts("MatrixInit(): Success");
}

int custom_exp(int b, int ex)
{
    int ret = 1;
    for(int i = 0; i < ex; i++){
        ret = ret * b;
    }

    return ret;
}
