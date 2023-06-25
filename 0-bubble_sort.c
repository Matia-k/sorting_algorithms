#include "sort.h"
#include <stdbool.h>
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 * @array: the array of integers to be sorted.
 * @size: the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	bool swapped;

	if (array == NULL || size < 2)
		return;
	while (j < size - 1)
	{
		swapped = false;
		for (i = 0; i < (size - j - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			return;
		j++;
	}
}

/**
 * swap - swaps two integers.
 * @a: the first integer.
 * @b: the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
