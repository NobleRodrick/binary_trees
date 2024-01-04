#include "binary_trees.h"

/**
 * binary_tree_nodes - functions gives us the list of nodes with atleast
 * one child on the binary tree
 * @tree: pointer to root of tree.
 *
 * Return: 0 if tree is null, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node_count = 0;

	if (tree)
	{
		node_count += (tree->left || tree->right) ? 1 : 0;
		node_count += binary_tree_nodes(tree->left);
		node_count += binary_tree_nodes(tree->right);
	}
	return (node_count);
}
