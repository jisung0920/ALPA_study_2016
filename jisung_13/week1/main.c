#include "matx.h"

int main(void){

	float ar[ROW][COL];
	float E[ROW][COL];
	float P[ROW][COL];

	unitMatMaker(E);
	unitMatMaker(P);
	
	matscan(ar);
	matprint(ar);
	
	LUconvert(ar,E,P);


	printf("\n----------------------------------------\n");
	printf("	Upper \n");
	matprint(ar);
	printf("	Lower \n");
	matprint(E);
	printf("	P\n");
	matprint(P);
	printf("\n----------------------------------------\n");

	return 0;
}
