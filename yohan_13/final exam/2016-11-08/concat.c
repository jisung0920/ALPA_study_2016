#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* malloc() return void pointer.*/
char* concat(char*, char*);

int main(int argc, char const *argv[]){
	char* a = "Hello,";
	char* b = "World!";
	char* string = concat(a,b);
	printf("%s\n",string);
}

char* concat(char* a, char* b){
	/* Code here*/
	char* space = (char*)malloc((strlen(a)+ strlen(b)));
	int i,j;
	for(i=0; i<strlen(a); i++){
		*(space + i) =a[i];  
	}	
	for(j=0,i=strlen(a); i<strlen(a)+strlen(b); i++,j++){
		*(space+i) = b[j];
	}
	*(space+strlen(a)+strlen(b))='\0';
	return space;
}
