#include "bitree.h"

void bitree_init(BiTree *tree, void (*destroy)(void *data))
{
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;
}

static int create_newnode(BiTreeNode **node, const void *data)
{
	(*node) = (BiTreeNode *)malloc(sizeof(BiTreeNode));

	if (NULL == (*node))
		return -1;

	(*node)->data	= (void *)data;
	(*node)->left	= NULL;
	(*node)->right	= NULL;

	return 0;
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *newNode;

	if (-1 == create_newnode(&newNode, data))
		return -1;

	if (NULL == node && 0 != bitree_size(tree)) {
		return -1;
	} else if (NULL == node && 0 == bitree_size(tree)) {
		tree->root = newNode;
	} else if (NULL != node && NULL == bitree_left(node)) {
		node->left = newNode;
	} else if (NULL != node && NULL != bitree_left(node)) {
		return -1;
	}

	++tree->size;

	return 0;
}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *newNode;

	if (-1 == create_newnode(&newNode, data))
		return -1;

	if (NULL == node && 0 != bitree_size(tree))
		return -1;
	else if (NULL == node && 0 == bitree_size(tree))
		tree->root = newNode;
	else if (NULL != node && NULL == bitree_left(node))
		node->left = newNode;
	else if (NULL != node && NULL != bitree_left(node))
		return -1;

	++tree->size;

	return 0;
}
