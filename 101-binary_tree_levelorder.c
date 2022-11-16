#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse through tree using level-order traversal
 * @tree: pointer to root of tree
 * @func: pointer to function to use on nodes
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *start;
	queue_t *temp;
	queue_t *end;

	if (tree == NULL || func == NULL)
		return;
	start = malloc(sizeof(queue_t));
	end = start;
	start->tnode = tree;
	start->next = NULL;
	while (tree != NULL)
	{
		func(tree->n);
		if (tree->left != NULL)
		{
			end->next = malloc(sizeof(queue_t));
			if (end->next == NULL)
				return;
			end = end->next;
			end->tnode = tree->left;
			end->next = NULL;
		}
		if (tree->right != NULL)
		{
			end->next = malloc(sizeof(queue_t));
			if (end->next == NULL)
				return;
			end = end->next;
			end->tnode = tree->right;
			end->next = NULL;
		}
		temp = start;
		start = start->next;
		if (start != NULL)
			tree = start->tnode;
		else
			tree = NULL;
		free(temp);
	}

}
