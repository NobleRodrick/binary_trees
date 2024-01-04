#include "binary_trees.h"

/**
 * binary_tree_leaves - function to count the leaves in a binary tree
 * @tree: pointer to target tree root.
 *
 * Return: leaf number.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_number = 0;

	if (tree)
	{
		leaf_number += (!tree->left && !tree->right) ? 1 : 0;
		leaf_number += binary_tree_leaves(tree->left);
		leaf_number += binary_tree_leaves(tree->right);
	}
	return (leaf_number);
}
