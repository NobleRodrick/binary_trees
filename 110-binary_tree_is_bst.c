#include "binary_trees.h"
#include "limits.h"

/**
 * binary_tree_is_bst - function to checks if a binary tree is
 * a valid binary search tree.
 * @tree: pointer to root nde of target tree
 *
 * Return: 1 in success, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_valid_tree(tree, INT_MIN, INT_MAX));
}

/**
 * is_valid_tree - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited
 * @max: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_valid_tree(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (is_valid_tree(tree->left, min, tree->n - 1) &&
			is_valid_tree(tree->right, tree->n + 1, max));
	}
	return (1);
}