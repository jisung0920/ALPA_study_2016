#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int input();
void print(char*,char*,char*);
int main()
{	
	int user,com;
	char str[5],str1[5],str2[20];
	srand( (unsigned int)time (NULL));
	///////////////////////////////
	com = (rand()%3)+1;
	if(com==1)
		strcpy(str,"바위");
	else if(com==2)
		strcpy(str,"가위");
	else
		strcpy(str,"보");
	//////////////////////////////

	user = input();	//입력받음
	if(user ==1)
		strcpy(str1,"바위");
	else if (user==2)
		strcpy(str1,"가위");
	else
		strcpy(str1,"보");

	//////////////////////////////
	
	if(com==user)
		strcpy(str2,"비겼습니다");
	else if( ((com == 1)&&(user ==3)) || ((com == 2) && (user ==1)) || ((com ==3) && (user ==2)))
		strcpy(str2,"당신이 이겼습니다");
	else
		strcpy(str2,"당신이 졌습니다");

	print(str1,str,str2);
	return 0;
}
int input(){
	int i =1,num;
	while(i!=0){
		printf("#바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
		scanf("%d",&num);
		if( (num==1) || (num==2) || (num==3) )	i=0;
	}
	return num;
}
void print(char *str1, char *str,char *str2){
	printf("당신은 %s선택, 컴퓨터는 %s 선택 : %s\n",str1,str,str2);
}
