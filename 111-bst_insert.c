#include "binary_trees.h"

/**
 * bst_insert - function will put a value into the search tree
 * @tree: Is double pointer to the root node of the tree to insert the value.
 * @value: The value we are going to insert in the node.
 *
 * Return: pointer to new node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current_node, *new_node;

	if (tree != NULL)
	{
		current_node = *tree;

		if (current_node == NULL)
		{
			new_node = binary_tree_node(current_node, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}
		
		 /*insert in left subtree */
		if (value < current_node->n)
		{
			if (current_node->left != NULL)
				return (bst_insert(&current_node->left, value));

			new_node = binary_tree_node(current_node, value);
			if (new_node == NULL)
				return (NULL);
			return (current_node->left = new_node);
		}
		/* insert in right subtree */
		if (value > current_node->n)
		{
			if (current_node->right != NULL)
				return (bst_insert(&current_node->right, value));

			new_node = binary_tree_node(current_node, value);
			if (new_node == NULL)
				return (NULL);
			return (curr->right = new_node);
		}
	}
	return (NULL);
}
