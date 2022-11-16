#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to lowest common ancestor or NULL if fail
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second || first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	if (binary_tree_depth(first) < binary_tree_depth(second))
	{
		ancestor = binary_trees_ancestor(first, second->parent);
		if (ancestor)
			return (ancestor);
		ancestor = binary_trees_ancestor(first->parent, second);
		if (ancestor)
			return (ancestor);
	}
	else
	{
		ancestor = binary_trees_ancestor(first->parent, second);
		if (ancestor)
			return (ancestor);
		ancestor = binary_trees_ancestor(first, second->parent);
		if (ancestor)
			return (ancestor);
	}
	return (NULL);
}

/**
 * binary_tree_depth - measure the depth of a node
 * @node: pointer node to measure
 *
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
