#include "verifier.h"
#include "matmul.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void _matmul(int *A, int* B, int *C, int n, int r, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < r; k++)
				C[m * i + j] += A[n * i + k] * B[m * k + j];
}

void matsub(int *A, int* B, int* C, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			C[m * i + j] = A[m * i + j] - B[m * i + j];
}

// https://en.wikipedia.org/wiki/Freivalds%27_algorithm
//
// Algorithm:
// Generate Nx1 random bitvector r
// Compute P = A x Br - Cr
int freivald(int* A,int* B,int* C, int n) {
	int r[n];
	for (int i = 0; i < n; i++) {
		r[i] = rand() % 2;
	}
	int *Br = malloc(n * sizeof(int));
	int *Cr = malloc(n * sizeof(int));
	int *ABr = malloc(n * sizeof(int));
	int *sub = malloc(n * sizeof(int));
	_matmul(B, r, Br, n, n, 1);
	_matmul(C, r, Cr, n, n, 1);
	_matmul(A, Br, ABr, n, n, 1);
	matsub(ABr, Cr, sub, n, 1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", sub[i]);
		assert(sub[i] == 0);
	}
	free(Br);
	free(Cr);
	free(ABr);
	free(sub);
	return 1;
}

void verify() {
    printf("in verify\n");
	// int N = 4;
	// int *A = malloc(N*N*sizeof(int));
	// setRand(A, N);
	// printMatrix(A, N);
	// int *B = malloc(N*N*sizeof(int));
	// setRand(B, N);
	// printMatrix(B, N);
	// int *C = malloc(N*N*sizeof(int));
    // for (int i = 1; i <= 100; i++) {
    //     int *A = malloc(i*i*sizeof(int));
    //     int *B = malloc(i*i*sizeof(int));
    //     int *C = malloc(i*i*sizeof(int));
    //     matmul(A, B, C, i);
    //     assert(freivald(A, B, C, i));
    // }
	// free(A);
	// free(B);
	// free(C);
}