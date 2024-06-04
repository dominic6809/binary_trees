#include "binary_trees.h"

/**
 * array_to_avl - function that Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t x, y;
	avl_t *base = NULL;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&base, array[x]) == NULL)
				return (NULL);
		}
	}

	return (base);
}
