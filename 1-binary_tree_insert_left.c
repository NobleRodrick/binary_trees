#include "binary_trees.h"

/**
 * binary_tree_insert_left - function  will insert a node as a left-child of
 *                       of another in a binary tree.
 * @parent: to be parent of the inserted node.
 * @value: the value that the new node has.
 *
 * Return: Null in case of and error or null parent value
 *         pointer to other node otherwise
 * Description: If parent already has a left-child, the new node
 *       takes its place and the old left-child is set as 
 *        the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
