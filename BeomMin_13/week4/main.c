#include "bst.h"

void main() {
	
	init_bst();
	int i;
	int key;
	

	insert(8,8);
	insert(4,4);
	insert(11,11);
	insert(2,2);
	insert(3,3);
	insert(1,1);
	insert(6,6);
	insert(5,5);
	insert(7,7);
	insert(13,13);
	insert(9,9);
	insert(10,10);
	insert(12,12);

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
	
