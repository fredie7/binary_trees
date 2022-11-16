#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree
 * using post-order traversal
 * @tree: pointer to root of tree
 * @func: pointer to function to use on nodes
 * Return: pointer to the new node or NULL if fail
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
