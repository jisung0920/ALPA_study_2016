#include "str.h"

void main() {
	char* str1 = (char*)malloc(sizeof(char));
	char* str2 = (char*)malloc(sizeof(char));
	str2 = "Min";
	puts("input string");
	scanf("%s",str1);

	print_strlen(str1);

	print_strcpy(str1, str2);

	print_strncpy(str1, str2, 2);

	print_strcat(str1, str2);

	print_strcmp(str1, str2);

	print_strchr(str2, 'i');
}
