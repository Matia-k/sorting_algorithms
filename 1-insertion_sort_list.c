#include "sort.h"

/**
 * insertion_sort_list -  function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *buf;
	int swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (*list)
	{
		buf = *list;
		swap = 0;
		while (buf)
		{
			if (buf->next == NULL)
				return;
			if (buf->next->n < buf->n)
			{
				swap_node(list, buf, buf->next);
				print_list(*list);
				swap = 1;
				break;
			}
			else
				buf = buf->next;
		}
		if (swap == 0)
			return;
	}
}

/**
 * swap_node - swaps two nodes of a doubly linked list.
 * @h: the head of the list.
 * @node1: the first node.
 * @node2: the second node.
 */
void swap_node(listint_t **h, listint_t *node1, listint_t *node2)
{
	listint_t *temp = node1;

	if (node2->next != NULL)
	{
		node1->next = node2->next;
		node2->next->prev = node1;
	}
	else
		node1->next = NULL;
	node2->next = node1;

	if (node1->prev != NULL)
	{
		node2->prev = NULL;
		node2->prev = temp->prev;
		temp->prev->next = node2;
	}
	else
	{
		node2->prev = NULL;
		*h = node2;
	}
	node1->prev = node2;
}
