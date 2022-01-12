#include "monty.h"
/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 *
 * @head: double pointer to double linked list
 * @n: data to store
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = NULL;
	stack_t *last = *head;
    
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (last->next)
		{
			last = last->next;
		}
		last->next = new_node;
		new_node->prev = last;
	}
	return (*head);
}