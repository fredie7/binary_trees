#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array to use to build tree
 * @size: size of array
 *
 * Return: pointer to root of new AVL tree or NULL if fail
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);
	tree = NULL;
	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);
	return (tree);
}
