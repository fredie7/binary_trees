#include "binary_trees.h"

/**
 * array_to_bst - converts an array to a BST
 * @array: array to convert
 * @size: size of array
 *
 * Return: pointer to root of BST, or NULL if fail
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree;

	if (array == NULL || size == 0)
		return (NULL);

	tree = NULL;
	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
