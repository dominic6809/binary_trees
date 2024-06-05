#include "binary_trees.h"

/**
 * binary_tree_uncle - function that Finds the uncle of a node
 * @node: A Pointer to the node to find the uncle
 *
 * Return: A Pointer to the uncle node,
 * or NULL if node is NULL or has no uncle
 *
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent == node->parent->parent->left)
	{
		/* If uncle exists (right child of grandparent), return it */
		if (node->parent->parent->right != NULL)
			return (node->parent->parent->right);
	}
	else
	{
		/* If uncle exists (left child of grandparent), return it */
		if (node->parent->parent->left != NULL)
			return (node->parent->parent->left);
	}

	return (NULL);
}
