#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * usng the selection sort algorithm.
 * @array: list of integers
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < (size - 1); i++)
	{
		min_idx = i;
		for (j = i + i; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}

			if (min_idx != i)
			{
				swap(&array[min_idx], &array[i]);
			}
		}
	}
}
