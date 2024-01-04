#include "binary_trees.h"

/**
 * binary_tree_rotate_left - functiom left-rotates a binary tree.
 * @tree: pointer to root node
 *
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *piv, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	piv = tree->right;
	temp = piv->left;
	piv->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = piv;
	piv->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = piv;
		else
			temp->right = piv;
	}

	return (piv);
}
