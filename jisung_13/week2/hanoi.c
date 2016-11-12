#include "hanoi.h"

void stackInit(stack * tower){
	
}

int stackEmpty(stack *tower){
	if(tower->top)
		return true;
	else
		return false;
}

char pop(stack *tower){
	if(stackEmpty(tower)){
		printf("stack is empty");
		return '\0';//exception

	return tower->ring[tower->(top--)];//array pointer(top) decrease
}

char top(stack *tower){
	return tower->ring[tower->top];
}

void push(stack *tower,Data nring){
	if(tower->top==SIZE){
		printf("Stack is full");
		return ;
	}
	tower->ring[++top]=nring;
}

void stackPrint(stack *tower){
	if(!stackEmpty(tower)){
		for(int i=0;i<(tower->top);i++)
			printf("[%c]",tower->ring[i]);
	}//untill stack size
	printf("stack is empty");
}

char outputTower(stack *tower){
	return pop(tower);
}

void inputTower(stack *tower,char ring){
	push(tower,ring);
}

void HanoiSort(stack *a, stack *b, stack *c,int n){

	if(n==1){
		inputTower(c,outputTower(a));
	}
	else{
		HanoiSort(a,c,b,n-1);//n-1 rings a to b
		HanoiSort(a,b,c,1);	// a to c
		HanoiSort(b,a,c,n-1); // n-1 rings b to c
	}
		
}

