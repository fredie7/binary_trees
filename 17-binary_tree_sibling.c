i#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
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
