#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in tree
 * @node: pointer node to measure
 * Return: depth of node, 0 if NULL
 */

size_t binary_tree_depth(const binary_tree_t *node)
{
	int count;

	if (node == NULL)
		return (0);
	for (count = 0; node->parent != NULL; node = node->parent)
		count++;
	return (count);
}
