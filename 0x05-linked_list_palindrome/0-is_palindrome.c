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
	return (is_palindrome_recursive(head, *head));
}

/**
 * is_palindrome_recursive - determines if list is palindrome
 * @left: current left node
 * @right: current right node
 * Return: 0 if false 1 if true
 */
int is_palindrome_recursive(listint_t **left, listint_t *right)
{
	int result1, result2;

	if (right == NULL)
		return (1);
	result1 = is_palindrome_recursive(left, right->next);
	if (result1 == 0)
		return (0);
	if (right->n == (*left)->n)
		result2 = 1;
	else
		result2 = 0;
	*left = (*left)->next;
	return (result2);
}
