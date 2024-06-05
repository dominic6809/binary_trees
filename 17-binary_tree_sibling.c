#include "binary_trees.h"

/**
 * binary_tree_sibling - function that Finds the sibling of a node
 * @node: A Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if node is NULL,
 * parent is NULL, or node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
		(node->parent->left == NULL && node->parent->right == NULL))
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
