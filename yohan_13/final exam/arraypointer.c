#include <stdio.h>

int main(void){
	int i;
	char a[5] = {'a','b','c','d'};
	for(i=0; i<5; ++i){
		printf("%c ",a[i]);
	}
	printf("\n");
	for(i=0;i<5;i++){
		printf("%c",*(a+i));
	}
	printf("\n");
	return 0;
}
