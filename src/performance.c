#include "performance.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matmul.h"

void benchmark() {
    int size = 1024;
    int elms = size * size;
    int *A = calloc(elms, sizeof(int));
    int *B = calloc(elms, sizeof(int));
    int *C = calloc(elms, sizeof(int));
    setRand(A, size);
    setRand(B, size);
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    matmul(A, B, C, size);
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    float timeElapsed = endTime - startTime;
    printf("time: %fs\n", timeElapsed);
}

void benchmark2() {
    int size = 2048;
    int elms = size * size;
    int *A = calloc(elms, sizeof(int));
    int *B = calloc(elms, sizeof(int));
    int *C = calloc(elms, sizeof(int));
    setRand(A, size);
    setRand(B, size);
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    matmul(A, B, C, size);
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    float timeElapsed = endTime - startTime;
    printf("time: %fs\n", timeElapsed);
}
