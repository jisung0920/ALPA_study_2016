#include "hanoi.h"

int main(void){
	
	stack X,Y,Z;
	int size;

	stackInit(&X);
	stackInit(&Y);
	stackInit(&Z);

	size = stackPusher(&X);
	stackPrint(&X);
	

	HanoiSort(&X,&Y,&Z,size);
	stackPrint(&Z);
	return 0;
}
