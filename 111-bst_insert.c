#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent, *current, *new_link;

	if (tree == NULL)
		return (NULL);

	parent = NULL;
	current = *tree;

	/* Find the parent node for the new value */
	while (current != NULL)
	{
		if (value == current->n)
			return (NULL);
		parent = current;
		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	new_link = binary_tree_node(parent, value);
	if (new_link == NULL)
		return (NULL);

	/* Insert the new node */
	if (parent == NULL)
		/* Tree is empty, new node becomes root */
		*tree = new_link;
	else if (value < parent->n)
		parent->left = new_link;
	else
		parent->right = new_link;

	return (new_link);
}
