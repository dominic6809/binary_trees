#include "binary_trees.h"

/**
 * array_to_bst - function that Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST,
 * or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t n;

	if (array == NULL || size == 0)
		return (NULL);

	for (n = 0; n < size; n++)
	{
		bst_insert(&root, array[n]);
	}
	return (root);
}
