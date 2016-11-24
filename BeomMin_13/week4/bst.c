#include "bst.h"

void insert(node* newNode) {
	if (search(newNode->key) != NULL) {
		printf("%d is exist\n", newNode->key);
		exit(1);
	}

	if (tree->root == NULL) {
		tree->root = newNode;
	}
	else {
		node* temp = tree->root;
		while(1) {
			if (temp->key > newNode->key) {
				if (temp->left_child == NULL) {
					newNode->parent = temp;
					temp->left_child = newNode;
					break;
				}
				else {
					temp = temp->left_child;
				}
			}
			else {
				if (temp->right_child == NULL) {
					newNode->parent = temp;
					temp->right_child = newNode;
					break;
				}
				else {
					temp= temp->right_child;
				}
			}
		}
	}
}

void delete(int key) {
	node* delNode = search(key);
	node* repNode = delNode->left_child;
	node* lefNode;

	if(delNode == NULL) {
		printf("%d is not exist",key);
		exit(1);
	}
	else {
		if (delNode->left_child == NULL && delNode->right_child == NULL) {
			if (delNode->parent->key > delNode->key) {
				delNode->parent->left_child = NULL;
				delNode->parent = NULL;
			}
			else {
				delNode->parent->right_child = NULL;
				delNode->parent = NULL;
			}
		}
		else if (delNode->left_child != NULL && delNode->right_child != NULL) {	
			while(repNode->right_child != NULL) {
				repNode = repNode->right_child;
			}			
			
			if (repNode->left_child != NULL) {
				lefNode = repNode->left_child;
				while(lefNode->left_child != NULL) {
					lefNode = lefNode->left_child;
				}
			}
			else {
				lefNode = repNode;
			}

			if (delNode == tree->root) {
				repNode->right_child = delNode->parent;
				repNode->parent =  delNode->parent;
				lefNode->left_child = delNode->left_child;
				tree->root = repNode;
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
				if (delNode->parent->key > delNode->key) {
					delNode->parent->left_child = repNode;
				}
				else {
					delNode->parent->right_child = repNode;
				}
			}
			else {
				repNode->right_child = delNode->right_child;
				lefNode->left_child = delNode->left_child;
				repNode->parent = delNode->parent;
				
				delNode->left_child->parent = lefNode;
				delNode->right_child->parent = repNode;
				
				if (delNode->parent->key > delNode->key) {
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
				if (delNode->parent->key > delNode->key) {
					delNode->parent->left_child = delNode->left_child;
				}
				else {
					delNode->parent->right_child = delNode->left_child;
				}
			}
			else {
				delNode->right_child->parent = delNode->parent;
				if (delNode->parent->key > delNode->key) {
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
	node* search_node = tree->root;
	if (tree->root == NULL) {
		return NULL;
	}
	else {
		while (search_node != NULL) {
			if (search_node->key == key) {
				return search_node;
			}
			else if(search_node->key > key) {
				search_node = search_node->left_child;
			}
			else {
				search_node = search_node->right_child;
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
	node* temp = tree->root;
	return temp;
}
	
