#include <stdio.h>
#include <stdlib.h>
int mStrlen(const char*);           // length of string
void mStrcpy(const char*,char*);     // copy string
void mStrncpy(const char*,char*,int); // copy string
void mStrcat(char*,const char*);     // add string
int mStrcmp(const char*,const char*);      // compare string by dic order
const char* mStrchr(const char*,char);       // char searching
