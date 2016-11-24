#include "hanoi.h"
int cnt = 1;
void move(int n,STACK* from, STACK* temp, STACK* to) {
	
	if (n == 1) {
		push(to,convert_int(pop(from)));
		printf("count : %d\n",cnt);
		allstackprint(from,temp,to);
		cnt++;
	}
	else {
		move(n-1,from,to,temp);
		push(to,convert_int(pop(from)));
		printf("count : %d\n",cnt);
		allstackprint(from,temp,to);
		cnt++;
		move(n-1,temp,from,to);
	}
}
