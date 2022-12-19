#ifndef MATMUL_H
#define MATMUL_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define INP_BND 10
void matmul(int* A, int* B, int* C, int n);
void printMatrix(int* A, int n);
void setRand(int *A, int n);
#endif