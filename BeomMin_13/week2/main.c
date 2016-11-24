#include "hanoi.h"

void main() {
	
	initial_stack();

	int input;
	scanf("%d", &input);
	for (int i = input; i > 0; i--) {
		push(A, i);
	}

	printf("Initial Stack\n");
	allstackprint(A,B,C);
	move(input, A, B, C);
	printf("Result\n");
	allstackprint(A,B,C);

}			

