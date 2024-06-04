#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to put in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	return (new_node);
}

/**
 * heapify_up - Maintains the heap property by moving a node up.
 * @node: Pointer to the node to move up.
 *
 * Return: Pointer to the node after moving up.
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * find_insert_position - Finds the position to insert a new node in the heap.
 * @root: Pointer to the root of the heap.
 * @size: Size of the heap.
 *
 * Return: Pointer to the parent node where the new node should be inserted.
 */
heap_t *find_insert_position(heap_t *root, int size)
{
	int path[32];
	int i = 0;

	while (size > 1)
	{
		path[i++] = size % 2;
		size /= 2;
	}
	while (i > 1)
	{
		if (path[--i])
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

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
 * heap_insert - Inserts a value in Max Binary Heap.
 * @root: Double pointer to the root node of the Heap to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;
	int size;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	parent = find_insert_position(*root, size + 1);

	if (parent->left == NULL)
		new_node = parent->left = binary_tree_node(parent, value);
	else
		new_node = parent->right = binary_tree_node(parent, value);

	if (!new_node)
		return (NULL);

	return (heapify_up(new_node));
}
