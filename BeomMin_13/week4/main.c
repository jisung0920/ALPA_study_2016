#include "bst.h"

void main() {
	
	init_bst();
	int i;
	int key;
	
	scanf("%d",&key);
	
	for(i = 0; i < key; i++) {
		insert(make_node(i,i));
	}
	
	delete(1);
	inorder(get_root());
}
