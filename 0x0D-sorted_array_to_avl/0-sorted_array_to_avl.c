#include "binary_trees.h"

/**
 * sorted_array_to_avl - turns array into AVL tree
 * @array: array to convert
 * @size: size of the array
 * Return: head of tree NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avl_t *tree = NULL;

	if (size < 1 || array == NULL)
		return (NULL);

	i = add_nodes(array, size, &tree, 1);
	if (i)
		return (NULL);
	return (tree);
}

/**
 * add_nodes - adds nodes from array to avl tree
 * @array: list of sorted values to insert
 * @size: size of the array
 * @tree: tree to insert into
 * @add_left: 1 if adding value to left of tree or 0 if right
 * Return: 0 if passed -1 if failed
 */
int add_nodes(int *array, size_t size, avl_t **tree, int add_left)
{
	size_t halfway = (size - 1) / 2;
	avl_t *node = NULL;
	int i = 0;

	if (array == NULL || size < 1)
		return (0);

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (-1);
	node->n = array[halfway];
	node->parent = (*tree);
	node->left = NULL;
	node->right = NULL;
	if ((*tree) == NULL)
		(*tree) = node;
	else if (add_left)
		(*tree)->left = node;
	else
		(*tree)->right = node;
	i = add_nodes(array, halfway, &node, 1);
	if (i == -1)
		return (-1);
	halfway++;
	i = add_nodes(&array[halfway], size - halfway, &node, 0);
	if (i == -1)
		return (-1);
	return (0);
}
