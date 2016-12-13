#include <stdio.h>

#define N 7

main(void)
{
	prn_heading();
	prn_tbl_of_powers(N);
	return 0;
}

prn_heading(void){
	printf("\n::::: A TABLE OF POWERS :::::\n\n");
}

void prn_tbl_of_powers(n)
double n;{
	printf("(sizeof N is %d, int:4, double:8)\n", sizeof(n));
	int i,j;
	for(i=1;i<=n;++j)
		for(j=1;j<=n;++j)
			if(j==1)
				printf("%ld",power(i,j));
			else
				printf("%9ld",power(i,j));
		putchar('\n');
	}
}

long power(int m, int n){
	int i;
	m = 199, n =10;
	long product = 1;
	for(i=1;i<=n;++i)
		product *= m;
	return product;
}

