#include <stdio.h>

void recursiveFunction_1(int num){
	printf("recursiveFunction_1 : %d\n", num);
	if(num<10){
	  recursiveFunction_1(num + 1);
	}
}

void recursiveFunction_2(int num){
	if(num<10){
	  recursiveFunction_2(num+1);
	}
	printf("recursiveFunction_2 : %d\n",num);
}

int main(int argc, char const *argv[]){
	recursiveFunction_1(1);
	printf("\n");
	recursiveFunction_2(1);
	return 0;
}
