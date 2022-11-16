#include "binary_trees.h"

/**
 * binary_tree_is_complete - check if binary tree is complete
 * @tree: pointer to root of tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (complete_rec(tree, binary_tree_size(tree), 0));
}

/**
 * complete_rec - recursively check if binary tree is complete
 * @tree: pointer to root of tree
 * @size: size of tree
 * @index: current index of node
 *
 * Return: 1 if complete, 0 otherwise
 */
int complete_rec(const binary_tree_t *tree, size_t size, size_t index)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (complete_rec(tree->left, size, index * 2 + 1) &&
			complete_rec(tree->right, size, index * 2 + 2));
}

/**
 * binary_tree_size - calculates the size of the tree
 * @tree: pointer to root of tree
 *
 * Return: size of tree or 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->right) + binary_tree_size(tree->left));
}
