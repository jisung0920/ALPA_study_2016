#include<stdio.h>

int main()
{
	char name[20];
	double height;
	char gender[1];
	printf("# 성명 입력 : ");
	scanf("%s",name);
	printf("# 키 입력(cm) : ");
	scanf("%lf",&height);
	printf("# 성별입력(M/F) : ");
	scanf("%c",gender);
	if(gender != ('M'||'m') | gender!= ('F'|| 'f'))
		printf("다시 입력해주세요\n");
	else if(gender == ('M'||'m'))
		printf("%s씨의 키는 %.1lf이고 남성입니다\n",name,height);
	else
		printf("%s씨의 키는 %.1lf이고 여성입니다\n",name,height);
	
	return 0;
}
