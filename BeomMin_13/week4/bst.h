#include <stdio.h>
#include <stdlib.h>

#define cmp(x,y) (x->key) > (y->key)
#define HaveTwoChild(x) (x->left_child != NULL) && (x->right_child != NULL)
#define HaveZeroChild(x) (x->left_child == NULL) && (x->right_child == NULL)
#define Root  tree->root
#define MoveLeft(x) (x) = (x->left_child)
#define MoveRight(x) (x) = (x->right_child)
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
