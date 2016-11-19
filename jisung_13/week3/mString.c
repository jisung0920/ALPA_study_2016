#include "myString.h"

int mStrlen(char* str){
  int cnt=0;
  char c=(*str);
  while(c!='\0'){
    c= *(str+cnt);
    cnt++;
  }
  return cnt-1;
}

void mStrcpy(char *str1, char *str2){
  int l,i;
  l=mStrlen(str1);
  for(i=0;i<l;i++)
      *(str2+i)=*(str1+i);
  *(str2+i)='\0';
}     // copy string

void mStrncpy(char *str1,char *str2,int n){
  int i,l;
  l=mStrlen(str1);
  if(n>l)
    n=l;
  for(i=0;i<n;i++)
      *(str2+i)=*(str1+i);
  *(str2+i)='\0';
}
/*
void mStrcat(char *str1,char *str2){
  int l1,l2,i,j=0;
  l1=mStrlen(str1);
  l2=mStrlen(str2);
  for(i=l1;i<(l1+l2);i++)
      *(str1+i)=*(str2);
    *(str1+i)='\0';
}     // add string
int mStrcmp(char *str1,char *str2){

}      // compare string by dic order
int mStrchr(char *str,char c){
  int l;
  l=mStrlen(str);
  for(int i=0;i<l;i++)
    if(*(str+i)==c)//
      return i;
  return 0;
}       // char searching
*/
