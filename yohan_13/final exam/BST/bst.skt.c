#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	/* Define node */
	struct tnode *left;
	struct tnode *right;
	char val;	
} tnode;

typedef struct tree{
	/* Define tree */
	tnode *root;
} tree;

tnode* newtnode(char);
tree* newtree();
tnode* getRoot(tree*);
void inorder(tnode*);
void preorder(tnode*);
void postorder(tnode*);
void insert(tree*, tnode* );

int main(int argc, char const *argv[]){
	tree* t = newtree();
	char a[10] = {'G','D','I','B','F','H','J','A','C','E'};
	int i;
	for(i = 0; i<10;i++){
		insert(t, newtnode(a[i]));
	}
	inorder(getRoot(t));
	preorder(getRoot(t));
	postorder(getRoot(t));
	return 0;
}
void insert(tree *t,tnode *tnode){
	tnode* current = t->root;
	tnode* parent = current;
	if(t->root == NULL){
		t->root = tnode;
	}else{
		while(1){
			parent = current;
			if(tnode->val < current->val){
			current = current->left;
				if(current == NULL){
					parent->left = tnode;
					return;
				}else{
					current = current->right;
					if(current == NULL){
						parent->right = tnode;
						return;
				}
			}
		}	
	}		
}
void preorder(tnode *t){
	if(t!=NULL){
		printf("Node val : %c\n",t->val);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(tnode *t){
	if(t!=NULL){
		inorder(t->left);
		printf("node key : %c\n",t->val);
		inorder(t->right);
	}
}
void postorder(tnode *t){
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		printf("node key : %c\n",t->val);
	}
}

tnode* newtnode(char val){
	tnode *newtnode = (tnode*)malloc(sizeof(tnode));
	newtnode->val = val;
	return newtnode;
}
tnode* getRoot(tree *t){
	tnode *temp = tree->root;
	return temp;
}
tree* newtree(){
	tree* temp;
	temp->root = NULL;
	return temp;
}
