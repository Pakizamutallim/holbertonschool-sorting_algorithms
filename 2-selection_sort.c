#include "sort.h"

/**
 * selection_sort - sorting algorithm
 * @array: list
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min, swap;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		swap = array[i];
		array[i] = array[min];
		array[min] = swap;
		if (min != i)
			print_array(array, size);
	}
}
