#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on tree
 * @tree: pointer to tree to rotate
 *
 * Return: pointer to new root of tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	new = tree->left;
	new->parent = tree->parent;
	tree->parent = new;
	tree->left = new->right;
	if (tree->left != NULL)
		tree->left->parent = tree;
	new->right = tree;
	return (new);
}
