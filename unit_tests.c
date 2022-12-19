void test1() {
	int A[4] = {1, 2, 3, 4};
	int B[4] = {1, 2, 3, 4};
	int C[4] = {0, 0, 0, 0};
	_matmul(A, B, C, 2);
	int expected[4] = {7, 10, 15, 22};
	for (int i = 0; i < 4; i++) {
		assert(C[i] == expected[i]);
	}
}

void test2() {
	int A[4] = {1, 2, 3, 4};
	int r[2] = {1, 0};
	int C[2] = {0, 0};
	_matmul(A, r, C, 2, 2, 1);
	int expected[2] = {1, 3};
	for (int i = 0; i < 2; i++) {
		assert(C[i] == expected[i]);
	}
}


void test3() {
	int A[4] = {1, 2, 3, 4};
	int r[2] = {0, 1};
	int C[2] = {0, 0};
	_matmul(A, r, C, 2, 2, 1);
	int expected[2] = {2, 4};
	for (int i = 0; i < 2; i++) {
		assert(C[i] == expected[i]);
	}
}

void test4() {
	int A[16] = {9, 9, 1, 6, 3, 6, 3, 5, 2, 8, 4, 7, 2, 8, 8, 1};
	int B[12] = {6, 8, 5, 6, 6, 0, 2, 6, 4, 3, 8, 0};
	int C[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	_matmul(A, B, C, 4, 4, 3);
	int expected[12] = {128, 180, 49, 75, 118, 27, 89, 144, 26, 79, 120, 42};
	for (int i = 0; i < 12; i++) {
		assert(C[i] == expected[i]);
	}
}

void test5() {
	int A[16] = {9, 4, 5, 3,
				 0, 8, 3, 7,
				 0, 7, 5, 4,
				 2, 1, 8, 3};

	int B[16] = {5, 1, 9, 8,
				 0, 7, 3, 2,
				 8, 6, 2, 6,
				 1, 2, 1, 7};

	int C[16] = {0, 0, 0, 0,
				 0, 0, 0, 0,
				 0, 0, 0, 0,
				 0, 0, 0, 0};

	int expected[16] = {88, 73, 106, 131,
						31, 88, 37, 83,
						44, 87, 35, 72,
						77, 63, 40, 87};
	matmul(A, B, C, 4);
	for (int i = 0; i < 16; i++) {
		assert(C[i] == expected[i]);
	}
	int r[4] = {1, 1, 1, 0};
	int br[4] = {0, 0, 0, 0};
	int exBr[4] = {15, 10, 16, 4};
	_matmul(B, r, br, 4, 4, 1);
	for (int i = 0; i < 4; i++) {
		assert(br[i] == exBr[i]);
	}
	int cr[4] = {0, 0, 0, 0};
	int exCr[4] = {267, 156, 166, 180};
	_matmul(C, r, cr, 4, 4, 1);
	for (int i = 0; i < 4; i++) {
		assert(cr[i] == exCr[i]);
	}
	int abr[4] = {0, 0, 0, 0};
	int expAbr[4] = {267, 156, 166, 180};
	_matmul(A, br, abr, 4, 4, 1);
	for (int i = 0; i < 4; i++) {
		assert(abr[i] == expAbr[i]);
	}
	int abr_cr[4] = {0, 0, 0, 0};
	matsub(abr, cr, abr_cr, 4, 1);
	for (int i = 0; i < 4; i++) {
		assert(!abr_cr[i]);
	}
}

// this example is from wikipedia
void test6() {
	int A[4] = {2, 3, 3, 4};
	int B[4] = {1, 0, 1, 2};
	int C[4] = {6, 5, 8, 7};
	int n = 2;
	int r[2] = {1, 1};
	int Br[2] = {0, 0};
	int exBr[2] = {1, 3};
	int Cr[2] = {0, 0};
	int exCr[2] = {11, 15};
	int ABr[2] = {0, 0};
	int exABr[2] = {11, 15};
	int sub[2] = {0, 0};
	_matmul(B, r, Br, n, n, 1);
	for (int i = 0; i < n; i++) {
		assert(Br[i] == exBr[i]);
	}
	_matmul(C, r, Cr, n, n, 1);
	for (int i = 0; i < n; i++) {
		assert(Cr[i] == exCr[i]);
	}
	_matmul(A, Br, ABr, n, n, 1);
	for (int i = 0; i < n; i++) {
		assert(ABr[i] == exABr[i]);
	}
	matsub(ABr, Cr, sub, n, 1);
	for (int i = 0; i < n; i++) {
		assert(sub[i] == 0);
	}
}