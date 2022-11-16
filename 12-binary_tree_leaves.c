#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in tree
 * @tree: pointer to the root of the tree
 * Return: number of leaves or 0 if NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
