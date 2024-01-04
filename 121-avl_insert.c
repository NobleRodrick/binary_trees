#include "binary_trees.h"

/**
 * avl_insert - funtion inserts valueninto avl tree.
 * @tree: A double pointer to root of avl tree
 * @value: value to be inserted.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	recursive_insertion(tree, *tree, &new_node, value);
	return (new);
}

/**
 * the_height - will measure the height of a binary tree.
 * @tree: pointer to root node.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t the_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_most = 0, right_most = 0;

		left_most = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_most = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left_most > right_most) ? left_most : right_most);
	}
	return (0);
}

/**
 * give_balance_factor - measure the balance factor of a binary tree.
 * @tree: pointer to the root node
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int give_balance_factor(const binary_tree_t *tree)
{
	return (tree != NULL ? the_height(tree->left) - the_height(tree->right) : 0);
}

/**
 * recursive_insertion - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *recursive_insertion(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = recursive_insertion(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = recursive_insertion(&(*tree)->right, *tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance_factor = give_balance_factor(*tree);
	if (balance_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}