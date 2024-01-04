#include "binary_trees.h"

/**
 * binary_trees_ancestor - function gives the
 * lowst common ancestor of two nodes
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mama, *papa;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mama = first->parent, papa = second->parent;
	if (first == papa || !mama || (!mama->parent && papa))
		return (binary_trees_ancestor(first, papa));
	else if (mama == second || !papa || (!papa->parent && mama))
		return (binary_trees_ancestor(mama, second));
	return (binary_trees_ancestor(mama, papa));
}
