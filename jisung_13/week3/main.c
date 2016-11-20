#include "myString.h"
#include <string.h>


int main(void){
  char s1[] = "abcdef";
  char s2[] = "jeongjisung";
  char s3[] = "Hanyang";
  char s4[] = "University";
  char s5[] = "Hello World";

  printf("%s\n",s6);
  printf("function \n");
  printf("strlen \t%lu\t%d\n",strlen(s1),mStrlen(s1));
  mStrcpy(s3,s4);
  printf("strcpy \t%s\t%s\n",s3,s4);

  mStrcat(s1,s2);
  printf("strcat \t%s\n",s1);
  const char *p = mStrchr(s1,'e');
  printf("strchr \t%s find \t%c  :\t%s\n",s1,'e',p);
  int j = mStrcmp(s1,s2);
  printf("strcmp \t%s and \t%s :\t%d\n",s1,s2,j);
  int k = mStrcmp(s4,s5);
  printf("strcmp \t%s and \t%s :\t%d\n",s4,s5,k);

  return 0;
}
