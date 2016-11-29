#include "bst.h"

void insert(int key, int data) {
	node* newNode = make_node(key, data);
	if (search(newNode->key) != NULL) {
		printf("%d is exist\n", newNode->key);
		exit(1);
	}

	if (root == NULL) {
		root = newNode;
	}
	else {
		node* temp = root;
		search_insert_space(temp, newNode);
	}
}

void delete(int key) {
	if(search(key) == NULL) {
		printf("%d is not exist\n",key);
		exit(1);
	}
	else {
		node* delNode = search(key);
		node* repNode;
		//node* lefNode;
		if (HaveZeroChild(delNode)) {
			zero_deletion(delNode);
		}
		else if (HaveTwoChild(delNode)) {	
			repNode = delNode->left_child;
			repNode = search_replace_node(repNode);			
			
			//lefNode = left_node_of_replace_node(repNode, lefNode);

			if (delNode == root) {
				two_deletion_root(delNode, repNode);			
			}
			else if (delNode->left_child == repNode || delNode->right_child == repNode ) {
				two_deletion_replace_node(delNode, repNode);
			}
			else {
				two_deletion_middle(delNode, repNode);
			}
		}
		else {
			if (delNode->left_child != NULL) {
				one_deletion_left(delNode);
			}
			else {
				one_deletion_right(delNode);
			}
		}
		init_delete_node(delNode);
	}
}

node* search(int key) {
	node* search_node = root;
	if (root == NULL) {
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
	return root;
}
	
