#include "bst.h"

node* make_node (int key, int data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->key = key;
	newNode->data = data;
	return newNode;
}
