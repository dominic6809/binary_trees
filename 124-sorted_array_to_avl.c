#include "binary_trees.h"

/**
 * create_avl_node - function that Creates a new AVL node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the newly created node
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * sorted_array_to_avl_recursive - function that Builds
 * an AVL tree from a sorted array recursively
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl_recursive(int *array, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;
	avl_t *root = create_avl_node(NULL, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = sorted_array_to_avl_recursive(array, start, mid - 1);
	root->right = sorted_array_to_avl_recursive(array, mid + 1, end);

	if (root->left != NULL)
		root->left->parent = root;
	if (root->right != NULL)
		root->right->parent = root;

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_recursive(array, 0, size - 1));
}
