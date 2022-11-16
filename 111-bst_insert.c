#include "binary_trees.h"

/**
 * bst_insert - inserts a node into a BST
 * @tree: double pointer to root of binary search tree
 * @value: value to add
 *
 * Return: pointer to created node, NULL if fail
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	if ((*tree)->n > value)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		return (bst_insert(&((*tree)->left), value));
	}
	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		return (bst_insert(&((*tree)->right), value));
	}
	return (NULL);
}
