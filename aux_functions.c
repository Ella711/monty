#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 *
 * @head: double pointer to double linked list
 * @n: data to store
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = *head;
	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (new_node);
}

/**
 * free_stack_t - frees list
 * @head: pointer to head of list
 */
void free_stack_t(stack_t **head)
{
	stack_t *traverse;

	if (*head == NULL)
		return;

	while (*head != NULL)
	{
		traverse = *head;
		(*head) = (*head)->next;
		free(traverse);
	}
}
