#include <stdio.h>

int main(void){
	char a[4][10] = {"HaHa", "han yang ", "cheese", " Iphone"}; 
	char *(pc[4]) = {a[0], a[1], a[2], a[3]};
	char **ppc = pc;
	
	printf("%c",*(*(pc)));
	printf("%c",*(*(pc+1)+1));
	printf("%c",*(*(pc+1)+2));
	printf("%s",*(ppc+1)+4);
	printf(" %c",*(*(pc+2)));
	printf("%c",*(*(pc+2)+4));
	printf("%c",*(*(pc+2)+5));
	return 0;
}

// Print "Hanyang cse"
