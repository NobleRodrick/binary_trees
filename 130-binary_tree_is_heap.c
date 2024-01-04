#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid max binary heap
 * @tree: pointer to root node
 * Return: 1 in in success and 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);
	if (!temp)
		return (0);
	return (is_max(tree));
}

/**
 * is_max - goes through a binary tree checking as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int is_max(const binary_tree_t *tree)
{
	int temp1 = 1 temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = is_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = is_max(tree->right);
	}
	return (temp1 && temp2);
}