#include "hanoi.h"

void setName(stack * tower, char c){
	tower->name=c;
}

void stackInit(stack * tower){
	tower->top = -1;	
}

int stackEmpty(stack *tower){
	if((tower->top) == -1)
		return 1;
	else
		return 0;
}

Data pop(stack *tower){
	if(stackEmpty(tower)){
		printf("stack is empty\n");
		exit(-1);	
	}
	tower->top -=1;
	return tower->ring[(tower->top)+1];//array pointer(top) decrease
	
}

Data top(stack *tower){
	return tower->ring[tower->top];
}

void push(stack *tower,Data nring){
	if((tower->top)==(SIZE)){
		printf("Stack is full\n");
		exit(-1);
	}
	tower->top+=1;

	tower->ring[tower->top]=nring;
}

//addtion function

void stackPrint(stack *tower){
	if((tower->top)>-2){//also empty stack
		for(int i=0;i<(SIZE);i++){
			if(i<(tower->top)+1)
				printf("[%c]",tower->ring[i]);
			else
				printf("[ ]");
		}
		putchar('\n');
	}//untill stack size
	else
		printf("stack print error\n");
}

int stackPusher(stack *tower){
	int n;
	printf("input ring number(MAX %d) : ",SIZE);
	scanf("%d",&n);
	
	if(n<1 || n>SIZE){
		printf("input error\n");
		exit(-1) ;
	}

	for(char c='A';c<'A'+n;c++)
		push(tower,c);

	return n;
}//push char type data into stack 
//this function has type dependency(char)
