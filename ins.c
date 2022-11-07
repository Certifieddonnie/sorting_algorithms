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

	/*check if the list is empty or NULL*/
	if (!list || !*list)
	{
		return;
	}
	current = *list;		 /*current now points to head of the list*/
	current = current->next; /*moves to 2nd indx of the list*/

	while (current) /*if the is a next*/
	{
		/**
		 * if d node before current isn't NULL &
		 * the data in current is less than it's data
		 */
		while ((current->prev) && ((current->n) < (current->prev->n)))
		{
			past = current->prev;			  /*declare past to be prev*/
			if (current->next)				  /*check is there is a value after current*/
				(current->next)->prev = past; /*point the prev of the value to "past" */

			if (past->prev) /*if past is not the head*/
			{
				/*point the next attrib of its prev node to current */
				past->prev->next = current;
			}
			else
			{
				/*current becomes the new head*/
				*list = current;
			}
			/*point the next value of past node to current's next*/
			past->next = current->next;
			/*point current's prev to past's prev*/
			current->prev = past->prev;
			/*past prev now points to current*/
			past->prev = current;
			/*current's next now points to past*/
			current->next = past;
			print_list(*list);
		}
		/*move the pointer `current` to the next node*/
		current = current->next;
	}
}
