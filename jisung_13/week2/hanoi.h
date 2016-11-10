#include <stdio.h>
#define SIZE 20

typedef struct stack{
	char st[SIZE];
	int top=0;
}stack;

char pop(stack);
char top(stack);
void push(stack,char ring);

void initTower(stack a,int size);

char outputTower(stack target); 
void inputTower(stack target, char ring);
void HanoiSort(stack a,stack b, stack c,int size);



