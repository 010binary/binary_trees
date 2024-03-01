#include "binary_trees.h"

/**
 * is_heap_util - Helper function to check if a binary tree is a valid Heap
 * @tree: The binary tree to check
 * @val: The value to compare with node values
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int is_heap_util(const binary_tree_t *tree, int val)
{
	if (tree == NULL)
		return (1);

	int left_result = is_heap_util(tree->left, tree->n);
	int right_result = is_heap_util(tree->right, tree->n);

	if (tree->n > val && left_result && right_result)
		return (1);
	else
		return (0);
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

	int heap_result = is_heap_util(tree, tree->n);
	int complete_result = binary_tree_is_complete(tree);

	if (heap_result && complete_result)
		return (1);
	else
		return (0);
}

