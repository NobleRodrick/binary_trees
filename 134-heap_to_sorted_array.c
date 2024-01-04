#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = size_of_tree(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}

/**
 * size_of_tree - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t size_of_tree(const binary_tree_t *tree)
{
	size_t height_of_left = 0;
	size_t height_of_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_of_left = 1 + size_of_tree(tree->left);

	if (tree->right)
		height_of_right = 1 + size_of_tree(tree->right);

	return (height_of_left + height_of_right);
}