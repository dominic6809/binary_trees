#include "binary_trees.h"

/* Function Prototypes */
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array
 * @array: Pointer to the sorted array
 * @size: Size of the sorted array
 *
 * Return: AVL tree created from the sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)size) - 1));
}

/**
 * aux_sort - Creates the tree using the middle element of the array
 * @parent: Parent of the node to create
 * @array: Sorted array
 * @begin: Starting position of the array
 * @last: Ending position of the array
 *
 * Return: Tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *base;
	binary_tree_t *ax;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		ax = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (ax == NULL)
			return (NULL);
		base = (avl_t *)ax;
		base->left = aux_sort(base, array, begin, mid - 1);
		base->right = aux_sort(base, array, mid + 1, last);
		return (base);
	}
	return (NULL);
}
