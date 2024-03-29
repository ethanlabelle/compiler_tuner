#include "performance.h"
#include "fib.h"
#include "matmul.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void benchmark_matmul() {
  int size = 1024;
  int elms = size * size;
  int *A = calloc(elms, sizeof(int));
  int *B = calloc(elms, sizeof(int));
  int *C = calloc(elms, sizeof(int));
  float startTime = (float)clock() / CLOCKS_PER_SEC;
  setRand(A, size);
  setRand(B, size);
  matmul(A, B, C, size);
  zero(C, size);
  float endTime = (float)clock() / CLOCKS_PER_SEC;
  float timeElapsed = endTime - startTime;
  printf("time: %fs\n", timeElapsed);
}

void benchmark_fib() {
  float startTime = (float)clock() / CLOCKS_PER_SEC;
  int a = fib(45);
  float endTime = (float)clock() / CLOCKS_PER_SEC;
  float timeElapsed = endTime - startTime;
  printf("time: %fs\n", timeElapsed);
}

void benchmark() { benchmark_fib(); }
