#include "bst.h"

void insert(node* newNode) {
	if (search(newNode->key) != NULL) {
		printf("%d is exist\n", newNode->key);
		exit(1);
	}

	if (tree->root == NULL) {
		Root = newNode;
	}
	else {
		node* temp = Root;
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
}

void delete(int key) {
//	node* delNode = search(key);
//	node* repNode = delNode->left_child;
//	node* lefNode;

	if(search(key) == NULL) {
		printf("%d is not exist\n",key);
		exit(1);
	}
	else {
		node* delNode = search(key);
		node* repNode;
		node* lefNode;
		if (HaveZeroChild(delNode)) {
			if (cmp(delNode->parent, delNode)) {
				delNode->parent->left_child = NULL;
				delNode->parent = NULL;
			}
			else {
				delNode->parent->right_child = NULL;
				delNode->parent = NULL;
			}
		}
		else if (HaveTwoChild(delNode)) {	
			repNode = delNode->left_child;
			while(repNode->right_child != NULL) {
				MoveRight(repNode);
			}			
			
			if (repNode->left_child != NULL) {
				lefNode = repNode->left_child;
				while(lefNode->left_child != NULL) {
					MoveLeft(lefNode);
				}
			}
			else {
				lefNode = repNode;
			}

			if (delNode == Root) {
				repNode->parent->right_child = NULL;
				repNode->right_child = delNode->right_child;
				repNode->parent =  delNode->parent;
				lefNode->left_child = delNode->left_child;
				
				Root = repNode;
				delNode->left_child->parent = repNode;
				delNode->right_child->parent = repNode;
			}
			else if (delNode->left_child == repNode || delNode->right_child == repNode ) {
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
			else {
				repNode->parent->right_child = NULL;
				repNode->right_child = delNode->right_child;
				lefNode->left_child = delNode->left_child;
				repNode->parent = delNode->parent;
				
				
				delNode->left_child->parent = lefNode;
				delNode->right_child->parent = repNode;
				
				if (cmp(delNode->parent,delNode)) {
					delNode->parent->left_child = repNode;
				}
				else {
					delNode->parent->right_child = repNode;
				}
			}
		}
		else {
			if (delNode->left_child != NULL) {
				delNode->left_child->parent = delNode->parent;
				if (cmp(delNode->parent,delNode)) {
					delNode->parent->left_child = delNode->left_child;
				}
				else {
					delNode->parent->right_child = delNode->left_child;
				}
			}
			else {
				delNode->right_child->parent = delNode->parent;
				if (cmp(delNode->parent,delNode)) {
					delNode->parent->left_child = delNode->right_child;
				}
				else {
					delNode->parent->right_child = delNode->right_child;
				}
			}
		}
		delNode->parent = NULL;
		delNode->left_child = NULL;
		delNode->right_child = NULL;
	}
}

node* search(int key) {
	node* search_node = Root;
	if (Root == NULL) {
		return NULL;
	}
	else {
		while (search_node != NULL) {
			if (search_node->key == key) {
				return search_node;
			}
			else if(search_node->key > key) {
				MoveLeft(search_node);
			}
			else {
				MoveRight(search_node);
			}
		}
		return NULL;
	}
}	
	
		
void inorder(node* node) {
	if(node->left_child != NULL) {
		inorder(node->left_child);
	}
	printf("%d ", node->key);
	if(node->right_child != NULL) {
		inorder(node->right_child);
	}
}

node* get_root() {
	node* temp = Root;
	return temp;
}
	
