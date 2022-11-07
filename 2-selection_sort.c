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
 * selection_sort - sorts an array of integers in ascending order
 * usng the selection sort algorithm.
 * @array: list of integers
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_val;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min_val)
				min_val = array + j;
			else
				min_val = min_val;
		}

		if ((array + i) != min_val)
		{
			swap(array + i, min_val);
			print_array(array, size);
		}
	}
}
