#include "bitree.h"

void bitree_init(BiTree *tree, void (*destroy)(void *data))
{
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;
}
