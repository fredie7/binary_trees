#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on tree
 * @tree: pointer to tree to rotate
 *
 * Return: pointer to new root of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	new = tree->right;
	new->parent = tree->parent;
	tree->parent = new;
	tree->right = new->left;
	if (tree->right != NULL)
		tree->right->parent = tree;
	new->left = tree;
	return (new);
}
