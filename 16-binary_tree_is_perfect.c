#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function that Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	/* A node is a leaf if it has no left and no right children */
	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}

/**
 * binary_tree_height - function that Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	if (l_height >= r_height)
		return (l_height + 1);
	else
		return (r_height + 1);
}

/**
 * binary_tree_is_perfect - function that Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *lt, *rt;

	if (tree == NULL)
		return (0);

	lt = tree->left;
	rt = tree->right;

	if (binary_tree_is_leaf(tree))
		return (1);
	if (lt == NULL || rt == NULL)
		return (0);
	if (binary_tree_height(lt) == binary_tree_height(rt))
	{
		if (binary_tree_is_perfect(lt) && binary_tree_is_perfect(rt))
			return (1);
	}
	return (0);
}
