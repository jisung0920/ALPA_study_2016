#include "myString.h"

int mStrlen(const char* str){
  int cnt=0;
  char c=(*str);
  while(c!='\0'){
    c= *(str+cnt);
    cnt++;
  }
  return cnt-1;
}

char* mStrcpy(const char *str1,char *str2){
  int l,i;
  l=mStrlen(str1);
  for(i=0;i<l;i++)
      *(str2+i)=*(str1+i);
  *(str2+i)='\0';
  return str1;
}     // copy string

char* mStrncpy(const char *str1,char *str2,int n){
  int i,l;
  l=mStrlen(str1);
  if(n>l)
    n=l;
  for(i=0;i<n-1;i++)
      *(str2+i)=*(str1+i);
  *(str2+i)='\0';
  return str1;
}

char* mStrcat(char *str1,const char *str2){
  int l1,l2,i,j=0;
  l1=mStrlen(str1);
  l2=mStrlen(str2);
  for(i=l1;i<(l1+l2);i++)
      *(str1+i)=*(str2+j++);
    *(str1+i)='\0';
  return str1;
}     // add string
int mStrcmp(const char *str1,const char *str2){
  int l1,l2,i;

  l1=mStrlen(str1);
  l2=mStrlen(str2);

  for(i=0;i<l1 && i<l2;i++){
    if(*(str1+i) != *(str2+i))
      break;
    }

  if(*(str1+i) > *(str2+i))
    return -1;
  else if(*(str1+i) < *(str2+i))
    return 1;
  else if(l1==l2)
    return 0;
  else if(l1>l2)
    return 1;
  else
    return -1;
}      // compare string by dic order
const char* mStrchr(const char *str,char c){
  int l;
  l=mStrlen(str);
  for(int i=0;i<l;i++)
    if(*(str+i)==c)//
      return (str+i);
  return NULL;
}       // char searching
