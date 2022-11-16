#include "binary_trees.h"
#include <stdio.h>

/**
 * avl_insert - inserts a node into AVL tree
 * @tree: double pointer to root of tree
 * @value: value to insert into tree
 *
 * Return: pointer to new node or NULL if fail
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *next;
	int balance;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	new = NULL;
	if ((*tree)->n > value)
	{
		next = (*tree)->left;
		if (next == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		new = avl_insert(&next, value);
	}
	if ((*tree)->n < value)
	{
		next = (*tree)->right;
		if (next == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		new = avl_insert(&next, value);
	}
	if (new != NULL)
	{
		balance = binary_tree_balance(*tree);
		if (balance > 1)
			balance_left(tree, next);
		else if (balance < -1)
			balance_right(tree, next);
	}
	return (new);
}

/**
 * balance_left - makes left side AVL balanced
 * @tree: double pointer to tree
 * @next: pointer to next node
 *
 * Return: pointer to root
 */
avl_t *balance_left(avl_t **tree, avl_t *next)
{
	avl_t *parent;

	parent = (*tree)->parent;
	if (binary_tree_balance(next) < 0)
	{
		(*tree)->left = binary_tree_rotate_left(next);
		(*tree)->left->parent = *tree;
	}
	if (parent != NULL)
	{
		if (parent->n < (*tree)->n)
		{
			parent->right = binary_tree_rotate_right(*tree);
			parent->right->parent = parent;
		}
		else
		{
			parent->left = binary_tree_rotate_right(*tree);
			parent->left->parent = parent;
		}
	}
	else
		*tree = binary_tree_rotate_right(*tree);
	return (*tree);
}

/**
 * balance_right - makes right side AVL balanced
 * @tree: double pointer to tree
 * @next: pointer to next node
 *
 * Return: pointer to root
 */
avl_t *balance_right(avl_t **tree, avl_t *next)
{
	avl_t *parent;

	parent = (*tree)->parent;
	if (binary_tree_balance(next) > 0)
	{
		(*tree)->right = binary_tree_rotate_right(next);
		(*tree)->right->parent = *tree;
	}
	if (parent != NULL)
	{
		if (parent->n < (*tree)->n)
		{
			parent->right = binary_tree_rotate_left(*tree);
			parent->right->parent = parent;
		}
		else
		{
			parent->left = binary_tree_rotate_left(*tree);
			parent->left->parent = parent;
		}
	}
	else
		*tree = binary_tree_rotate_left(*tree);
	return (*tree);
}
