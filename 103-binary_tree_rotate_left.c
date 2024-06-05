#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that Performs
 * a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *spin;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	spin = tree->right;
	tree->right = spin->left;

	if (spin->left != NULL)
		spin->left->parent = tree;

	spin->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = spin;
		else
			tree->parent->right = spin;
	}

	tree->parent = spin;
	spin->left = tree;

	return (spin);
}
