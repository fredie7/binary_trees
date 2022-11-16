#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle of a node
 * @node: node to find the uncle of
 * Return: uncle of node or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - find the sibling of a node
 * @node: node to find the sibling of
 * Return: sibling of node or NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->right == node)
		return (node->parent->left);
	return (node->parent->right);
}
