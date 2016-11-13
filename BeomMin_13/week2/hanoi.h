#include <stdio.h>
#include <malloc.h>

typedef struct node { //make node
	int data;
	struct node *next;
}NODE;

typedef struct stack { //make stack
	NODE* top;
}STACK;

// make stack A, B, C
STACK* A;
STACK* B;
STACK* C;

typedef unsigned char bool; //make bool operation
#define true 1
#define false 0

void initial_stack();

void push(STACK*, int);
NODE pop(STACK*);
bool isEmpty(STACK*);
void allstackprint(STACK*, STACK*, STACK*);
void stackprint(STACK*);

void move(int, STACK*, STACK*, STACK*);

int convert_int(NODE);

