#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm.
 * @array: the array to sort.
 * @size: the size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int f = 0, l = size - 1;

	if (array == NULL || size < 2)
		return;

	sort(array, size, f, l);
}

/**
 * sort - sorts an array of integers recursively using lomuto scheme.
 * @array: array to be sorted.
 * @size: size of the array to be sorted.
 * @f: index of the first element.
 * @l: index of the last element.
 */
void sort(int *array, size_t size, int f, int l)
{
	int sorted;

	if (f < l)
	{
		sorted = lomuto(array, size, f, l);
		sort(array, size, f, sorted - 1);
		sort(array, size, sorted + 1, l);
	}
}

/**
 * lomuto - implements the lomuto partitioning scheme.
 * @array: the array to be partioned.
 * @size: the size of the array.
 * @f: index of the first element of the array.
 * @l: index of the last element of the array.
 *
 * Return: the index at which the next partition will be based.
 */
int lomuto(int *array, size_t size, int f, int l)
{
	int pivot, j, i;

	pivot = array[l];
	j = f;
	i = f - 1;

	while (j < l)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}
		j++;
	}
	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[l]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap - swaps two integers.
 * @a: pointer to the first integer.
 * @b: pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
