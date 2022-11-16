#include "binary_trees.h"
#include <stdio.h>

/**
 * avl_remove - remove a node from an AVL tree
 * @root: pointer to root of tree
 * @value: value to remove
 *
 * Return: pointer to new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node;
	avl_t *rem; /* node to remove */
	int balance;

	if (root == NULL)
		return (NULL);
	if (root->n == value)
	{
		rem = root;
		node = find_successor(rem->right);
		if (node == NULL && root->left == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (node == NULL)
		{
			root = root->left;
			root->parent = rem->parent;
			free(rem);
			return (root);
		}
		else if (node->n == root->right->n)
		{
			root = root->right;
			root->parent = rem->parent;
			root->left = rem->left;
			rem->left->parent = root;
			free(rem);
		}
		root->n = node->n;
		root->right = avl_remove(root->right, node->n);
	}
	else if (root->n > value)
	{
		root->left = avl_remove(root->left, value);
		node = root->left;
	}
	else
	{
		root->right = avl_remove(root->right, value);
		node = root->right;
	}
	balance = binary_tree_balance(root);
printf("balance factor at %d is %d\n", root->n, balance);
	if (balance < -1)
	{
printf("Before balance_left\n");
		binary_tree_print(root);
		balance_left(&root, node);
printf("After balance_left\n");
		binary_tree_print(root);
	}
	else if (balance > 1)
	{
printf("Before balance_right\n");
		binary_tree_print(root);
		balance_right(&root, node);
printf("After\n");
		binary_tree_print(root);
	}
	return (root);
}

/**
 * find_successor - finds first in-order successor
 * @root: pointer to root of tree
 *
 * Return: pointer to successor, or NULL if fail
 */
bst_t *find_successor(bst_t *root)
{
	if (root == NULL)
		return (NULL);
	if (root->left == NULL)
		return (root);
	return (find_successor(root->left));
}
