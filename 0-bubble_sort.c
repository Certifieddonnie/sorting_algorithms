#include "sort.h"

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
