#include "binary_trees.h"

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	measure_balance(&root_a);
	return (root_a);
}

/**
 * measure_balance - Measures balance factor of a AVL
 * @tree: tree root node
 * Return: balanced factor
 */
void measure_balance(avl_t **tree)
{
	int balance_val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	measure_balance(&(*tree)->left);
	measure_balance(&(*tree)->right);
	balance_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 *take_away_node - function that removes a node depending of its children
 *@root_node: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root_node)
{
	int new_node_val = 0;

	if (!root_node->left && !root_node->right)
	{
		if (root_node->parent->right == root_node)
			root_node->parent->right = NULL;
		else
			root_node->parent->left = NULL;
		free(root_node);
		return (0);
	}
	else if ((!root_node->left && root_node->right) || (!root_node->right && root_node->left))
	{
		if (!root_node->left)
		{
			if (root_node->parent->right == root_node)
				root_node->parent->right = root_node->right;
			else
				root_node->parent->left = root_node->right;
			root_node->right->parent = root_node->parent;
		}
		if (!root_node->right)
		{
			if (root_node->parent->right == root_node)
				root_node->parent->right = root_node->left;
			else
				root_node->parent->left = root_node->left;
			root_node->left->parent = root_node->parent;
		}
		free(root_node);
		return (0);
	}
	else
	{
		new_node_val = successor(root_node->right);
		root_node->n = new_node_val;
		return (new_node_val);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root_node: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root_node, int value)
{
	int type = 0;

	if (root_node == NULL)
		return (NULL);
	if (value < root_node->n)
		bst_remove(root_node->left, value);
	else if (value > root_node->n)
		bst_remove(root_node->right, value);
	else if (value == root_node->n)
	{
		type = remove_type(root_node);
		if (type != 0)
			bst_remove(root_node->right, type);
	}
	else
		return (NULL);
	return (root_node);
}

/**
 * get_successor - get the next successor in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int get_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = get_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}