#include "binary_trees.h"

/**
 * bst_search - search for value in a BST
 * @tree: pointer to root of tree
 * @value: value to search for
 *
 * Return: pointer to node if found, NULL otherwise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));
	return (NULL);
}
