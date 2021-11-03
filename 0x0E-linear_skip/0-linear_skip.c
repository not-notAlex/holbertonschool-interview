#include "search.h"

/**
 * linear_skip - searches a skip list for value
 * @list: list to search through
 * @value: value to search for
 * Return: first node with value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *i = list, *x;

	if (list == NULL)
		return (NULL);
	x = list->express;
	while (x)
	{
		printf("Value checked at index [%lu] = [%d]\n", x->index, x->n);
		if (value == x->n)
			break;
		if (x->n > value)
		{
			break;
		}
		if (x->express == NULL)
		{
			i = x;
			while (x->next)
				x = x->next;
			break;
		}
		i = x;
		x = x->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", i->index, x->index);
	while (i)
	{
		printf("Value checked at index [%lu] = [%d]\n", i->index, i->n);
		if (i->n == value)
			return (i);
		i = i->next;
	}
	return (NULL);
}
