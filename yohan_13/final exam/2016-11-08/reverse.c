#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char*);

int main(int argc, char const *argv[]){
	char str[] = "abcdefghijklmonpqrstuvwxyz";
	printf("%s\n",reverse(str));
	return 0;

}
char* reverse(char* s){
	/* code here*/
	char* space = (char *)malloc(strlen(s));
	int i,j;
	for(j=0,i=strlen(s);i!=0;--i,++j){
		*(space +j)= s[i-1];
	}
	*(space+strlen(s)) = '\0';
	return space;
	}

