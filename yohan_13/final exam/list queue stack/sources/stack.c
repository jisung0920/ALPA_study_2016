#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"
typedef struct stack{
	int size;
	struct node* top;
}stack;
/* Define 'stack' using typedef and struct.
	stack has top, size */

/* Prototypes */
stack* init_stack();
void push(stack*, node*);
void pop(stack*);
int top(stack*);
void print_stack(stack*);

int main(int argc, char const *argv[]) {
	int i;
	stack* s = init_stack();
	push(s, newnode(1));
	printf("top : %d\n", top(s));
	pop(s);
	pop(s);
	for (i = 2; i < 6; i++) {
		push(s, newnode(i));
	}
	pop(s);
	print_stack(s);
	for (i = 0; i < 3; i++){
	pop(s);
	}
	top(s);
	return 0;
}
stack* init_stack(){
	stack* temp = (stack*)malloc(sizeof(stack));
	temp ->top =NULL;
	temp->size=0;
	return temp;
}
void push(stack* stack, node* newnode){
	if(stack->size ==0){
		stack->top = newnode;
		stack->size ++;
	}else{
		newnode->next = stack->top;
		stack->top = newnode;
		stack->size ++;
	}
}
void pop(stack* stack){
	if(stack->size <1){
		printf("pop() : stack is empty.\n");
		return;
	}
	else{
		if(stack->size ==1){
			node* temp = stack->top;
			stack->size--;
			free(temp);
			return;
		}else{
		node* temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
		stack->size--;
		}
	}
}
int top(stack* stack){
	if(stack->size < 1){
		printf("top() : stack is empty.\n");
		return -1;
	}
		return stack->top->val;
}
void print_stack(stack* stack){
	int i;
	node* temp = stack->top;
	printf("TOP\n");
	for(i=0; i<stack->size;i++){
		printf("[%d]\n",temp->val);
		temp = temp->next;
	}
	putchar('\n');
}
