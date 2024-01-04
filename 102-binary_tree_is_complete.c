#include "binary_trees.h"

/**
 * binary_tree_is_complete - function checks
 *     whether a binary tree is complete
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *begining, *end;
	unsigned char signal = 0;

	if (tree == NULL)
		return (0);

	begining = end = node_creation((binary_tree_t *)tree);
	if (begining == NULL)
		exit(1);

	while (begining != NULL)
	{
		if (begining->node->left != NULL)
		{
			if (signal == 1)
			{
				free_queue(begining);
				return (0);
			}
			push(head->node->left, begining, &end);
		}
		else
			signal = 1;
		if (begining->node->right != NULL)
		{
			if (signal == 1)
			{
				free_queue(begining);
				return (0);
			}
			push(begining->node->right, begining, &end);
		}
		else
			signal = 1;
		pop(&begining);
	}
	return (1);
}

/**
 * node_creation -  function creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *node_creation(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @begining: A double pointer to the head of the queue.
 * @end: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *begining,
		levelorder_queue_t **end)
{
	levelorder_queue_t *new_node;

	new_node = node_creation(node);
	if (new_node == NULL)
	{
		free_queue(begining);
		exit(1);
	}
	(*end)->next = new_node;
	*end = new_node;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp_val;

	temp_val = (*head)->next;
	free(*head);
	*head = temp_val;
}