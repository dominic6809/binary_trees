#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Recursively calculate the size of the left subtree */
	size_t left_size = binary_tree_size(tree->left);

	/* Recursively calculate the size of the right subtree */
	size_t right_size = binary_tree_size(tree->right);

	/* Return size of tree as the sum of LST and RST, +1 for current node */
	return (left_size + right_size + 1);
}
