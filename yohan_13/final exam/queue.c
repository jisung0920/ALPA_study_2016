#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

/* Define  'queue' using typedef and struct.
	queue has front, rear, and size */

/* Prototypes */
queue* init_queue();
void enqueue(queue*, node*);
void dequeue(queue*);
int front(queue*);
void print_queue(queue*);


int main(int argc, char const *argv[]){
	int i;
	queue* q = init_queue();
	enqueue(q, newnode(1));
	printf("front : %d\n", front(q));
	dequeue(q);
	dequeue(q);
	for(i = 2; i<6;i++){
		enqueue(q, newnode(i));
	}
	dequeue(q);
	print_queue(q);
	for(i = 0; i<3;i++) dequeue(q);
	front(q);
	return 0;
}
