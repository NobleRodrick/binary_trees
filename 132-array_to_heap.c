#include "binary_trees.h"

/**
 * array_to_heap - function builds a max binary heap from array
 * @array: a pointer to the first array element
 * @size: the length/number of elements in the array
 *
 * Return: pointer to heap tree
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int a;
	heap_t *root_node = NULL;

	for (a = 0; a < size; a++)
		heap_insert(&root_node, array[a]);

	return (root_node);
}