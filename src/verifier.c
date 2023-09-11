#include "verifier.h"
#include "matmul.h"
#include "fib.h"
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
	int *Br = calloc(n, sizeof(int));
	int *Cr = calloc(n, sizeof(int));
	int *ABr = calloc(n, sizeof(int));
	int *sub = calloc(n, sizeof(int));
	_matmul(B, r, Br, n, n, 1);
	_matmul(C, r, Cr, n, n, 1);
	_matmul(A, Br, ABr, n, n, 1);
	matsub(ABr, Cr, sub, n, 1);
	for (int i = 0; i < n; i++) {
		assert(sub[i] == 0);
	}
	free(Br);
	free(Cr);
	free(ABr);
	free(sub);
	return 1;
}

void verify_matmul() {
    for (int i = 1; i <= 100; i++) {
        int *A = calloc(i*i, sizeof(int));
        int *B = calloc(i*i, sizeof(int));
        int *C = calloc(i*i, sizeof(int));
        setRand(A, i);
        setRand(B, i);
        matmul(A, B, C, i);
        for (int j = 0; j < i; j++)
            freivald(A, B, C, i);
	    free(A);
	    free(B);
	    free(C);
    }
    printf("passed verifier!\n");
}

void verify() {
	verify_fib();
}

void verify_fib() {
	assert(fib(0) == 0);
	assert(fib(1) == 1);
	assert(fib(10) == 55);
	assert(fib(20) == 6765);
	assert(fib(30) == 832040);
    printf("passed verifier!\n");
}
