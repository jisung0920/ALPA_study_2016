#include<stdio.h>

unsigned int strlen(char* s)
{
	int len;

	for(len=0;s[len] != '\0';len++)
		;

	return len;
}

char* strcpy(char* des,char* src)
{
	int i;

	for(i=0;i<strlen(src)+1;i++)
		des[i] = src[i];

	return des;
}

char* strncpy(char* des,char* src,int n)
{
	int i;
	
	if(n > strlen(src))
		return "Exceed length";
	
	for(i=0;i<n;i++)
		des[i] = src[i];
	des[i] = '\0';

	return des;
}

char* strcat(char* des,char* src)
{
	int i;
	int d_len = strlen(des);

	for(i=0; i<strlen(src)+1; i++)
		des[d_len+i] = src[i];
	
	return des;
}

int strcmp(char* des,char* src)
{
	if(des[0] == src[0])
		return 0;
	else if(des[0] > src[0])
		return 1;
	else
		return -1;
}

char* strchr(char* src,char c)
{
	int i;
	for(i=0;i<strlen(src);i++)
	{
		if(src[i] == c)
			return &src[i];
	}
	return NULL;
}

int main(void)
{
	char str[] = "Welcome!";
	char cpy[50];

	printf("String length of \"Welcome!\" is %d\n",strlen(str));
	printf("String copy of \"Welcome!\" is %s\n",strcpy(cpy,str));
	printf("Copy of %d len is %s\n",5,strncpy(cpy,str,5));
	printf("Attaching of two strings is %s\n",strcat(cpy,str));
	//cpy[0] = 'a';
 	printf("Compare of two strings is %d\n",strcmp(cpy,str));
	printf("Sercha of %c is %s\n",'e',strchr(cpy,'e'));
	return 0;
}
