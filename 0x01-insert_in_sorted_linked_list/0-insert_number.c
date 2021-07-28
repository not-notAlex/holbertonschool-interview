#include "lists.h"
#include <stdlib.h>

/**
 * name - insert_node
 * @head: head of list 
 * @number: value of new node
 * Return: pointer to new node
 */
listint_t *insert_node(listint_t **head, int number)
{
  listint_t *node, *temp;
  
    if (head == NULL)
    {
        return (NULL);
    }

    node = malloc(sizeof(listint_t));
    if (node == NULL)
    {
        return NULL;
    }
    node->n = number;

    if (*head == NULL)
    {
        *head = node;
	node->next = NULL;
        return node;
    }

    if ((*head)->n > number)
    {
        node->next = *head;
	*head = node;
	return node;
    }

    temp = *head;
    while (temp->next->n < number)
    {
        temp = temp->next;
	if (temp->next == NULL)
	{
	    temp->next = node;
	    node->next = NULL;
	    return node;
	}    
    }
    node->next = temp->next;
    temp->next = node;
    return (node);
}
