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
	listint_t *tmp = *head;
	int len = 0, *lst, i = 0;

	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 2)
		return (1);
	lst = malloc(sizeof(int) * len);
	if (lst == NULL)
		return (0);
	tmp = *head;
	while (tmp)
	{
		*lst = tmp->n;
		tmp = tmp->next;
		lst++;
	}
	lst--;
	tmp = *head;
	while (i < (len / 2))
	{
		if (tmp->n != *lst)
			return (0);
		tmp = tmp->next;
		lst--;
		i++;
	}
	return (1);
}
