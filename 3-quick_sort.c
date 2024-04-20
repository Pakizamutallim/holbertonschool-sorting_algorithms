#include "sort.h"

/**
 * quick_sort -  sorts an array of integers in ascending order using the
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int l_p = 0;

	if (left < right)
	{
		l_p = lomuto_partition(array, left, right, size);
		lomuto_sort(array, left, l_p - 1, size);
		lomuto_sort(array, l_p + 1, right, size);
	}
}


/**
 * lomuto_partition - Order a subset of an array of integers according to
 * @array: The array of integers.
 * @size: The size of the array.
 * @lower: The starting index of the subset to order.
 * @higher: The ending index of the subset to order.
 *
 * Return: 0
 */

int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}
	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
