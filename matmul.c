#include "matmul.h"

// https://github.com/attractivechaos/matmul/blob/master/matmul.c
// 
// High quality code such as this is the ultimate goal, but for now just compiler settings
// 
// ASSUME: NxN matrices. I think this is valid with a padding argument.

// A is n x r, B is r x m
// C is n x m
// n rows, r cols
// C[i][j] += A[i][k] * B[k][j]
void matmul(int* A, int* B, int* C, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				C[n * i + j] += A[n * i + k] * B[n * k + j];
}

void printMatrix(int* A, int n) {
	for (int i  = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[n * i + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void setRand(int *A, int n) {
	for (int i  = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i * n + j] = rand() % INP_BND;
}

//int main() {
//	int N = 4;
//	int *A = malloc(N*N*sizeof(int));
//	setRand(A, N);
//	printMatrix(A, N);
//	int *B = malloc(N*N*sizeof(int));
//	setRand(B, N);
//	printMatrix(B, N);
//	int *C = malloc(N*N*sizeof(int));
//	//matmul(A, B, C, N);
//	_matmul(A, B, C, N, N, N);
//	printMatrix(C, N);
//	verify(A, B, C, N);
//	free(A);
//	free(B);
//	free(C);
//}
