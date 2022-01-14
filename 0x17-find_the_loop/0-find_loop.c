#include "lists.h"

/**
 * find_listint_loop - checks if a linked list has loop
 * @head: list to check
 *
 * Return: 0 if false 1 if true
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *cur = head;
	listint_t *fut = head;

	if (head == NULL || head->next == NULL)
		return (NULL);


	while (fut->next != NULL && fut->next->next != NULL)
	{
		cur = cur->next;
		fut = fut->next->next;
		if (cur == fut)
		{
			cur = head;
			while (fut != NULL)
			{
				if (cur == fut)
					return (fut);
				fut = fut->next;
				cur = cur->next;
			}
		}
	}

	return (NULL);
}
