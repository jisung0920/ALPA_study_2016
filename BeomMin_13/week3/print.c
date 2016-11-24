#include "str.h"

void print_str(char* str1, char* str2) {
	printf("str1 : %s\nstr2 : %s\n", str1, str2);
}

void print_strlen(char* str) {
	puts("print strlen");
	printf("str : %s\nstrlen : %d\n", str, mystrlen(str));
}

void print_strcpy(char* str1, char* str2) {
	puts("print strcpy");
	print_str(str1, str2);
	puts("result");
	mystrcpy(str1, str2);
	print_str(str1, str2);
}

void print_strncpy(char* str1, char* str2, int n) {
	puts("print strncpy");
	print_str(str1, str2);
	puts("result");
	mystrncpy(str1, str2, n);
	print_str(str1, str2);
}

void print_strcat(char* str1, char* str2) {
	puts("print strcat");
	print_str(str1, str2);
	puts("result");
	mystrcat(str1, str2);
	print_str(str1, str2);
}

void print_strcmp(char* str1, char* str2) {
	puts("print strcmp");
	print_str(str1, str2);
	if (!mystrcmp(str1, str2)) {
		puts("same");
	}
	else {
		puts("diffrent");
	}
}

void print_strchr(char* str, int c) {
	puts("print strchr");
	printf("str : %s\n",str);
	puts("result");
	puts(mystrchr(str, c));
}
