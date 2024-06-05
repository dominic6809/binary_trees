#include "binary_trees.h"

/**
 * array_to_heap - Creates a max binary heap tree from an array.
 * @array: Pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap,
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
