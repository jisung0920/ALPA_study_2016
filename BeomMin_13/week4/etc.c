#include "bst.h"

void init_bst() {
	root = (node*)malloc(sizeof(node));
	root = NULL;
}

void search_insert_space(node* temp, node* newNode) {
	while(1) {
			if (cmp(temp,newNode)) {
				if (temp->left_child == NULL) {
					newNode->parent = temp;
					temp->left_child = newNode;
					break;
				}
				else {
					MoveLeft(temp);
				}
			}
			else {
				if (temp->right_child == NULL) {
					newNode->parent = temp;
					temp->right_child = newNode;
					break;
				}
				else {
					MoveRight(temp);
				}
			}
		}
}

void zero_deletion(node* delNode) {
	if (cmp(delNode->parent, delNode)) {
		delNode->parent->left_child = NULL;
		delNode->parent = NULL;
	}
	else {
		delNode->parent->right_child = NULL;
		delNode->parent = NULL;
	}
}
	
node* search_replace_node(node* repNode) {
	while(repNode->right_child != NULL) {
		MoveRight(repNode);
	}
	return repNode;
}

node* left_node_of_replace_node(node* repNode, node* lefNode) {
	if (repNode->left_child != NULL) {
		lefNode = repNode->left_child;
		while(lefNode->left_child != NULL) {
			MoveLeft(lefNode);
		}
	}
	else {
		lefNode = repNode;
	}
	return lefNode;
}

void two_deletion_root(node* delNode, node* repNode) {
	
	if(repNode->left_child != NULL) {	
		repNode->left_child->parent = repNode->parent;
		repNode->parent->right_child = repNode->left_child;
	}
	else {
		repNode->parent->right_child = NULL;
	}
	repNode->left_child = delNode->left_child;
	repNode->right_child = delNode->right_child;
	repNode->parent =  delNode->parent;
//	lefNode->left_child = delNode->left_child;
					
	root = repNode;
	delNode->left_child->parent = repNode;
	delNode->right_child->parent = repNode;
}

void two_deletion_replace_node(node* delNode, node* repNode) {
	if (delNode->left_child == repNode) {
		repNode->right_child = delNode->right_child;
		repNode->parent = delNode->parent;
				
		delNode->right_child->parent = repNode;
	}
	else {
		repNode->left_child = delNode->left_child;
		repNode->parent = delNode->parent;
					
		delNode->left_child->parent = repNode;
	}
	if (cmp(delNode->parent,delNode)) {
		delNode->parent->left_child = repNode;
	}
	else {
		delNode->parent->right_child = repNode;
	}
}

void two_deletion_middle (node* delNode, node* repNode) {
	if (repNode->left_child != NULL) {
	repNode->left_child->parent = repNode->parent;
	repNode->parent->right_child = repNode->left_child;
	}
	else {
		repNode->parent->right_child = NULL;
	}
	repNode->right_child = delNode->right_child;
	repNode->left_child = delNode->left_child;
	//lefNode->left_child = delNode->left_child;
	repNode->parent = delNode->parent;
				
				
	delNode->left_child->parent = repNode;
	delNode->right_child->parent = repNode;
			
	if (cmp(delNode->parent,delNode)) {
		delNode->parent->left_child = repNode;
	}
	else {
		delNode->parent->right_child = repNode;
	}
}

void one_deletion_left (node* delNode) {
	delNode->left_child->parent = delNode->parent;
	if (cmp(delNode->parent,delNode)) {
		delNode->parent->left_child = delNode->left_child;
	}
	else {
		delNode->parent->right_child = delNode->left_child;
	}
}

void one_deletion_right (node* delNode) {
	delNode->right_child->parent = delNode->parent;
	if (cmp(delNode->parent,delNode)) {
		delNode->parent->left_child = delNode->right_child;
	}
	else {
		delNode->parent->right_child = delNode->right_child;
	}
}

void init_delete_node (node* delNode) {	
	delNode->parent = NULL;
	delNode->left_child = NULL;
	delNode->right_child = NULL;
}
