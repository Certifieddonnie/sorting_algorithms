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
