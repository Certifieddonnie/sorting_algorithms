#include "sort.h"

/**
 * forward_swap - Function to swap the values and sort them for
 * the forward pass.
 * @list: head of the linked list.
 * @end: pointer to the tail of the list
 * @start: pointer to iterate back and forth the list.
 * Return: nothing
 */
void forward_swap(listint_t **list, listint_t **end, listint_t **start)
{
	listint_t *temp;

	temp = (*start)->next;
	if ((*start)->prev != NULL)
		(*start)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*start)->prev;
	(*start)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *start;
	else
		*end = *start;
	(*start)->prev = temp;
	temp->next = *start;
	*start = temp;
}

/**
 * backward_swap - Function to swap values and sort them for the
 * backward pass.
 * @list: head to the linked list.
 * @end: pointer to the tail of the list.
 * @start: pointer to iterate back and forth the list.
 * Return: nothing
 */
void backward_swap(listint_t **list, listint_t **end, listint_t **start)
{
	listint_t *temp;

	temp = (*start)->prev;
	if ((*start)->next != NULL)
		(*start)->next->prev = temp;
	else
		*end = temp;
	temp->next = (*start)->next;
	(*start)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *start;
	else
		*list = *start;
	(*start)->next = temp;
	temp->prev = *start;
	*start = temp;
}

/**
 * cocktail_sort_list - Function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort
 * algorithm.
 * @list: list of integers.
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int sort = 1;

	if (!*list || !list || !(*list)->next)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (sort == 1)
	{
		sort = 0;
		start = *list;

		while (start != end)
		{
			if (start->n > start->next->n)
			{
				forward_swap(list, &end, &start);
				print_list((const listint_t *)*list);
				sort = 1;
			}
			start = start->next;
		}

		start = start->prev;
		while (start != *list)
		{
			if (start->n < start->prev->n)
			{
				backward_swap(list, &end, &start);
				print_list((const listint_t *)*list);
				sort = 1;
			}
			start = start->prev;
		}
	}
}
