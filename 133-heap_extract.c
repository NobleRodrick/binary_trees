#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - takes root node from binary search heap
 * @root: pointer to the heap root
 * Return: extracted node value
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	traverse_preorder(heap_r, &node, binary_tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify_binary_max(heap_r);
	*root = heap_r;
	return (value);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t binary_tree_height(const heap_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * heights_sum - function measures the sum of heights of a binary tree
 * @tree: root node pointer of target tree
 *
 * Return: Height 
 *		0 if tree is NULL
 */
size_t heights_sum(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + heights_sum(tree->left);

	if (tree->right)
		right_height = 1 + heights_sum(tree->right);

	return (left_height + right_height);
}

/**
 * heapify_binary_max - heapifies max binary heap
 * @root_node: pointer to binary heap
 */
void heapify(heap_t *root_node)
{
	int value;
	heap_t *temp1, *temp2;

	if (!root_node)
		return;

	temp1 = root_node;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = value;
		temp1 = temp2;
	}
}

/**
 * traverse_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @tree_height: height of tree
 *
 * Return: No Return
 */
void traverse_preorder(heap_t *tree, heap_t **node, size_t tree_height)
{
	if (!tree)
		return;

	if (!tree_height)
		*node = tree;
	tree_height--;

	traverse_preorder(tree->left, node, height);
	traverse_preorder(tree->right, node, height);
}