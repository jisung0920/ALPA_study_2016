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

node* root;

node* make_node(int, int);

void init_bst();

void insert(int, int);
void delete(int);
node* search(int);
void inorder(node*);
node* get_root();

void search_insert_space(node*, node*);
void zero_deletion(node*); // if tree has zero child

node* search_replace_node(node*);
node* left_node_of_replace_node(node*, node*);
void two_deletion_root(node*, node*, node*);
void two_deletion_replace_node(node*, node*);
void two_deletion_middle (node*, node*, node*);

void one_deletion_left (node*);
void one_deletion_right (node*);

void init_delete_node (node*);
