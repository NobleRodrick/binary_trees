#include "binary_trees.h"

/**
 * binary_tree_is_root - function checks whether a node is a root of a binary tree.
 * @node: pointer to our target node
 *
 * Return: 1 If the node is a root.
 *         0 Otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
