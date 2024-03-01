#include "binary_trees.h"

/**
 * is_heap_util - Helper function to recursively check if a binary tree is a valid Max Binary Heap
 * @tree: The binary tree to check
 * @val: The value to compare with node values
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int is_heap_util(const binary_tree_t *tree, int val)
{
    if (tree == NULL)
        return (1);

    if (tree->n > val)
        return (0);

    return (is_heap_util(tree->left, tree->n) && is_heap_util(tree->right, tree->n));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: The binary tree to check
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_heap_util(tree, tree->n) && binary_tree_is_complete(tree));
}

