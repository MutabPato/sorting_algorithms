#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point;
	/* checks if a list or its first two elements exist */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;/* Initialize a pointer to traverse the list */
	/* Iterate through the list starting from the second element */
	while (current != NULL)
	{
		insertion_point = current->prev; /* Identify the insertion point */
		/* Compare and swap elements until the correct position is found */
		while (insertion_point != NULL &&  insertion_point->n > current->n)
		{
			if (insertion_point->prev != NULL)
				insertion_point->prev->next = current;
			else
				*list = current;
			current->prev = insertion_point->prev;
			insertion_point->prev = current;
			insertion_point->next = current->next;

			if (current->next != NULL)
				current->next->prev = insertion_point;
			current->next = insertion_point;

			print_list(*list); /* print list after each swap */
			insertion_point = current->prev;
		}
		current = current->next /* Move to the next element in the list */;
	}
}
