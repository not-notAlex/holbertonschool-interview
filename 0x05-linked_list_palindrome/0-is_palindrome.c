#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - determines if list is palindrome
 * @head: head of the list
 *
 * Return: 0 if false 1 if true
 */
int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head, *back = *head;
	int len = 0, i = 0, x, end = 0;

	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 2)
		return (1);
	while (i < (len / 2))
	{
		tmp = *head;
		back = *head;
		for (x = 0; x < len - end - 1; x++)
			tmp = tmp->next;
		for (x = 0; x < end; x++)
			back = back->next;
		if (tmp->n != back->n)
			return (0);
		end++;
		i++;
	}
	return (1);
}
