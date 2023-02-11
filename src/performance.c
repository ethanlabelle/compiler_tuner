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
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    // for (int i = 0; i < 2; i++) {
    setRand(A, size);
    setRand(B, size);
    matmul(A, B, C, size);
    zero(C, size);
    // }
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    float timeElapsed = endTime - startTime;
    printf("time: %fs\n", timeElapsed);
}