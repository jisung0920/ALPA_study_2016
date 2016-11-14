#include "hanoi.h"

int main(void){
	
	stack X,Y,Z;
	int size;

	stackInit(&X);
	stackInit(&Y);
	stackInit(&Z);
	
	setName(&X,'X');
	setName(&Y,'Y');
	setName(&Z,'Z');
	//stack init and name setting

	size = stackPusher(&X);	//input stack and resive size 
	

	printf("\n========================================\n");
	stackPrint(&X);
	
	HanoiSort(&X,&Y,&Z,size);//call Sort function
	
	stackPrint(&Z);
	printf("\n========================================\n");
	return 0;
}
