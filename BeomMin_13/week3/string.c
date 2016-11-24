#include "str.h"

int mystrlen(char* str) {
	int cnt = 0;
	int i=0;
	while (str[i] != '\0') {
		cnt++;
		i++;
	}
	return cnt;
}

void mystrcpy(char* str1, char* str2) {
	int i;
	for(i = 0; i < mystrlen(str2); i++){
		str1[i] = str2[i];
	}
	str1[mystrlen(str2)] = '\0';
}

void mystrncpy(char* str1, char* str2, int n) {
	if (n > mystrlen(str2)) {
		puts("ERROR");
		exit(1);
	}	

	int i;
	for(i = 0; i < n; i++) {
		str1[i] = str2[i];
	}
	str1[n] = '\0';
}

void mystrcat(char* str1, char* str2) {
	int i;
	int str1len = mystrlen(str1);
	int catlen = mystrlen(str1) + mystrlen(str2);
	for(i = str1len; i < catlen; i++) {
		str1[i] = str2[i-str1len];
	}
	str1[catlen] = '\0';
}

int mystrcmp(char* str1, char* str2) {
	int i;
	int cnt = 0;	

	for (i = 0; i < mystrlen(str1); i++) {
		if (str1[i] == str2[i]) {
			cnt++;
		}
		else {
			cnt = 0;
		}
	}
	if (cnt == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

char* mystrchr(char* str1, int c) {
	int i=0;
	int cnt=-1;

	while (i < mystrlen(str1)) {
		if (str1[i] == c) {
			cnt = i;
			break;
		}
	i++;
	}
	
	if (cnt == -1) {
		return "No Search";
	}
	else {
		return &str1[cnt];
	}
}
	
