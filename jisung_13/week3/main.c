#include "myString.h"
#include <string.h>


int main(void){
  char *s1 = "abcdef";
  char *s2 = "jeongjisung";
  char *s3 = "Hanyang";
  char *s4 = "University";
  printf("function \n");
  printf("strlen %10lu %10d\n",strlen(s1),mStrlen(s1));
  mStrcpy(&s1,&s2);
  printf("strcpy %10s %10s\n",s1,s2);
/*
  mStrcat(&s1,&s2);
  printf("strcat %10s\n",s1);
  int i = mStrchr(&s1,'c');
  printf("strchr %s find %c  : %d\n",s1,'c',i);
  int j = mStrcmp(char *s3,char *s4);
  printf("strcmp %s and %s :%d",s3,s4,j);
  printf("");
  */
  return 0;
}
