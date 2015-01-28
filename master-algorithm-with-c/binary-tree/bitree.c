#include "bitree.h"
#include <stdio.h>
#include <string.h>

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
	BiTreeNode *newnode;

	if (-1 == create_newnode(&newnode, data))
		return -1;

	if (NULL == node && 0 != bitree_size(tree))
		return -1;
	else if (NULL == node && 0 == bitree_size(tree))
		tree->root = newnode;
	else if (NULL != node && NULL == bitree_left(node))
		node->left = newnode;
	else if (NULL != node && NULL != bitree_left(node))
		return -1;

	++tree->size;

	return 0;
}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *newnode;

	if (-1 == create_newnode(&newnode, data))
		return -1;

	if (NULL == node && 0 != bitree_size(tree))
		return -1;
	else if (NULL == node && 0 == bitree_size(tree))
		tree->root = newnode;
	else if (NULL != node && NULL == bitree_right(node))
		node->right = newnode;
	else if (NULL != node && NULL != bitree_right(node))
		return -1;

	++tree->size;

	return 0;
}

void bitree_destroy(BiTree *tree)
{
	bitree_rem_left(tree, NULL);

	memset(tree, 0, sizeof(BiTree));
}


static void bitree_rem_node(BiTree *tree, BiTreeNode *node)
{
	if (NULL == node)
		return;

	/* printf("rem:%d\n", *((int *)node->data)); */

	if (NULL != node->left)
		bitree_rem_node(tree, node->left);

	if (NULL != node->right)
		bitree_rem_node(tree, node->right);

	if (NULL != node->data && NULL != tree->destroy) {
		/* printf("Destroy:%d\n", *((int *)node->data)); */
		tree->destroy(bitree_data(node));
		node->data = NULL;
	}

	--tree->size;

	free(node);
	node = NULL;
}

void bitree_rem_left(BiTree *tree, BiTreeNode *node)
{
	if (NULL == node) {
		bitree_rem_node(tree, bitree_root(tree));
		tree->root = NULL;
	} else {
		bitree_rem_node(tree, node->left);
		node->left = NULL;
	}
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node)
{
	if (NULL == node) {
		bitree_rem_node(tree, bitree_root(tree));
		tree->root = NULL;
	} else {
		bitree_rem_node(tree, node->right);
		node->right = NULL;
	}
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
	if (-1 == bitree_ins_left(merge, NULL, data))
		return -1;

	merge->root->left = left->root;
	merge->root->right = right->root;
	merge->size += left->size + right->size;

	left->root = NULL;
	left->size = 0;

	right->root = NULL;
	right->size = 0;

	return 0;
}
