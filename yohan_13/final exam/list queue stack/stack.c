#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

/* Define 'stack' using typedef and struct.
	stack has top, size */

/* Prototypes */
stack* init_stack();
void push(stack*, node*);
void pop(stack*);
int top(stack*);
void print_stack(stack*);

int main(int argc, char const *argv[]) {
	int i;
	stack* s = init_stack();
	push(s, newnode(1));
	printf("top : %d\n", top(s));
	pop(s);
	pop(s);
	for (i = 2; i < 6; i++) {
		push(s, newnode(i));
	}
	pop(s);
	print_stack(s);
	for (i = 0; i < 3; i++) pop(s);
	top(s);
	return 0;
}
