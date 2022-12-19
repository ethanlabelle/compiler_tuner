#include "verifier.h"
#include "performance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-v"))
			verify();
		else if (!strcmp(argv[i], "-b"))
			benchmark();
		else
			printf("please provide -v to verify, -b to benchmark\n");
	}
	return 0;
}