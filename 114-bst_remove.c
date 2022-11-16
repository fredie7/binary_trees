#include "binary_trees.h"
#include "stdio.h"

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to root of tree
 * @value: value to remove from tree
 *
 * Return: new root of tree once value is removed, or NULL if fail
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *rem; /* node to remove */

	if (root == NULL)
		return (NULL);
	if (root->n == value)
	{
		rem = root;
		node = find_successor(rem->right);
		if (node == NULL && root->left == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (node == NULL)
		{
			root = root->left;
			root->parent = rem->parent;
			free(rem);
			return (root);
		}
		else if (node->n == root->right->n)
		{
			root = root->right;
			root->parent = rem->parent;
			root->left = rem->left;
			rem->left->parent = root;
			free(rem);
			return (root);
		}
		root->n = node->n;
		root->right = bst_remove(root->right, node->n);
		return (root);
	}
	else if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
		root->right = bst_remove(root->right, value);

	return (root);
}

/**
 * find_successor - finds first in-order successor
 * @root: pointer to root of tree
 *
 * Return: pointer to successor, or NULL if fail
 */
bst_t *find_successor(bst_t *root)
{
	if (root == NULL)
		return (NULL);
	if (root->left == NULL)
		return (root);
	return (find_successor(root->left));
}

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
