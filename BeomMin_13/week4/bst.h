#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	int data;
	struct node* left_child;
	struct node* right_child;
	struct node* parent;
}node;

typedef struct {
	node* root;
}bst;

bst* tree;

node* make_node(int, int);

void init_bst();

void insert(node*);
void delete(int);
node* search(int);
void inorder(node*);
node* get_root();
