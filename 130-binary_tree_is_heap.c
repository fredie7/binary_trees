#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if binary tree is a max binary heap
 * @tree: pointer to root node of tree
 *
 * Return: 1 if valid max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (heap_check(tree->left, tree->n, binary_tree_size(tree), 1) &&
			heap_check(tree->right, tree->n, binary_tree_size(tree), 2));
}

/**
 * heap_check - recursively checks if tree is a max heap
 * @tree: pointer to root of tree
 * @max: maximum value node can have to be valid
 * @size: number of nodes in tree
 * @index: current index of node
 *
 * Return: 1 if valid max heap, 0 otherwise
 */
int heap_check(const binary_tree_t *tree, int max, size_t size, size_t index)
{
	if (tree == NULL)
		return (1);
	if (index >= size || tree->n > max)
		return (0);
	return (heap_check(tree->left, tree->n, size, index * 2 + 1) &&
			heap_check(tree->right, tree->n, size, index * 2 + 2));
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
