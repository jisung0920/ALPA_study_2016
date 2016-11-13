#include "hanoi.h"

int convert_int(NODE node) {
	int cint = node.data;
	return cint;
}

void initial_stack() {
	A = (STACK*)malloc(sizeof(STACK));
	A->top = NULL;
	B = (STACK*)malloc(sizeof(STACK));
	B->top = NULL;
	C = (STACK*)malloc(sizeof(STACK));
	C->top = NULL;
}

void allstackprint(STACK* A, STACK* B, STACK* C) {
	stackprint(A);
	printf("A stack\n");
	stackprint(B);
	printf("B stack\n");
	stackprint(C);
	printf("C stack\n");
	printf("\n----------------------------\n");
}
