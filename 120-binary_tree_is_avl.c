#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_avl - checks if binary tree is an AVL tree
 * @tree: pointer to root of tree
 *
 * Return: 1 if AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_check(tree, INT_MIN, INT_MAX));
}

/**
 * avl_check - check if binary tree is AVL
 * @tree: pointer to root of tree
 * @min: local minimum
 * @max: local maximum
 *
 * Return: 1 if AVL tree, 0 otherwise
 */
int avl_check(const binary_tree_t *tree, int min, int max)
{
	int balance;

	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	return (avl_check(tree->left, min, tree->n) &&
			avl_check(tree->right, tree->n, max));
}

/**
 * binary_tree_balance - calculates the balance factor of tree
 * @tree: pointer to root of tree
 *
 * Return: balance factor of tree or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - measures height of tree
 * @tree: pointer to root of tree
 *
 * Return: height of tree, -1 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lsum;
	size_t rsum;

	if (tree == NULL)
		return (0);
	lsum = binary_tree_height(tree->left);
	rsum = binary_tree_height(tree->right);
	if (lsum > rsum)
		return (lsum + 1);
	return (rsum + 1);
}
