#ifndef MATMUL_H
#define MATMUL_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INP_BND 100
void matmul(int *A, int *B, int *C, int n);
void printMatrix(int *A, int n);
void setRand(int *A, int n);
void zero(int *A, int n);
#endif