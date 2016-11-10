#include "matx.h"

void matprint(float (*arr)[COL]){
	putchar('\n');
	for(int i=0;i<ROW;i++){
		putchar('\t');
		putchar('|');
		for(int j=0;j<COL;j++)
			printf("%7.2f",arr[i][j]);
		putchar('|');
		putchar('\n');
	}
	putchar('\n');
}
void unitMatMaker(float (*E)[COL]){
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			if(i==j)
				E[i][j]=1;
			else
				E[i][j]=0;
		}
	}
}//단위백터 생성 함수

void matscan(float(*arr)[COL]){
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			printf("input array [%d][%d]:",i+1,j+1);
			scanf("%f",&arr[i][j]);
		}
	}
}
//행렬 입력 함수

void mrowChange(float (*arr)[COL],float (*E)[COL],int r1, int r2){
	if(r1<0 || r1>ROW-1 || r2<0 || r2>ROW-1){	
		printf("row input error");
		return;
	}
	int temp[COL],Etemp[COL];
	for(int i=0;i<COL;i++){
		temp[i] =arr[r1][i];
		Etemp[i] = E[r1][i];
	}
	for(int i=0;i<COL;i++){
		arr[r1][i]=arr[r2][i];
		E[r1][i] =E[r2][i];
	}
	for(int i=0;i<COL;i++){
		arr[r2][i]=temp[i];
		E[r2][i]=Etemp[i];
	}
	printf("Row Change %d to %d\n", r1+1,r2+1);
	matprint(arr);
}
//행 교환 함수 (+단위행렬)

void mrowOp(float (*arr)[COL],float (*E)[COL],int r1, float n, int r2){
	if(r1<0 || r1>ROW-1 || r2<0 || r2>ROW-1){	
		printf("row input error");
		return;
	}
	for(int i=0;i<COL;i++){
		arr[r2][i]+=arr[r1][i]*n;
		E[r2][i]+=E[r1][i]*n;
		arr[r2][i]=roundf(arr[r2][i]*100)/100;
		E[r2][i]=roundf(E[r2][i]*100)/100;
	}
	printf("\nRow OP row %d <- row %d * %.2f\n",r2+1,r1+1,n);
	matprint(arr);
}
//행 연산 함수

void ZeroRowChanger(float (*arr)[COL],float (*P)[COL],int l){
	int cnt=0;//0 counter
	for(int j=0;j<ROW-1;j++){
		for(int i=j+l; i<ROW-1; i++){
			if(cnt==(COL-1))
				break;
			if(arr[i][l]<0.001 && arr[i][l]>(-0.001)){
				mrowChange(arr,P,i,i+1);
				cnt++;
			}
			
		}//0 정렬
	}	
}

void PivotOp(float(*arr)[COL],float (*E)[COL],int i, int j){
	for(int k=i+1;k<ROW;k++){
		if(arr[k][j]>0.001 || arr[k][j]<(-0.001)){
			printf("pivot arr[%d][%d]\n",i+1,j+1);
			mrowOp(arr,E,i,-(arr[k][j]/arr[i][j]),k);

		}
	}
	
}//피봇 설정 함수

void LUconvert(float (*arr)[COL],float (*E)[COL],float (*P)[COL]){
		
	for(int i=0,j=0;i<ROW&&j<COL;i++,j++){
		ZeroRowChanger(arr,P,j);
		if(arr[i][j]>0.001 || arr[i][j]<(-0.001))
			PivotOp(arr,E,i,j);
		else
			PivotOp(arr,E,i,++j);
	}
	
}

