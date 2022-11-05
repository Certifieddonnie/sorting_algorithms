#include "sort.h"

/**
 * swap - compares 2 numbers
 * and interchanges them if the first is larger
 * @a: the numbers to be compared
 * @b: the numbers to be compared
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm.
 * @array: set of integers
 * @size: size of array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	if (array == NULL || size < 2)
		return;

	/*Loop responsible for checking the array again*/
	for (i = 0; i < size - 1; i++)
	{
		/*Loop to check and swap the numbers*/
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*function to swap the return and return either 1 or 0*/
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
