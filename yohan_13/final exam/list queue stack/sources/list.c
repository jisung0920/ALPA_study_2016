#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"
typedef struct list{
	int size;
	struct node* head;
}list;
/* Define  'list' using typedef and struct.
	queue has head, and size */

/* Prototypes */
list* init_list();
void appendTo(list* list, node* newnode);
void delAt(list* list, int n);
void print_list(list* list);

int main(int argc, char const *argv[]) {
	list* linked = init_list();
	int i;
	for (i = 1; i < 6; i++) {
		appendTo(linked, newnode(i));
	}
	print_list(linked);
	delAt(linked, -1);
	delAt(linked, 5);
	print_list(linked);
	delAt(linked, 3);
	print_list(linked);
	return 0;
}
list* init_list(){
	list* temp = (list*)malloc(sizeof(list));
	temp->head = NULL;
	temp->size = 0;
	return temp;
}
void appendTo(list* list, node* newnode){
	int i;
	node* pointer = list->head;
	if(list->size ==0){
		list->head = newnode;
		list->size++;
		return;
	}else{
	for(i=0;i<list->size-1;i++){
		pointer = pointer->next;
	}
	pointer->next = newnode;
	list->size++;
	}
}

void delAt(list* list, int n){
	if(n<0){
		printf("error\n");
		return;
	}
	else{
		int i;
		node* pointer = list->head;
		for(i=1;i<n-1;i++)
			pointer = pointer->next;
		
		node* temp = pointer->next;
		if(pointer->next->next == NULL){
			free(pointer->next);
			list->size --;
		}else{	
			pointer->next = temp->next;
			free(temp);
			list->size--;
		}
	}
}
void print_list(list* list){
	int i;
	node* pointer = list->head;
	printf("list size : %d \n",list->size);
	for(i=0; i<list->size;i++){
		printf("%d ", pointer->val);
		pointer=pointer->next;
	}
	putchar('\n');
}
