#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef char Data;
typedef struct stack{
	Data ring[SIZE];
	int top;
}stack;

void stackInit(stack*);
int stackEmpty(stack*);
char pop(stack*);
char top(stack*);
void push(stack*,Data ring);

void stackPrint(stack *);
int stackPusher(stack *);

char outputTower(stack *target); 
void inputTower(stack *target, Data ring);
void HanoiSort(stack *a,stack *b, stack *c,int size);



