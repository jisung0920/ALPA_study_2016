#include <stdlib.h>
#include <stdio.h>

int main(void){
	int i;
	int* space = (int*)malloc(sizeof(int)*5);
	for(i=0;i<5;i++){
		*(space +i)=i;
	}
	for(i=0;i<5;i++){
		printf("%d \n", space[i]);
	}
	free(space);
	return 0;
}
