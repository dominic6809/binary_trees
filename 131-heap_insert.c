#include "binary_trees.h"

/* Function prototypes */
heap_t *heap_insert(heap_t **root, int value);
void enqueue_item_3(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item);
heap_t *dequeue_item_3(heap_t **queue_h,
	heap_t **queue_t, int *n);
heap_t *get_insert_position(const heap_t *root);
void swap_tree_node_with_parent(heap_t **node, heap_t **root);

/**
 * heap_insert - function that Inserts a value into a max binary heap tree.
 * @root: A pointer to the root of the tree.
 * @value: The value to insert.
 *
 * Return: A pointer to the inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_link = NULL, *parent = NULL;

	if (root != NULL)
	{
		parent = get_insert_position(*root);
		new_link = malloc(sizeof(heap_t));
		if (new_link == NULL)
			return (new_link);
		new_link->left = NULL;
		new_link->right = NULL;
		new_link->parent = parent;
		new_link->n = value;
		if (parent == NULL)
		{
			*root = new_link;
		}
		else
		{
			if (parent->left == NULL)
				parent->left = new_link;
			else
				parent->right = new_link;
			while (new_link->parent != NULL)
			{
				if (new_link->n > new_link->parent->n)
					swap_tree_node_with_parent(&new_link, root);
				else
					break;
			}
		}
	}
	return (new_link);
}

/**
 * enqueue_item_3 - function that Adds an item to a queue.
 * @queue_h: pointer to the queue's head.
 * @queue_t: pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 * @item: The item to add to the queue.
 * Return: item to add to the queue.
 */
void enqueue_item_3(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item)
{
	heap_t *new_link;
	heap_t *node = (heap_t *)item;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		new_link = malloc(sizeof(heap_t));
		if (new_link == NULL)
			return;
		new_link->left = *queue_t;
		new_link->right = NULL;
		new_link->n = (node != NULL ? node->n : -1);
		new_link->parent = node;
		if (*queue_h == NULL)
			*queue_h = new_link;
		if (*queue_t != NULL)
			(*queue_t)->right = new_link;
		*queue_t = new_link;
		if (n != NULL)
			(*n)++;
	}
}

/**
 * dequeue_item_3 - function that Removes an item from a queue.
 * @queue_h: pointer to the queue's head.
 * @queue_t: pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 *
 * Return: The value of the removed queue.
 */
heap_t *dequeue_item_3(heap_t **queue_h,
	heap_t **queue_t, int *n)
{
	heap_t *val0;
	heap_t *val1;
	heap_t *node = NULL;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		val0 = *queue_h;
		if (val0 != NULL)
		{
			node = val0->parent;
			if (val0->right != NULL)
			{
				val1 = val0->right;
				val1->left = NULL;
				*queue_h = val1;
				free(val0);
			}
			else
			{
				free(val0);
				*queue_h = NULL;
				*queue_t = NULL;
			}
			if (n != NULL)
				(*n)--;
		}
	}
	return (node);
}

/**
 * get_insert_position - function that Gets the next available insertion
 * position for a node in a max binary heap tree.
 * @root: The root of the max binary heap tree.
 *
 * Return: The insertion position.
 */
heap_t *get_insert_position(const heap_t *root)
{
	heap_t *head = NULL, *tail = NULL;
	heap_t *parent_node = NULL, *current = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item_3(&head, &tail, &n, (void *)root);
		while (n > 0)
		{
			current = head;
			if (current->parent != NULL)
			{
				if (current->parent->left != NULL)
				{
					enqueue_item_3(&head, &tail, &n,
						(void *)(current->parent->left));
					if (current->parent->right != NULL)
					{
						enqueue_item_3(&head, &tail, &n,
							(void *)(current->parent->right));
					}
					else
					{
						parent_node = current->parent;
						break;
					}
				}
				else
				{
					parent_node = current->parent;
					break;
				}
			}
			dequeue_item_3(&head, &tail, &n);
		}
		while (n > 0)
			dequeue_item_3(&head, &tail, &n);
	}
	return (parent_node);
}

/**
 * swap_tree_node_with_parent - function that Swaps a node in a
 * max binary heap tree with its parent.
 * @node: A pointer to the node's address.
 * @root: A pointer to the root of the tree.
 * Return: maximum swapped nodes, otherwise NULL
 */
void swap_tree_node_with_parent(heap_t **node, heap_t **root)
{
	heap_t *node_copy, *pt, *val0, *lt, *rt;

    /* swaps from the right, and then swaps from the left */
	if ((node != NULL) && ((*node)->parent != NULL) && (root != NULL))
	{
		pt = (*node)->parent, node_copy = *node,
			val0 = (*node)->parent->parent;
		lt = (*node)->left, rt = (*node)->right;
		if ((*node)->parent->left != *node)
		{
			if ((val0 != NULL) && (val0->left == (*node)->parent))
				val0->left = *node;
			if ((val0 != NULL) && (val0->right == (*node)->parent))
				val0->right = *node;
			if ((*node)->parent->left != NULL)
				(*node)->parent->left->parent = node_copy;
			(*node)->parent = val0, (*node)->left =
				pt->left, (*node)->right = pt;
			pt->parent = node_copy, pt->left = lt, pt->right = rt;
		}
		else
		{
			if ((val0 != NULL) && (val0->left == pt))
				val0->left = *node;
			if ((val0 != NULL) && (val0->right == pt))
				val0->right = *node;
			if ((*node)->parent->right != NULL)
				(*node)->parent->right->parent = *node;
			(*node)->parent = val0, (*node)->right =
				pt->right, (*node)->left = pt;
			pt->parent = node_copy, pt->left = lt, pt->right = rt;
		}
		if (lt != NULL)
			lt->parent = pt;
		if (rt != NULL)
			rt->parent = pt;
		if (val0 == NULL)
			*root = node_copy;
	}
}
