#include "binary_trees.h"

void binary_tree_levelorder(const struct binary_tree_s *tree,
                            void(*func)(int));
/**
 * binary_tree_levelorder - performs level order traversal of a binary tree
 * @tree: the link to root node
 * return - appropriate value
 */
void binary_tree_levelorder(const struct binary_tree_s *tree,
                            void(*func)(int))
{   
    if(tree == NULL || func == NULL)
        return;

    int height = binary_tree_height(tree);

    for (int i = 1; i <= height; i++)
        binary_tree_traverse_level(tree, i, func);
}

/**
 * binary_tree_heigth - calculates the height of binary tree
 * @tree: root node
 * return - appropriate value
 */
int binary_tree_height(const struct binary_tree_s *tree)
    {
        if(tree == NULL)
            return 0;

        int left_height = binary_tree_height(tree->left);
        int right_height = binary_tree_height(tree->right);

        return 1 + (left_height > right_height ? left_height : right_height);
    }

/**
 * binary_tree_traverse_level - reverses a specific level of the tree
 * @tree: the root node
 * return - depending on user needs
 */
int binary_tree_traverse_level(const struct binary_tree_s *tree,
                            int level, void(*func)(int))
    {
        if(tree == NULL)
            return;

        if(level == 1)
            func(tree->n)
        else if(level > 1)
        {
            binary_tree_traverse_level(tree->left, level - 1, func);
            binary_tree_traverse_level(tree->right, level - 1, func);
        }
    }