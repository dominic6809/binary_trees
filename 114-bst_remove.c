#include "binary_trees.h"

/**
 * find_min_value - Finds the minimum value node in a BST
 * @node: Pointer to the root node of the subtree to search
 *
 * Return: Pointer to the node containing the minimum value
 */
bst_t *find_min_value(bst_t *node)
{
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree where the node will be removed
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		/* Node with two children: Get the in-order successor */
		temp = find_min_value(root->right);

		/* Copy the in-order successor's content to this node */
		root->n = temp->n;

		/* Delete the in-order successor */
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
