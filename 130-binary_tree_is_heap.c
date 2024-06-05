#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
 * is_complete_tree - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * @index: Current index of the node in the complete binary tree.
 * @node_count: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_tree(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_tree(tree->left, 2 * index + 1, node_count) &&
		is_complete_tree(tree->right, 2 * index + 2, node_count));
}

/**
 * is_max_heap - Checks if a binary tree is a max heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->n < tree->left->n)
		return (0);

	if (tree->right && tree->n < tree->right->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count;

	if (tree == NULL)
		return (0);

	node_count = binary_tree_size(tree);
	return (is_complete_tree(tree, 0, node_count) && is_max_heap(tree));
}
