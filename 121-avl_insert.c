#include "binary_trees.h"

/**
 * avl_insert - function that Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the
 * AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
        if (tree == NULL)
                return NULL;

        if (*tree == NULL)
        {
                *tree = (avl_t *)binary_tree_node(NULL, value);
                return *tree;
        }

        avl_t *new_node = NULL;

        if (value < (*tree)->n)
        {
                (*tree)->left = avl_insert(&((*tree)->left), value);
                if ((*tree)->left == NULL)
                        return NULL;
                (*tree)->left->parent = *tree;
                new_node = *tree;
        }
        else if (value > (*tree)->n)
        {
                (*tree)->right = avl_insert(&((*tree)->right), value);
                if ((*tree)->right == NULL)
                        return NULL;
                (*tree)->right->parent = *tree;
                new_node = *tree;
        }
        else
        {
                return NULL;
        }

        int balance = binary_tree_balance(*tree);

        if (balance > 1 && value < (*tree)->left->n)
                return (avl_t *)binary_tree_rotate_right(*tree);

        if (balance < -1 && value > (*tree)->right->n)
                return (avl_t *)binary_tree_rotate_left(*tree);

        if (balance > 1 && value > (*tree)->left->n)
        {
                (*tree)->left = binary_tree_rotate_left((*tree)->left);
                return (avl_t *)binary_tree_rotate_right(*tree);
        }

        if (balance < -1 && value < (*tree)->right->n)
        {
                (*tree)->right = binary_tree_rotate_right((*tree)->right);
                return (avl_t *)binary_tree_rotate_left(*tree);
        }

        return new_node;
}
