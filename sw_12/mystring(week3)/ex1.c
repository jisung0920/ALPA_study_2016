#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strlen		\n전까지의 string의 길이									반환값 : int
//strcpy		strcpy(a,b) 시 b를 a로 복사해준다.							반환값 : null로 종결되는 a의 포인터
//strncpy		strncpy(a,b,n) n개의 문자를 b에서 a로 복사해준다.			반환값 : null로 종결되는 a의 포인터
//strcat		strcat(a,b) a와 b를 붙여준다								반환값 : 문자열
//strcmp		strcmp(a,b) a와 b의 첫번째 문자부터 차례로 비교				반환값 : a=b :0, a>b :+, a<b :-
//strchr		char *strchr(const char *str, int chr) str에서 chr를 찾음	반환값 : 포인터를 반환, 못찾으면 NULL을 반환

char *my_strchr(char *str, int chr)
{
	while(*str)
	{
		if(*str == (char)chr)
			return str;
		str++;
	}
	return NULL;
}

int my_strcmp(char *a,char *b)
{
	int i;
	for(i=0; i<my_strlen(a); i++)
	{
		if(a[i]>b[i])
			return 1;
		else if(a[i] == b[i])
			return 0;
		else
			return -1;
	}
}

char *my_strcat(char *a, char *b)
{
	int alen = my_strlen(a);
	int blen = my_strlen(b);
	int i;
	for(i=0; i<blen; i++)
	{
		a[i+alen] = b[i];
	}
	a[blen+alen] = '\0';
	return a;
}

int my_strlen(char *input)
{
	int cnt = 0;
	while(input[cnt]) {cnt++;}
	return cnt;
}

char *my_strcpy(char *to, char*from)
{
	int cnt = 0;
	while(from[cnt])
	{
		to[cnt] = from[cnt];
		cnt++;
	}
	to[cnt+1] = '\0';
	return to;
}

char *my_strncpy(char *to, char *from, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		to[i] = from[i];
	}
	to[i+1] = '\0';
	return to;
}

int main(void)
{
	char a[8] = "01234";
	char b[8] = "01234";
	char *input =b;

	//string function...
	printf("a[8] = %s\n",a);
	printf("strlen(a) = %d\n", strlen(a));
	printf("strcpy(a,'12345') = %s\n", strcpy(a,"12345"));
	printf("strncpy(a,'123456789',5) = %s\n", strncpy(a,"123456789",5));
	printf("strcat(a,'67') = %s\n", strcat(a,"67"));
	printf("strcmp(a,1234567) = %d\n", strcmp(a,"1234567"));
	printf("strcmp(a,1234568) = %d\n", strcmp(a,"1234568"));
	printf("strcmp(a,1234566) = %d\n", strcmp(a,"1234566"));
	printf("strchr(a,'2')=%s\n", strchr(a,'2'));
	printf("--------------------------------------------------------\n");


	//my string function...
	printf("b[8] = %s\n",b);
	printf("strlen(b) = %d\n", my_strlen(b));
	printf("strcpy(b,'12345') = %s\n", my_strcpy(b,"12345"));
	printf("strncpy(b,'123456789',5) = %s\n", strncpy(b,"123456789",5));
	printf("strcat(b,'67') = %s\n", my_strcat(b,"67"));
	printf("strcmp(b,1234567) = %d\n", strcmp(b,"1234567"));
	printf("strcmp(b,1234568) = %d\n", strcmp(b,"1234568"));
	printf("strcmp(b,1234566) = %d\n", strcmp(b,"1234566"));
	printf("strchr(b,'2')=%s\n", strchr(b,'2'));
	printf("--------------------------------------------------------\n");
	return 0;
}
