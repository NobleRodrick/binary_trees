#include "binary_trees.h"

/**
 * binary_tree_rotate_right - does right rotation to a binary tree
 * @tree: ppointer to root node
 *
 * Return: root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *piv, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	piv = tree->left;
	temp = piv->right;
	piv->right = tree;
	tree->left = temp;
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
