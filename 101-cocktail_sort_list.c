#include "sort.h"

/**
 * swap - swaps two nodes
 *
 * @a: first node
 * @b: second node
 */

void swap(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL)
		return;

	if (a->prev != NULL)
		a->prev->next = b;

	else
		*list = b;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *end;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	end = NULL;

	do {
		swapped = 0;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		current = end;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current, current->prev);
				print_list(*list);
				swapped = 1;
			}
			current = current->prev;
		}
	} while (swapped);
}
