#include "sort.h"

/**
 * insertion_sort_list - Insertion sort algorithm
 * @list: points to a linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *node;

	if (!list || !*list || !(*list)->next)
		return;
	node = (*list)->next;
	while (node)
	{
		temp = node;
		node = node->next;
		while (temp && temp->prev)
		{
			if (temp->prev->n > temp->n)
			{
				swap(temp->prev, temp);
				if (!temp->prev)
					*list = temp;
				print_list((const listint_t *)*list);
			}
			else
				temp = temp->prev;
		}
	}
}

/**
 * swap - swaps nodes
 * @n1: 1st node
 * @n2: 2nd node
 * Return: void
 */
void swap(listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}
