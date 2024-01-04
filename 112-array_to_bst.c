#include "binary_trees.h"

/**
 * array_to_bst - function builds for us a binary tree from an array
 * @array: pointer to first element of target array.
 * @size: the lenght of the array
 *
 * Return: root node of created tree, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t a, b;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (bst_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
