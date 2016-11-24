#include "hanoi.h"
int cnt=1;
//operator count variable

//Tower manufacture function

Data outputTower(stack *tower){
	printf("\ncount : %d\n",cnt++);
	printf("Output tower %c - [%c]\n",tower->name,top(tower));
	return pop(tower);
}//stack output func, input stack, output data(in stack)

void inputTower(stack *tower,Data ring){
	push(tower,ring);
	printf("input tower  %c - [%c]\n",tower->name,ring);
}//stack input func , 

//inoutput Tower function are made for readablilty in HanoiSort F 


void HanoiSort(stack *a, stack *b, stack *c,int n){

	if(n==1){
		inputTower(c,outputTower(a));

	}
	else{
		HanoiSort(a,c,b,n-1);//n-1 rings a to b
		HanoiSort(a,b,c,1);	// a to c
		HanoiSort(b,a,c,n-1); // n-1 rings b to c
	}

	HanoiPrint(a,b,c);//print result
}

void HanoiPrint(stack *a,stack *b,stack *c){	
	printf("\nTower %c:",a->name);
	stackPrint(a);
	printf("Tower %c:",b->name);
	stackPrint(b);
	printf("Tower %c:",c->name);
	stackPrint(c);
	putchar('\n');
	//stack status print
}

