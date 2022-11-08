#include "sort.h"

/**
 * partition - partitions an array
 * @arr: array
 * @left: leftmost index
 * @right: rightmost index
 * @size: full array size
 * Return: pivot index
 */
int partition(int *arr, int left, int right, size_t size)
{
	int i, i2, pivot, tmp;

	pivot = arr[right];
	i = left;

	for (i2 = left; i2 < right; i2++)
	{
		if (arr[i2] < pivot)
		{
			if (i != i2)
			{
				tmp = arr[i2];
				arr[i2] = arr[i];
				arr[i] = tmp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[right])
	{
		tmp = arr[i];
		arr[i] = arr[right];
		arr[right] = tmp;
		print_array(arr, size);
	}

	return (i);
}

/**
 * sorter - recursive sorting algorithm
 * @arr: array
 * @left: leftmost index
 * @right: rightmost index
 * @size: full size of array
 */
void sorter(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right, size);
		sorter(arr, left, pivot - 1, size);
		sorter(arr, pivot + 1, right, size);
	}
}

/**
 * quick_sort - quicksort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sorter(array, 0, size - 1, size);
}
