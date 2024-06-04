#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that Inserts a node
 * as the right-child of another node
 * 
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 * or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* If parent already has a right-child */
    if (parent->right != NULL)
    {
        new_node->right = parent->right;
        /* Set the current right child's parent to the new node */
        parent->right->parent = new_node;
    }

    /* Set the parent's right child to the new node */
    parent->right = new_node;

    return (new_node);
}
