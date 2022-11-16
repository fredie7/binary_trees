#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to root of tree
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
