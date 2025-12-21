#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current;
		temp = current->next;

		while (insert->prev && insert->n < insert->prev->n)
		{
			/* swap insert with insert->prev */
			insert->prev->next = insert->next;
			if (insert->next)
				insert->next->prev = insert->prev;

			insert->next = insert->prev;
			insert->prev = insert->prev->prev;

			insert->next->prev = insert;

			if (insert->prev)
				insert->prev->next = insert;
			else
				*list = insert;

			print_list(*list);
		}

		current = temp;
	}
}
