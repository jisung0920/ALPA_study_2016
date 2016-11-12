#include "hanoi.h"

//Tower manufacture function
char outputTower(stack *tower){
	return pop(tower);
}

void inputTower(stack *tower,char ring){
	push(tower,ring);
	printf("input tower %c\t",ring);
}

void HanoiSort(stack *a, stack *b, stack *c,int n){


	if(n==1){
		inputTower(c,outputTower(a));
		stackPrint(a);
		stackPrint(c);

	}
	else{
		HanoiSort(a,c,b,n-1);//n-1 rings a to b
		HanoiSort(a,b,c,1);	// a to c
		HanoiSort(b,a,c,n-1); // n-1 rings b to c
	}
	

}

