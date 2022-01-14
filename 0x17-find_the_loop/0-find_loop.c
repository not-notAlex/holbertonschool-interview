#include "lists.h"

/**
 * find_listint_loop - checks if a linked list has loop
 * @head: list to check
 *
 * Return: 0 if false 1 if true
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *cur;
	listint_t *fut;

	if (head == NULL)
		return (NULL);

	cur = head;
	fut = cur->next;

	while (cur && fut)
		{
			if (cur == fut)
				return (fut);
			cur = cur->next;
			fut = fut->next;
			if (fut != NULL)
				fut = fut->next;
			}

	return (NULL);
}
