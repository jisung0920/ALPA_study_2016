#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"
typedef struct queue{
	int size;
	struct node* front;
	struct node* back;
}queue;
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
	for(i = 0; i<3;i++){
		dequeue(q);
	}
	front(q);
	return 0;
}
queue* init_queue(){
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->back = NULL;
	temp->size = 0;
	temp->front = NULL;
	return temp;
}
void enqueue(queue* que, node* newnode){
	if(que->size==0){
		que->back = newnode;
		que->front = newnode;
		que->front->next = newnode;
		que->size++;
	}else{
		que->back->next = newnode;
		que->back = que->back->next;
		que->size++;
	}
}
void dequeue(queue* que){
	int i;
	if(que->size<1){
		printf("dequeue() : queue is empty\n");
	}
	else{	
		node* temp = que->front;
		que->front = que->front->next;
		free(temp);
		que->size --;
	}
}
int front(queue* que){
	if(que->size<1){
		printf("front() : queue is empty\n");
		return -1;
	}
	return que->front->val;
}
void print_queue(queue* que){
	int i;
	node* temp = que->front;
	for(i=0; i<que->size;i++){
		printf("[%d] ", temp->val);
		temp=temp->next;
	}
	putchar('\n');
}
