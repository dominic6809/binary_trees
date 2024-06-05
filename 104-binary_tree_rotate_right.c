#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that Performs
 * a right-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *spin;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	spin = tree->left;
	tree->left = spin->right;

	if (spin->right != NULL)
		spin->right->parent = tree;

	spin->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = spin;
		else
			tree->parent->right = spin;
	}

	tree->parent = spin;
	spin->right = tree;

	return (spin);
}
