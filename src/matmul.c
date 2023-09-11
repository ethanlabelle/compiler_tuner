#include "matmul.h"

// https://github.com/attractivechaos/matmul/blob/master/matmul.c
//
// High quality code such as this is the ultimate goal, but for now just
// compiler settings
//
// ASSUME: NxN matrices. I think this is valid with a padding argument.

// A is n x r, B is r x m
// C is n x m
// n rows, r cols
// C[i][j] += A[i][k] * B[k][j]
void matmul(int *A, int *B, int *C, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[n * i + j] += A[n * i + k] * B[n * k + j];
}

void printMatrix(int *A, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", A[n * i + j]);
    }
    printf("\n");
  }
  printf("\n");
}

void setRand(int *A, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      A[i * n + j] = rand() % INP_BND;
}

void zero(int *A, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      A[i * n + j] = 0;
}