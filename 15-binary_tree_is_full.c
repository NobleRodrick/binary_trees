#include "binary_trees.h"

/**
 * recursive_check - checks if binary tree is full using recursive methods
 * @tree: root node pointer
 *
 * Return: 0, if tree is full
 *         Otherwise, 1.
 */
int recursive_check(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    recursive_check(tree->left) == 0 ||
		    recursive_check(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - function checks if a binary tree is full.
 * @tree: pointer to root node of target tree.
 *
 * Return: If tree is NULL - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_check(tree));
}
