#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *newNode;
	listint_t *tmp = *head;

	newNode = malloc(sizeof(listint_t));
	if (!newNode || !head)
		return (NULL);
	neNode->n = n;
	newNode->next = NULL;
	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}
	i = 0;
	while (tmp && i < idx)
	{
		if (i == idx - 1)
		{
			newNode->next = tmp->next;
			temp->next = newNode;
			return (newNode);
		}
		else
			tmp = tmp->next;
	}
	return (NULL);
}
