#include "binary_trees.h"
#include "limits.h"

size_t bst_height(const binary_tree_t *tree);
int check_validity(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * check_validity - Checks if a binary tree is a valid AVL tree.
 * @tree: pointer to root node
 * @min: The value of the smallest node visited thus far.
 * @max: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int check_validity(const binary_tree_t *tree, int lo, int hi)
{
	size_t lft, rgt, diff;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		lft = bst_height(tree->left);
		rgt = bst_height(tree->right);
		diff = lft > rgt ? lft - rgt : rgt - lft;
		if (diff > 1)
			return (0);
		return (check_validity(tree->left, min, tree->n - 1) &&
			check_validity(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * height - height measure of a binary search tree
 * @tree: target root  node pointer
 *
 * Return: 0 if tree is NULL, else return height.
 */
size_t bst_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_most = 0, right_most = 0;

		left_most = tree->left ? 1 + height(tree->left) : 1;
		right_most = tree->right ? 1 + height(tree->right) : 1;
		return ((left_most > right_most) ? left_most : right_most);
	}
	return (0);
}

/**
 * binary_tree_is_avl - function checks if a binary tree is a valid AVL tree.
 * @tree: root node to target tree
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_validity(tree, INT_MIN, INT_MAX));
}