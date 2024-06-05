#include "binary_trees.h"

/* Function Prototypes */
bst_t *bst_remove(bst_t *root, int value);
avl_t *avl_remove(avl_t *root, int value);
int successor(bst_t *node);
void bal(avl_t **tree);
int remove_variant(bst_t *root);

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: pointer to the root of the tree.
 * @value: The value to remove in the tree.
 *
 * Return: The tree with the node removed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int var = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		var = remove_variant(root);
		if (var != 0)
			bst_remove(root->right, var);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after
 * removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_avl = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_avl == NULL)
		return (NULL);

	bal(&root_avl);

	return (root_avl);
}

/**
 * successor - Gets the next successor (minimum value) in the right subtree.
 * @node: pointer to the tree to check.
 *
 * Return: The minimum value in the right subtree.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);

	left = successor(node->left);
	if (left == 0)
		return (node->n);

	return (left);
}

/**
 * bal - Balances an AVL tree.
 * @tree: double pointer to the tree to balance.
 */
void bal(avl_t **tree)
{
	int bal_factor_avl;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	bal(&(*tree)->left);
	bal(&(*tree)->right);

	bal_factor_avl = binary_tree_balance((const binary_tree_t *)*tree);
	if (bal_factor_avl > 1)
		*tree = (avl_t *)binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bal_factor_avl < -1)
		*tree = (avl_t *)binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * remove_variant - Removes a node depending on its children.
 * @root: Node to remove.
 *
 * Return: 0 if it has no children, or the new value if it has children.
 */
int remove_variant(bst_t *root)
{
	int new_val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;

			root->right->parent = root->parent;
		}
		else
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;

			root->left->parent = root->parent;
		}

		free(root);
		return (0);
	}
	else
	{
		new_val = successor(root->right);
		root->n = new_val;
		return (new_val);
	}
}
