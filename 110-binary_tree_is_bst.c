#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - checks if binary tree is a BST
 * @tree: pointer to root of tree
 *
 * Return: 1 if is a BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * bst_check - check if binary tree is BST
 * @tree: pointer to root of tree
 * @min: local minimum
 * @max: local maximum
 *
 * Return: 1 if is a BST, 0 otherwise
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (bst_check(tree->left, min, tree->n) &&
			bst_check(tree->right, tree->n, max));
}
