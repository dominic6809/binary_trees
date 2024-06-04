#include "binary_trees.h"

/**
 * sorted_array_to_bst - function that Recursively builds a
 * Binary Search Tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *sorted_array_to_bst(int *array, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;
	bst_t *root = binary_tree_node(NULL, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = sorted_array_to_bst(array, start, mid - 1);
	root->right = sorted_array_to_bst(array, mid + 1, end);

	return (root);
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
