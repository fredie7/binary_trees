#include "binary_trees.h"

/**
 * sorted_array_to_avl - create an AVL tree from a sorted array
 * @array: sorted array
 * @size: size of array
 *
 * Return: pointer to root of AVL tree or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (array == NULL || size == 0)
		return (NULL);
	tree = NULL;
	return (create_avl(array, &tree, 0, size - 1));
}

/**
 * create_avl - creates an AVL tree from a sorted array
 * @array: sorted array
 * @tree: double pointer to root of tree
 * @start: start of array
 * @end: end of array
 *
 * Return: pointer to root of AVL tree or NULL
 */
avl_t *create_avl(int *array, avl_t **tree, size_t start, size_t end)
{
	size_t mid;

	if (tree == NULL)
		return (NULL);
	if (start > end)
		return (*tree);
	if (start == end)
	{
		if (*tree == NULL)
			*tree = avl_insert(tree, array[start]);
		else
			avl_insert(tree, array[start]);
		return (*tree);
	}

	mid = (end - start) / 2 + start;
	avl_insert(tree, array[mid]);
	create_avl(array, tree, start, mid - 1);
	create_avl(array, tree, mid + 1, end);
	return (*tree);
}

/**
 * avl_insert - inserts a node into AVL tree
 * @tree: double pointer to root of tree
 * @value: value to insert into tree
 *
 * Return: pointer to new node or NULL if fail
 */
avl_t *avl_insert(avl_t **tree, int value)
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
		return (avl_insert(&((*tree)->left), value));
	}
	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		return (avl_insert(&((*tree)->right), value));
	}
	return (NULL);
}
