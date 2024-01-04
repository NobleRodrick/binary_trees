#include "binary_trees.h"

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root_node;
	size_t middle;

	root_node = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);

	middle = (size % 2 == 0) ? mid_point - 1 : mid_point;

	root_node = binary_tree_node(root_node, array[mid_point]);

	create_tree(&root_node, array, mid_point, 1);
	create_tree(&root_node, array + mid_point + 1, (size - 1 - mid_point), 2);

	return (root_node);
}

/**
 * create_avl_tree - function creates an avl tree using recursion
 *
 * @node: points to begining node
 * @array: the inputted array
 * @size: array size
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return value
 */
void create_avl_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t mid_point;

	if (size == 0)
		return;

	mid_point = (size / 2);
	mid_point = (size % 2 == 0) ? mid_point - 1 : mid_point;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid_point]);
		create_avl_tree(&((*node)->left), array, mid_point, 1);
		create_avl_tree(&((*node)->left), array + mid_point + 1, (size - 1 - mid_point), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid_point]);
		create_avl_tree(&((*node)->right), array, mid_point, 1);
		create_avl_tree(&((*node)->right), array + mid_point + 1, (size - 1 - mid_point), 2);
	}
}