#include "binary_trees.h"

/* Function prototypes */
int heap_extract(heap_t **root);
void enqueue_item_4(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item);
heap_t *dequeue_item_4(heap_t **queue_h,
	heap_t **queue_t, int *n);
void swap_tree_node_with_parent_1(heap_t **node, heap_t **root);
heap_t *get_last_heap_node(const heap_t *root);

/**
 * heap_extract - Extracts the root node of a max binary heap tree
 * @root: A pointer to the address of the tree's root node.
 *
 * Return: The value of the extracted node, otherwise NULL.
 */
int heap_extract(heap_t **root)
{
	heap_t *node, *node_lt, *node_rt, *tmp, *dummy;
	int value = 0, val_lt, val_rt;

	if ((root != NULL) && (*root != NULL))
	{
		node = *root;
		node_lt = node->left;
		node_rt = node->right;
		value = node->n;
		tmp = get_last_heap_node(node);
		*root = ((tmp != NULL) && (tmp->parent != NULL) ? tmp : NULL);
		if ((tmp != NULL) && (tmp->parent != NULL))
		{
			if (tmp->parent->left == tmp)
				tmp->parent->left = NULL;
			if (tmp->parent->right == tmp)
				tmp->parent->right = NULL;
			tmp->parent = NULL;
			tmp->left = (node_lt != tmp ? node_lt : NULL);
			tmp->right = (node_rt != tmp ? node_rt : NULL);
			if ((node_lt != NULL) && (node_lt != tmp))
				node_lt->parent = tmp;
			if ((node_rt != NULL) && (node_rt != tmp))
				node_rt->parent = tmp;
			while (tmp != NULL)
			{
				val_lt = tmp->left != NULL ? tmp->left->n : tmp->n;
				val_rt = tmp->right != NULL ? tmp->right->n : tmp->n;
				dummy = val_lt > val_rt ? tmp->left : tmp->right;
				if ((dummy != NULL) && (dummy->n > dummy->parent->n))
					swap_tree_node_with_parent_1(&dummy, root);
				else
					break;
			}
		}
		free(node);
	}
	return (value);
}

/**
 * enqueue_item_4 - Adds an item to a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 * @item: The item to add to the queue.
 */
void enqueue_item_4(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item)
{
	heap_t *new_link;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		new_link = malloc(sizeof(heap_t));
		if (new_link == NULL)
			return;
		new_link->left = *queue_t;
		new_link->right = NULL;
		new_link->n = (item != NULL ? ((heap_t *)item)->n : -1);
		new_link->parent = (heap_t *)item;
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
 * dequeue_item_4 - Removes an item from a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 *
 * Return: The value of the removed queue.
 */
heap_t *dequeue_item_4(heap_t **queue_h,
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
 * swap_tree_node_with_parent_1 - function to Swaps a node in a
 * max binary heap tree with its parent.
 * @node: A pointer to the node's address.
 * @root: A pointer to the root of the tree.
 * Return: swapped max nodes
 */
void swap_tree_node_with_parent_1(heap_t **node, heap_t **root)
{
	heap_t *node_copy, *pt, *val0, *lt, *rt;

    /* swap from the right, then swap from the left */
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

/**
 * get_last_heap_node - function that Gets the last level order node
 * in a max binary heap tree.
 * @root: The root of the max binary heap tree.
 *
 * Return: A pointer to the last level order node, otherwise NULL.
 */
heap_t *get_last_heap_node(const heap_t *root)
{
	heap_t *head = NULL, *tail = NULL;
	heap_t *last_node = NULL, *current = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item_4(&head, &tail, &n, (void *)root);
		while (n > 0)
		{
			current = head;
			if (current->parent != NULL)
			{
				last_node = current->parent;
				if (current->parent->left != NULL)
				{
					enqueue_item_4(&head, &tail, &n,
						(void *)(current->parent->left));
				}
				if (current->parent->right != NULL)
				{
					enqueue_item_4(&head, &tail, &n,
						(void *)(current->parent->right));
				}
			}
			dequeue_item_4(&head, &tail, &n);
		}
		while (n > 0)
			dequeue_item_4(&head, &tail, &n);
	}
	return (last_node);
}
