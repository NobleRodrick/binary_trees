#include "binary_trees.h"

/**
 * binary_tree_height - function to measure the height of the binary tree
 * @tree: The tree whoes height we are to measure
 *
 * Return: 0 in the tree is null, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft = 0;
		size_t rght = 0;

		lft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rght = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((lft > rght) ? lft : rght);
	}
	return (0);
}
