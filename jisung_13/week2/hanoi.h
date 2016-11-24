#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef char Data;//data type define for alternative

typedef struct stack{
	Data ring[SIZE];
	int top;
	char name;
}stack;//stack struct   +member 'name' made for print

void setName(stack*,char);
void stackInit(stack*);
int stackEmpty(stack*);
Data pop(stack*);
Data top(stack*);
void push(stack*,Data ring);

void stackPrint(stack *);
int stackPusher(stack *);

Data outputTower(stack *target); 
void inputTower(stack *target, Data ring);
void HanoiSort(stack *a,stack *b, stack *c,int size);
void HanoiPrint(stack*,stack*,stack*);


