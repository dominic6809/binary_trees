#include "binary_trees.h"

/**
 * array_to_heap - function that Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: A Pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t n;
	heap_t *root = NULL;

	if (array != NULL)
	{
		for (n = 0; n < size; n++)
		{
			heap_insert(&root, *(array + n));
		}
	}
	return (root);
}
