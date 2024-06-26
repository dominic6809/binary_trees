#include "binary_trees.h"

/* Function prototype */
int *heap_to_sorted_array(heap_t *heap, size_t *size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * heap_to_sorted_array - Creates a sorted array from a max binary heap tree.
 * @heap: pointer to the max binary heap.
 * @size: pointer to the resulting array's size value.
 *
 * Return: A pointer to the array, otherwise NULL.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	heap_t *root;
	int val;
	size_t n = 0;

	if (heap != NULL)
	{
		root = heap;
		while (root != NULL)
		{
			val = heap_extract(&root);
			array = _realloc(array, sizeof(int) * n, sizeof(int) * (n + 1));
			*(array + n) = val;
			n++;
		}
	}
	if (size != NULL)
		*size = n;
	return (array);
}

/**
 * _realloc - function that Reallocates a memory block
 * @ptr: The pointer to the previous memory block
 * @old_size: The size of the old memory block
 * @new_size: The size of the new memory block
 *
 * Return: The pointer to the new memory block otherwise NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ref;
	unsigned int min_size = old_size < new_size ? old_size : new_size;
	unsigned int n;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL)
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
		new_ref = malloc(new_size);
		if (new_ref != NULL)
		{
			for (n = 0; n < min_size; n++)
				*((char *)new_ref + n) = *((char *)ptr + n);
			free(ptr);
			return (new_ref);
		}
		free(ptr);
		return (NULL);
	}
	else
	{
		new_ref = malloc(new_size);
		return (new_ref);
	}
}
