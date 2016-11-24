#include "bst.h"

void init_bst() {
	tree = (bst*)malloc(sizeof(bst));
	tree->root = NULL;
}
