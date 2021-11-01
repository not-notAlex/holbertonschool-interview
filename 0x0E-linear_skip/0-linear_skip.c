#include "search.h"

/**
 * linear_skip - searches a skip list for value
 * @list: list to search through
 * @value: value to search for
 * Return: first node with value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *min = list, *max;

	if (list == NULL)
		return (NULL);
	max = list->express;
	while (max)
	{
		printf("Value checked at index [%lu] = [%d]\n", max->index, max->n);
		if (value == max->n)
		{
			return max;
		}
		if (max->n > value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", min->index, max->index);
			break;
		}
		min = max;
		max = max->express;
	}
	while (min)
	{
		printf("Value checked at index [%lu] = [%d]\n", min->index, min->n);
		if (min->n == value)
		{
			return min;
		}
		min = min->next;
	}
	return (NULL);
}
