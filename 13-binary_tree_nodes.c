#include "binary_trees.h"

/**
 * binary_tree_nodes - count number of nodes with at least 1 child
 * @tree: pointer to root of tree
 * Return: number of nodes with at least on child, or 0 if NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
