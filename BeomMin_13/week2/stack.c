#include "hanoi.h"



bool isEmpty(STACK* T) {
	if (T->top == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void push(STACK* T, int i) {
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	NewNode->data = i;
	NewNode->next = T->top;
	T->top = NewNode;
}

NODE pop(STACK* T) {
	NODE* PoNode=T->top;
	T->top = PoNode->next;
	return *PoNode;
}


void stackprint(STACK* T) {
	NODE *temp;
	temp = T->top;
	if (temp == NULL) {
		for (int l = 0 ; l < 15; l++) {
			printf(" ");
		}
		printf("empty\n");
	}
	while (temp != NULL) {
		
			
			for (int j = convert_int(*temp); j < 20; j++) {

				printf(" ");
			}
			for (int k = 0; k < (2*convert_int(*temp)-1); k++) {
				printf("*");
			}
		
		printf("\n");

		temp = temp->next;
	}

}
