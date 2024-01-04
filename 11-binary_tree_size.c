#include "binary_trees.h"

/**
 * binary_tree_size - function to measure the size of a binary tree
 * @tree: root nod eof the tree.
 *
 * Return: tree size.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t the_size = 0;

	if (tree)
	{
		the_size += 1;
		the_size += binary_tree_size(tree->left);
		the_size += binary_tree_size(tree->right);
	}
	return (the_size);
}
