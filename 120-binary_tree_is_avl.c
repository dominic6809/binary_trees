#include "binary_trees.h"
#include "limits.h"

/**
 * binary_tree_height - Measures the height of a binary tree
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
 * bal_avl - Auxiliar function to compare each subtree if its AVL.
 * @tree: Node that points to the tree to check.
 * @lower: Node that points to the lower node selected.
 * @high: Node that points to the higher node selected.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t l_ht, r_ht, bal;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		l_ht = binary_tree_height(tree->left);
		r_ht = binary_tree_height(tree->right);
		bal = l_ht > r_ht ? l_ht - r_ht : r_ht - l_ht;
		if (bal > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
