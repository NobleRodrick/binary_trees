#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures the balance
 * factor of a binary tree
 * @tree: pointer to root node of the target tree
 *
 * Return: 0 if tree is null, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - function to measure the height of the tree
 * @tree: pointer to root node.
 *
 * Return: 0 if tree pointer points null, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft = 0, rght = 0;

		lft = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rght = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lft > rght) ? lft : rght);
	}
	return (0);
}
