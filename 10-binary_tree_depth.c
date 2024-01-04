#include "binary_trees.h"

/**
 * binary_tree_depth - fuction to measure the depth of a node in bt.
 * @tree: poiter to the node.
 *
 * Return: 0 of tree is null, else return depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
