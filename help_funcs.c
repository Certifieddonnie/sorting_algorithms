#include "sort.h"

/*
 * swap - compares 2 numbers
 * and interchanges them if the first is larger
 * @a: the numbers to be compared
 * @b: the numbers to be compared
 * Return: 0 for success and 1 for fail.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
