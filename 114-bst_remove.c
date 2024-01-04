#include "binary_trees.h"

/**
 * bst_remove - function to remove node from bst
 * @root: pointer to root node of tree
 * @value: value to be removed
 *
 * Return: pointer to new root node
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_recursively(root, root, value));
}

/**
 * inordr_successor - Returns the minimum value of a binary search tree.
 * @root_node: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inordr_successor(bst_t *root_node)
{
	while (root_node->left != NULL)
		root_node = root_node->left;
	return (root_node);
}

/**
 * delete_bst_node - func delete a node from a binary search tree.
 * @root_node: root node pointer
 * @node: target node.
 *
 * Return: new root node
 */
bst_t *delete_bst_node(bst_t *root_node, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root_node);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root_node);
	}

	/* Two children */
	successor = inordr_successor(node->right);
	node->n = successor->n;

	return (delete_bst_node(root_node, successor));
}

/**
 * remove_recursively - Removes a node from a binary search tree recursively.
 * @root_node: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *remove_recursively(bst_t *root_node, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete_bst_node(root_node, node));
		if (node->n > value)
			return (remove_recursively(root_node, node->left, value));
		return (remove_recursively(root_node, node->right, value));
	}
	return (NULL);
}