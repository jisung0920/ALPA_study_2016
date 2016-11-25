#include "bst.h"

void main() {
	
	init_bst();
	int i;
	int key;
	

	insert(make_node(8,8));
	insert(make_node(4,4));
	insert(make_node(11,11));
	insert(make_node(2,2));
	insert(make_node(3,3));
	insert(make_node(1,1));
	insert(make_node(6,6));
	insert(make_node(5,5));
	insert(make_node(7,7));
	insert(make_node(13,13));
	insert(make_node(9,9));
	insert(make_node(10,10));
	insert(make_node(12,12));

	inorder(get_root());
	puts("\n");	
	delete(8);
	inorder(get_root());
	puts("\n");
	delete(5);
	inorder(get_root());
	puts("\n");
	delete(2);
	inorder(get_root());
}
	
