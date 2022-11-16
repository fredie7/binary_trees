#include "binary_trees.h"

/**
 * binary_tree_height - measures height of a binary tree
 * @tree: pointer to root of tree
 * Return: height of tree or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lsum;
	size_t rsum;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	lsum = binary_tree_height(tree->left);
	rsum = binary_tree_height(tree->right);
	if (lsum > rsum)
		return (lsum + 1);
	return (rsum + 1);
}
