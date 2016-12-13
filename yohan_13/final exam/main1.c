#include <stdio.h>

int a = 1;

int extern_function(void);
int static_fucntion(void);

int main(void){
	auto int b=2;
	register int c=3;
	printf("%3d\n", extern_function());
	printf("%3d%3d%3d\n", a,b,c);
	static_function();
	static_function();
	return 0;
}
