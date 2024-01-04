#include "binary_trees.h"

unsigned char leaf_check(const binary_tree_t *node);
size_t specific_depth(const binary_tree_t *tree);
const binary_tree_t *show_leaf(const binary_tree_t *tree);
int perfection_recursive_check(const binary_tree_t *tree,
		size_t leaf_depth, size_t lev);
int binary_tree_is_perfect(const binary_tree_t *tree);


/**
 * specific_depth - Returns the depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t specific_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + specific_depth(tree->parent) : 0);
}

/**
 * show_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *show_leaf(const binary_tree_t *tree)
{
	if (leaf_check(tree) == 1)
		return (tree);
	return (tree->left ? show_leaf(tree->left) : show_leaf(tree->right));
}

/**
 * is_leaf - function checks whether the node is_leaf.
 * @node: pointer to node.
 *
 * Return: 1, and in case of failure, 0.
 */
unsigned char leaf_check(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * perfection_recursive_check - will check if a binary tree is
 * perfect recursively.
 * @tree: root node pointer
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @lev: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int perfection_recursive_check(const binary_tree_t *tree,
		size_t leaf_depth, size_t lev)
{
	if (leaf_check_leaf(tree))
		return (lev == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (perfection_recursive_check(tree->left, leaf_depth, lev + 1) &&
		perfection_recursive_check(tree->right, leaf_depth, lev + 1));
}

/**
 * binary_tree_is_perfect - function checks if a binary tree is perfect.
 * @tree: root node of target tree.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (perfection_recursive_check(tree, specific_depth(show_leaf(tree)), 0));
}
