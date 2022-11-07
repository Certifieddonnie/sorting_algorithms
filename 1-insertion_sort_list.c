#include "sort.h"

/**
 * insertion_sort_list - Sorts a list of integers
 *
 * @list: The list to be sorted
 *
 * Return: The sorted list
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *current, *past;

	if (!list || !*list)
	{
		return;
	}
	current = *list;		 /*current now points to head of the list*/
	current = current->next; /*moves to 2nd indx of the list*/

	while (current) /*if the is a next*/
	{
		while ((current->prev) && ((current->n) < (current->prev->n)))
		{
			past = current->prev;			  /*declare past to be prev*/
			if (current->next)				  /*check is there is a value after current*/
				(current->next)->prev = past; /*point the prev of the value to "past" */
			if (past->prev)					  /*if past is not the head*/
			{
				past->prev->next = current;
			}
			else
			{
				*list = current;
			}
			past->next = current->next;
			current->prev = past->prev;
			past->prev = current;
			current->next = past;
			print_list(*list);
		}
		current = current->next;
	}
}
