#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of the tree
 * @tree: pointer to root of tree
 * Return: size of tree or 0 if NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->right) + binary_tree_size(tree->left));
}
